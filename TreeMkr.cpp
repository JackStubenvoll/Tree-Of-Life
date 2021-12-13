#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
int main()
{
}
Tree::Tree(){
    ifstream inputfile;
    //string textfile = "AnimalKingdom.txt";
    inputfile.open("AnimalKingdom.txt");
    while(getline(inputfile, temp)){
        for(int i = 0; i < 1593758; i++){
            storage[i] = temp;
        }
        int tmp = 0;
        cout<< "got line " << temp << " " << endl;
        tmp++;
 
   }
    //read array into tree structure
    root = new Node(0);
    Node* currKingdom = NULL;
    Node* currPhylum = NULL;
    Node* currClass = NULL;
    Node* currOrder = NULL;
    Node* currFamily = NULL;
    Node* currGenus = NULL;
    for (unsigned i = 0; i < 1593758; i++) {
        std::string line = storage[i];
        size_t startInd = line.find("[");
        size_t endInd = line.find("]");
        std::string level = line.substr(startInd, endInd - startInd);
        if (level == "kingdom") {
            //only kingdom is the first line
            currKingdom = root;
        } else if (level == "phylum") {
            //Create node representing phylum
            //add phylum to list of children of most recent kingdom
            //set that as parent
            //set this phylum as most recent
            Node* newPhylum = new Node(i);
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
            break;
        } else if (level == "species") {
            //create node representing species
            //add species to lst of children of most recent genus
            //set that as parent
            //nothing below species
            Node* newSpecies = new Node(i);
            currGenus->child.push_back(newSpecies);
            newSpecies->parent = currGenus;
        }
        
    }
}

string Tree::mostConnected(Node* root) {
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

Tree::Node* Tree::findNode(string name) {
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        if (storage[temp->elements].find(name) != string::npos) {
            return temp;
        }
        for (unsigned i = 0; i < temp->child.size(); i++) {
            q.push(temp->child.at(i));
        }
        q.pop();

    }
    Node* notFound = new Node(1593759);
    return notFound;
}

int Tree::findDistance(string name1, string name2) {
    Node* node1 = findNode(name1);
    Node* node2 = findNode(name2);
    std::queue<Node*> nodeq;
    std::queue<int> distq;
    std::vector<Node*> visitedNodes;
    nodeq.push(node1);
    distq.push(0);
    while(!nodeq.empty()) {
        Node* curr = nodeq.front();
        int currDist = distq.front();
        string currData = storage[curr->elements];
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
                distq.push(currDist+1);
            }
            
        }
        nodeq.pop();
        distq.pop();
        return -1;

    }
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
