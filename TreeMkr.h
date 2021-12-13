#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Tree{
    struct Node{
        int elements;
        vector<Node*> child;
        //default constructor
        Node();
        Node(int elem){
          elements = elem;
        }
        Node(const Node& other):elements(other.elements){}
        Node* parent;
    };
  public:
    Tree();
    Tree(const Tree& other);
    ~Tree();
    const Tree& operator=(const Tree& rhs);
    string mostConnected(Node* root);
    Node* findNode(string name);
    int findDistance(string name1, string name2);
    Node* lowestCommonAncestor(string name1, string name2);
    //const int SIZE = 1593758;
  private:
    Node* root;
    void clear();
    Node* copy(const Node* subroot);
    string temp;
    string storage[1593758];
    
};