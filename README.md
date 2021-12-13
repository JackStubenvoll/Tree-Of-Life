# Taxonomy Tree

Contributors: Connor Schick (cschick3), Carlos Paredes (cfp3), Jack Stubenvoll (jackts2), Jeff Shin (wonjong2)
- - - -
## Table of contents
- [Taxonomy Tree](#taxonomy-tree)
- [Table of contents](#table-of-contents)
- [Overview](#overview)
- [Tree Maker](#tree-maker)
    - [Read File](#read-file)
    - [Find Most Connected](#find-most-connected)
    - [Find](#find)
    - [Find Distance](#find-distance)
    - [Lowest Common Ancestor](#lowest-common-ancestor)


- - - -
## Overview
The source of the data set is acquired from https://www.catalogueoflife.org/data/download. 
To run the file, we used make to compile the code and ./treemaker to run main which includes the functions. Make test while compile the tests and ./test will run the tests.

< Full instructions on how to build and run your executable, including how to define the input data and output location for each method. >

- - - -
## Tree Maker
### Files: TreeMkr.h/cpp
This is the file that contains all the functions of the 

- - - -
## Read File
### Files: TreeMkr.h/cpp (Line 8 ~ 92)

<Needs more work to be done>

Tree Structure contains nodes with values for:
1. Level of Tree (kingdom, phylum, order, etc)
2. Name (Animalia, Homo, Sapiens, etc)
3. writeToFile
4. readFromFile
5. Vector containing a list of all children of the node

- - - -
## Find Most Connected
### Files: TreeMkr.h/cpp (Line 102 ~ 121)

The goal of this findMostConnected function is to search the entire tree for which node has the most connections. This function utilizes Brandes' algorithm by assigning a connection score to each node. The edges are counted and assigned that as a score. Furthermore, this function compares the score of the latest node in BFS to the current node with the most connections. If it has more connections, meaning the more score,  then it is saved as the largest node. However, if it does not have more connections, the BFS moves on until it finishes iterating through the entire tree. 


- - - -
## Find
### Files: TreeMkr.h/cpp (Line 129 ~ 165)

This find feature consists of two parts, the main find function and the helper function. The goal of the main find function is to return the string of what is being searched for (entered in the parameter of the function). This main function is used by main(), since returning a node isn't useful. This function calls main() to find function that actually finds the node and returns it. After then, it returns the corrresponding string.

The helper function of the find feature is called fineNode(). The goal of this helper function is to return a node based on a string query. This helper function performs a BFS and determines if the current node in the BFS contains the query string. It will always return the first node it encounters that contains the query string. Even though this function is not useful for a user, it is very useful to return a node for other functions. 

Since many taxons have similar names, the original text file also contains the names of the discovers (ex. Acanthocephala Rudolphi, where Acanthocephala is the name of the phylum, and Rudolphi the name of the person who formally classified it). This can be used to ensure the query finds the correct node. If a node is not found, it returns NULL 

- - - -
## Find Distance 
### Files: TreeMkr.h/cpp (Line 183 ~ 229)

The goal of this findDistance function is to find the distance, number of edges, between two nodes. To begin, the find function is used to locate both nodes. Then, this function utilizes Djikstra's algorithm by setting the initial node and then slowly expanding outward until it finds its target, another node. While doing this, the function keeps track of the distance that the corresponding node in the node queue is from the start of a node in a separate distance queue and also keeps track of all nodes already visited. Once the target node is found, the function returns the corresponding distance from the start node.

- - - -
## Lowest Common Ancestor
### Files: TreeMkr.h/cpp (Line 243 ~ 266)

The goal of lowestCommonAncestor is literally to find the lowest common ancestor #### node of two nodes. It is not the latest common ancestor of two species. This function starts by adding all of the first node's ancestors to a vector minus the root. Then, it goes through all of the second node’s ancestors and compares them to each entry in the vector. If there are no matches, then this function returns the root due to both entries located under Animalia. 
