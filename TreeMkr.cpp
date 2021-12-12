#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;
Tree::Tree(){
    ifstream inputfile;
    string textfile = "AnimalKingdom.txt";
    inputfile.open(textfile);
    while(getline(inputfile, temp)){
        for(int i = 0; i < SIZE; i++){
            storage[i] = temp;
        }
        int tmp = 0;
        cout<< "got line " << temp << " " << endl;
        tmp++;
    }
    //read array into tree structure
    root = new Node(0);
    Node* currKingdom;
    Node* currPhylum;
    Node* currClass;
    Node* currOrder;
    Node* currFamily;
    Node* currGenus;
    for (unsigned i = 0; i < SIZE; i++) {
        std::string line = storage[i];
        size_t startInd = line.find("[");
        size_t endInd = line.find("]");
        std::string level = line.substr(startInd, endInd - startInd);
        if (level == "kingdom") {
            //only kingdom is the first line
            currKingdom = root;
            break;
        } else if (level == "phylum") {
            //Create node representing phylum
            //add phylum to list of children of most recent kingdom
            //set that as parent
            //set this phylum as most recent
            Node* newPhylum(i);
            currKingdom->child.push_back(newPhylum);
            newPhylum->parent = currKingdom
            currPhylum = newPhylum;
        } else if (level == "class") {
            //create node representing class
            //add class to lst of children of most recent phylum
            //set that as parent
            //set this class as most recent
            Node* newClass(i);
            currPhylum->child.push_back(newClass);
            newClass->parent = currPhylum;
            currClass = newClass;
        } else if (level == "order") {
            //create node representing order
            //add order to lst of children of most recent class
            //set that as parent
            //set this order as most recent
            Node* newOrder(i);
            currClass->child.push_back(newOrder);
            newOrder->parent = currClass;
            currOrder = newOrder;
        } else if (level == "family") {
            //create node representing family
            //add family to lst of children of most recent order
            //set that as parent
            //set this family as most recent
            Node* newFamily(i);
            currOrder->child.push_back(newFamily);
            newFamily->parent = currOrder;
            currFamily = newFamily;
        } else if (level == "genus") {
            //create node representing genus
            //add genus to lst of children of most recent family
            //set that as parent
            //set this genus as most recent
            Node* newGenus(i);
            currFamily->child.push_back(newGenus);
            newGenus->parent = currFamily;
            currGenus = newGenus;
            break;
        } else if (level == "species") {
            //create node representing species
            //add species to lst of children of most recent genus
            //set that as parent
            //nothing below species
            Node* newSpecies(i);
            currGenus->child.push_back(newSpecies);
            newSpecies->parent = currGenus;
        }
        
    }
}

string Tree::mostConnected(Node* root) {
    int largest = root->child.size();
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

    }
    return storage[mostConnectedNode->elements];
} 

Node* Tree::findNode(string name) {
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        if (storage[temp->element].find(name) != string::npos) {
            return temp;
        }
        for (unsigned i = 0; i < temp->child.size(); i++) {
            q.push(temp->child.at(i));
        }

    }
    Node* notFound(SIZE + 1);
    return notFound;
}