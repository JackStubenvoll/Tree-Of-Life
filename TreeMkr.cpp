#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
// int main {
//     Tree::Tree* test;
//     test = new Tree();
//     std::cout << "cock and ball torture" << std::endl;
//     std::cout << test->find("Animalia") << std::endl;
//     return 0;
// };
Tree::Tree(){
    ifstream inputfile;
    std::cout << "Point 1" << std::endl;
    //string textfile = "AnimalKingdom.txt";
    inputfile.open("Carlos/AnimalKingdom.txt");
    string line;
    int counter = 0;
    while(getline(inputfile, line)){
        //std::cout << "in while loop" << std::endl;
        storage[counter] = line;
        //cout<< "got line " << line << " " << endl;
        counter++;
 
   }
   size = counter;
   inputfile.close();
   std::cout << "Point 2" << std::endl;
    //read array into tree structure
    root = new Node(0);
    Node* currKingdom = NULL;
    Node* currPhylum = NULL;
    Node* currClass = NULL;
    Node* currOrder = NULL;
    Node* currFamily = NULL;
    Node* currGenus = NULL;
    std::cout << "Point 3" << std::endl;
    for (unsigned i = 0; i < (unsigned int) size; i++) {
        //std::cout << "size: " << size << std::endl;
        //std::cout << i << std::endl;
        std::string thisLine = storage[i];
        size_t startInd = thisLine.find("[");
        size_t endInd = thisLine.find("]");
        //std::cout << "startInd: " << startInd << " endInd: " << endInd << std::endl;
        std::string level = thisLine.substr(startInd + 1, endInd - startInd - 1);
        //std::cout << level << std::endl;
        if (level == "kingdom") {
            //only kingdom is the first line
            currKingdom = root;
        } else if (level == "phylum") {
            //Create node representing phylum
            //add phylum to list of children of most recent kingdom
            //set that as parent
            //set this phylum as most recent
            Node* newPhylum = new Node(i);
            
            //std::cout << storage[currKingdom->elements] << " has a new child: " << storage[i] << std::endl;
            currKingdom->child.push_back(newPhylum);
            newPhylum->parent = currKingdom;
            currPhylum = newPhylum;
        } else if (level == "class") {
            //create node representing class
            //add class to lst of children of most recent phylum
            //set that as parent
            //set this class as most recent
            Node* newClass = new Node(i);
            currPhylum->child.push_back(newClass);
            newClass->parent = currPhylum;
            currClass = newClass;
        } else if (level == "order") {
            //create node representing order
            //add order to lst of children of most recent class
            //set that as parent
            //set this order as most recent
            Node* newOrder = new Node(i);
            currClass->child.push_back(newOrder);
            newOrder->parent = currClass;
            currOrder = newOrder;
        } else if (level == "family") {
            //create node representing family
            //add family to lst of children of most recent order
            //set that as parent
            //set this family as most recent
            Node* newFamily = new Node(i);
            currOrder->child.push_back(newFamily);
            newFamily->parent = currOrder;
            currFamily = newFamily;
        } else if (level == "genus") {
            //create node representing genus
            //add genus to lst of children of most recent family
            //set that as parent
            //set this genus as most recent
            Node* newGenus = new Node(i);
            currFamily->child.push_back(newGenus);
            newGenus->parent = currFamily;
            currGenus = newGenus;
        } else if (level == "species") {
            //create node representing species
            //add species to lst of children of most recent genus
            //set that as parent
            //nothing below species
            //std::cout << "~~~~~~~~~~~~~~" << std::endl;
            Node* newSpecies = new Node(i);
            currGenus->child.push_back(newSpecies);
            newSpecies->parent = currGenus;
        }
        
    }
    std::cout << storage[0] << std::endl;
    std::cout << storage[1] << std::endl;
    std::cout << storage[2] << std::endl;
    std::cout << storage[3] << std::endl;
    std::cout << "Point 4" << std::endl;
}

string Tree::mostConnected(Tree::Node* subroot) {
    unsigned int largest = root->child.size();
    Node* mostConnectedNode = root;
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        if (temp->child.size() > largest) {
            largest = temp->child.size();
            mostConnectedNode = temp;
        }
        for (unsigned i = 0; i < temp->child.size(); i++) {
            q.push(temp->child.at(i));
        }
        q.pop();

    }
    return storage[mostConnectedNode->elements];
} 

string Tree::find(string name) {
    std::cout << "calling find" << std:: endl;
    Node* node = findNode(name);
    return storage[node->elements];
}

Tree::Node* Tree::findNode(string name) {
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        // std::cout << "bollocks" << std::endl;
        // std::cout << storage[temp->elements] << std::endl;
        // std::cout << "bollocks 2" << std::endl;
        // std::cout << storage[temp->elements].find(name) << std::endl;
        // std::cout << string::npos << std::endl;
        if (storage[temp->elements].find(name) != string::npos) {
            //std::cout << "returning" << std::endl;
            return temp;
        }
        //std::cout << "size of child array: " << temp->child.size() << std::endl;
        for (unsigned i = 0; i < temp->child.size(); i++) {
            q.push(temp->child[i]);
        }
        q.pop();

    }
    Node* notFound = new Node(-1);
    return notFound;
}

int Tree::findDistance(string name1, string name2) {
    Node* node1 = findNode(name1);
    Node* node2 = findNode(name2);
    std::cout << node1->elements << std::endl;
    std::cout << node2->elements << std::endl;
    std::queue<Node*> nodeq;
    std::queue<int> distq;
    std::vector<Node*> visitedNodes;
    nodeq.push(node1);
    distq.push(0);
    while(!nodeq.empty()) {
        Node* curr = nodeq.front();
        std::cout << curr->elements << std::endl;
        //std::cout << "basoivba" << std::endl;
        int currDist = distq.front();
        std::cout << "after distq" << std::endl;
        string currData = storage[curr->elements];
        std::cout << "after currData" << std::endl;
        bool visited = false;
        for (unsigned i = 0; i < visitedNodes.size(); i++) {
            string visitData = storage[visitedNodes[i]->elements];
            if (currData == visitData) {
                visited = true;
                break;
            }
        }
        if (!visited) {
            if (storage[curr->elements] == storage[node2->elements]) {
                return currDist;
            }

            visitedNodes.push_back(curr);
                
            nodeq.push(curr->parent);
            distq.push(currDist + 1);
            for (unsigned i = 0; i < curr->child.size(); i++) {
                nodeq.push(curr->child[i]);
                std::cout << storage[curr->child[i]->elements] << std::endl;
                distq.push(currDist+1);
            }
            
        }
        nodeq.pop();
        distq.pop();
        std::cout << "popped" << std::endl;

    }
    return -1;
}

Tree::Node* Tree::lowestCommonAncestor(string name1, string name2) {
    
    Node* node1 = findNode(name1);
    Node* node2 = findNode(name2);
    if (name1 == name2) {
        return node1;
    }
    std::vector<Node*> node1Ancestors;
    Node* curr = node1;
    while (curr != root) {
        curr = curr->parent;
        node1Ancestors.push_back(curr);
    }
    curr = node2;
    while (curr != root) {
        curr = curr->parent;
        for (unsigned i = 0; i < node1Ancestors.size(); i++) {
            if (node1Ancestors[i] == curr) {
                return curr;
            }
        }
    }
    return root;
}
