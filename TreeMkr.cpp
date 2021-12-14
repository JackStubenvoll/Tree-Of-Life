#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
Tree::Tree(){
    ifstream inputfile;
    inputfile.open("TreeSlim/AnimalKingdom.txt");
    string line;
    int counter = 0;
    while(getline(inputfile, line)){
        storage[counter] = line;
        counter++;
 
   }
   size = counter;
   inputfile.close();
    //read array into tree structure by keeping track of most recent level
    root = new Node(0);
    Node* currKingdom = NULL;
    Node* currPhylum = NULL;
    Node* currClass = NULL;
    Node* currOrder = NULL;
    Node* currFamily = NULL;
    Node* currGenus = NULL;
    for (unsigned i = 0; i < (unsigned int) size; i++) {
        std::string thisLine = storage[i];
        size_t startInd = thisLine.find("[");
        size_t endInd = thisLine.find("]");
        std::string level = thisLine.substr(startInd + 1, endInd - startInd - 1);
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

Tree::~Tree() {
    clear(root);
}

void Tree::clear(Tree::Node* subroot) {
    if (subroot == NULL) {
        return;
    }
    for (unsigned i = 0; i < subroot->child.size(); i++) {
        clear(subroot->child[i]);
    }

    delete subroot;
}
/**
 * searches entire tree for which node has the most connections
 * utilizes Brandes' algorithm by assigning a connection score to each node.
 *      Since all edges are the same weight, we can simply count the edges
 *      and assign that as a score.
 * then compares score of latest node in BFS to the current node with the most connections
 * if it has more, then it is saved as the largest node
 * if not, the BFS moves on until it finishes iterating through the entire tree
 */
string Tree::mostConnected(Tree::Node* subroot) {
    unsigned int largest = subroot->child.size();
    Node* mostConnectedNode = subroot;
    std::queue<Node*> q;
    q.push(subroot);
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
    //returns the corresponding string of the most connected node
    return storage[mostConnectedNode->elements];
}
/**
 * allows user to search for a node in the tree as opposed to having to pass
 * a node 
 */
string Tree::mostConnected(string query) {
    Node* node = findNode(query);
    if (node == NULL) {
        return "query not found";
    }
    return mostConnected(node);
}

/**
 * find function that returns the string of what is being searched for
 *      used by main, since returning a node isn't useful.
 * calls main find function that actually finds the node and returns it
 * then returns the corrresponding string
 */ 
string Tree::find(string name) {
    Node* node = findNode(name);
    if (node == NULL) {
        return "Query not found";
    }
    return storage[node->elements];
}

/**
 * findNode returns a node based on as string query.
 * 
 * not useful for a user, but very useful to return a node for other functions
 * performs a BFS and determines if the current node in the BFS contains the
 * query string. 
 * 
 * Will always return the first node it encounters that contains the query string
 * 
 * Since many taxons have similar names, the original text file also contains
 * the names of the discovers (eg Acanthocephala Rudolphi, where Acanthocephala
 * is the name of the phylum, and Rudolphi the name of the person who formally
 * classified it). This can be used to ensure the query finds the correct node.
 * 
 * If a node is not found, returns NULL
 */ 
Tree::Node* Tree::findNode(string name) {
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        if (storage[temp->elements].find(name) != string::npos) {
            return temp;
        }
        for (unsigned i = 0; i < temp->child.size(); i++) {
            q.push(temp->child[i]);
        }
        q.pop();

    }
    return NULL;
}
/**
 * finds the distance between two nodes (number of edges)
 * 
 * first uses the find function to locate both nodes.
 * 
 * Utilizes Djikstra's algorithm on the graph based on the
 * starting node, and slowly expanding outward until it finds its target,
 * keeping track of all nodes already visited. Because all edges are 
 * equally weighted, the distance score from one node to the next is always one.
 * 
 * Once target node is found, returns the corresponding distance from the
 * start node.
 */ 
int Tree::findDistance(string name1, string name2) {
    Node* node1 = findNode(name1);
    Node* node2 = findNode(name2);
    if (node1 == NULL || node2 == NULL) {
        return -1;
    }
    std::queue<Node*> nodeq; //queue that holds nodes
    std::queue<int> distq; //queue that holds the distance of the node at the same spot in nodeq
    std::vector<Node*> visitedNodes; // vector that holds all nodes visited so far
    nodeq.push(node1); //pushes start node
    distq.push(0); //pushes distance from start node to start node (always 0)
    while(!nodeq.empty()) {
        Node* curr = nodeq.front(); 
        int currDist = distq.front();
        string currData = storage[curr->elements];
        bool visited = false; //tests if the current node has already been visited
        for (unsigned i = 0; i < visitedNodes.size(); i++) {
            string visitData = storage[visitedNodes[i]->elements];
            if (currData == visitData) {
                visited = true;
                break;
            }
        }
        if (!visited) { //if the node has already been visted, it is immediately popped
            //if node has not been visited, first test if this is the target node 
            if (storage[curr->elements] == storage[node2->elements]) {
                return currDist;
            }
            //if not the target node, add all of this node's children and it's parent
            //to the queue.
            visitedNodes.push_back(curr);
            if (curr != root) { 
                //if the current node is the root then it doesn't have a parent to add
                nodeq.push(curr->parent);
                distq.push(currDist + 1);
            }    
            for (unsigned i = 0; i < curr->child.size(); i++) {
                nodeq.push(curr->child[i]);
                //Node* test = nodeq.back();
                distq.push(currDist+1);
            }
            
        }
        nodeq.pop();
        distq.pop();

    }
    //if no path is found, return negative one.
    return -1;
}
/**
 * finds the lowest common ancestor of two nodes
 * 
 * by lowest common ancestor, we mean the lowest common ancestor node
 * NOT the latest common ancestor of two species.
 * 
 * adds all of the first node's ancestors to a vector minus the root
 * then goes through all of the second node's ancestors and compares
 * them to each entry in the vector.
 * 
 * If no matches, then return the root as by definition it will be
 * the lowestCommonAncestor since both entries must be in Animalia. 
 */
string Tree::lowestCommonAncestor(string name1, string name2) {
    
    Node* node1 = findNode(name1);
    Node* node2 = findNode(name2);
    if (node1 == NULL || node2 == NULL) {
        return "one of these queries does not exist";
    }
    if (name1 == name2) {
        return storage[node1->elements];
    }
    std::vector<Node*> node1Ancestors;
    Node* curr = node1;
    while (curr != root) {
        node1Ancestors.push_back(curr);
        curr = curr->parent;
    }
    curr = node2;
    while (curr != root) {
        curr = curr->parent;
        for (unsigned i = 0; i < node1Ancestors.size(); i++) {
            if (node1Ancestors[i] == curr) {
                return storage[curr->elements];
            }
        }
    }
    return storage[root->elements];
}


