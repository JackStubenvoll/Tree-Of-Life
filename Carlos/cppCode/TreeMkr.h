//#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Tree{
    struct Node{
        bool is_leaf;
        int elements;
        vector<Node*> child;
        Node(bool is_leaf, int order): is_leaf(is_leaf){
          child.reserve(order +1);
        }
        Node(const Node& other):is_leaf(other.is_leaf),elements(other.elements){}
        int order;
        Node* parent;
    };
  public:
    Tree();
    Tree(int order, ifstream inputfile);
    Tree(const Tree& other);
    ~Tree();
    const Tree& operator=(const Tree& rhs);
  private:
    void clear();
    Node* copy(const Node* subroot);
    string temp;
    string storage[1593758];
};