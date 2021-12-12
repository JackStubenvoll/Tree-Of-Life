#include "TreeMkr.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
<<<<<<< HEAD
Tree::Tree(int order, ifstream inputfile){
    inputfile.open("AnimalKingdom.txt");
    //convert text fle to an array of strings, each line is one entry
=======
Tree::Tree(int order){
    ifstream inputfile;
    string textfile = "AnimalKingdom.txt";
    inputfile.open(textfile);
>>>>>>> 7c8627ce74f04dabd1862c947f532ebb49a02868
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
    Node* currKingdom;
    Node* currPhylum;
    Node* currClass;
    Node* currOrder;
    Node* currFamily;
    Node* currGenus;
    for (unsigned i = 0; i < 1593758; i++) {
        std::string line = storage[i];
        size_t startInd = line.find("[");
        size_t endInd = line.find("]");
        std::string level = line.substr(startInd, endInd - startInd);
        switch (level):
            case "kingdom":
                //only kingdom is the first line
                currKingdom = root;
                break;
            case "phylum":
                //Create node representing phylum
                //add phylum to list of children of most recent kingdom
                //set this phylum as most recent
                Node* newPhylum(i);
                currKingdom->child.push_back(newPhylum);
                currPhylum = newPhylum;
                break;
            case "class":
                //create node representing class
                //add class to lst of children of most recent phylum
                //set this class as most recent
                Node* newClass(i);
                currPhylum->child.push_back(newClass);
                currClass = newClass;
                break;
            case "order":
                //create node representing order
                //add order to lst of children of most recent class
                //set this order as most recent
                Node* newOrder(i);
                currClass->child.push_back(newOrder);
                currOrder = newOrder;
                break;
            case "family":
                //create node representing family
                //add family to lst of children of most recent order
                //set this family as most recent
                Node* newFamily(i);
                currOrder->child.push_back(newFamily);
                currFamily = newFamily;
                break;
            case "genus":
                //create node representing genus
                //add genus to lst of children of most recent family
                //set this genus as most recent
                Node* newGenus(i);
                currFamily->child.push_back(newGenus);
                currGenus = newGenus;
                break;
            case "species":
                //create node representing species
                //add species to lst of children of most recent genus
                //nothing below species
                Node* newSpecies(i);
                currGenus->child.push_back(newSpecies);
                break;
        
    }
}