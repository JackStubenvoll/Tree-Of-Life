#pragma once

#include <vector>
#include <iostream>
#include <string>
#include <sstream>


template <class K, class V>
class BTree
{
private:

    struct DataPair {
        K key;
        V value;


        DataPair(K key, V value) : key(key), value(value)
        {
        }
    };


    struct BTreeNode {
        bool is_leaf;
        std::vector<DataPair> elements;
        std::vector<BTreeNode*> children;


        BTreeNode(bool is_leaf, unsigned int order) : is_leaf(is_leaf)
        {
            elements.reserve(order + 1);
            children.reserve(order + 2);
        }


        BTreeNode(const BTreeNode& other)
            : is_leaf(other.is_leaf), elements(other.elements)
        {
        }
    };

   
    BTreeNode* root;

public:


    V findNode(const K& key) const;
    V findParent(const K& key) const;

private:
    V find(const BTreeNode* subroot, const K& key) const;

};

