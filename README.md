# Taxonomy Tree

Contributors: Connor Schick (cschick3), Carlos Paredes (cfp3), Jack Stubenvoll (jackts2), Jeff Shin (wonjong2)
- - - -
## Table of contents
- [Taxonomy Tree](#taxonomy-tree)
- [Table of contents](#table-of-contents)
- [Overview](#overview)
- [Tree Maker](#tree-maker)
    - [Read File](#read-file)
    - [Find](#find)
    - [Find Most Connected](#find-most-connected)
    - [Find Distance](#find-distance)
    - [Lowest Common Ancestor](#lowest-common-ancestor)
    - [Test Suite](#test-suite)

- - - -
## Overview
The source of the data set is acquired from https://www.catalogueoflife.org/data/download. 
To run the file, we used `make` to compile the code and `./treemaker` to run the main which includes the functions.

#### Manually input the desired data
- Find
    - input string in query to see what you want to look it up
- Most Connected
    - input string (ex. primates) in query to see which node has most connections
- Find Distance
    - input string of both nodes in each query to see the distance between two nodes
- Lowest Common Ancestor
    - input string of both nodes in each query to see the lowest common ancestor

To compile tests, we use `make test` and `./test` to run the tests.

Our presentation slide can be find via Google Slides:https://docs.google.com/presentation/d/1-fXQlNdQwU7Yw4SVIQABn7BgezfMNkAW89GBAotOFCc/edit?usp=sharing

Our presentation video can be find via Youtube: https://youtu.be/KlfxNKt7SA4

- - - -
## Tree Maker
### Files: TreeMkr.h/cpp
This is the file that contains all the functions of the project.  

- - - -
## Read File
### Files: TreeMkr.h/cpp (Line 8 ~ 92)

Read file uses the taxonomy dataset from https://www.catalogueoflife.org/data/download. The duplicates in the .txt file is parsed via going through the .txt and getting rid of spaces and using the upstream library in the TreeSlim file. Inside the tree constructor, getline is used to store each entry in the .txt in an array of strings. This array of strings is then used to create the tree structure. Each entry for the brackets that contain the entry’s level in the taxonomic tree is scanned in the tree constructor and is assigned to its parent. 

Tree Structure contains nodes with values for:
1. Level of Tree (kingdom, phylum, order, etc)
2. Name (Animalia, Homo, Sapiens, etc)
3. writeToFile
4. readFromFile
5. Vector containing a list of all children of the node

- - - -
## Find
### Files: TreeMkr.h/cpp (Line 155 ~ 193)

This find feature consists of two parts, the main find function and the helper function. The goal of the main find function is to return the string of what is being searched for (entered in the parameter of the function). This main function is used by main(), since returning a node isn't useful. This function calls main() to find the function that actually finds the node and returns it. After then, it returns the corresponding string.

Another function of the find feature is called fineNode(). The goal of this helper function is to return a node based on a string query. This helper function performs a BFS and determines if the current node in the BFS contains the query string. It will always return the first node it encounters that contains the query string. Even though this function is not useful for a user, it is very useful to return a node for other functions. 

Since many taxons have similar names, the original text file also contains the names of the discovers (ex. Acanthocephala Rudolphi, where Acanthocephala is the name of the phylum, and Rudolphi the name of the person who formally classified it). This can be used to ensure the query finds the correct node. If a node is not found, it returns NULL 

- - - -
## Find Most Connected
### Files: TreeMkr.h/cpp (Line 117 ~ 147)

The goal of this findMostConnected function is to search the entire tree for which node has the most connections. This function utilizes Brandes' algorithm by assigning a connection score to each node. The edges are counted and assigned that as a score. Furthermore, this function compares the score of the latest node in BFS to the current node with the most connections. If it has more connections, meaning the more score,  then it is saved as the largest node. However, if it does not have more connections, the BFS moves on until it finishes iterating through the entire tree. 

- - - -
## Find Distance 
### Files: TreeMkr.h/cpp (Line 208 ~ 257)

The goal of this findDistance function is to find the distance, number of edges, between two nodes. To begin, the find function is used to locate both nodes. Then, this function utilizes Djikstra's algorithm by setting the initial node and then slowly expanding outward until it finds its target, another node. While doing this, the function keeps track of the distance that the corresponding node in the node queue is from the start of a node in a separate distance queue and also keeps track of all nodes already visited. Once the target node is found, the function returns the corresponding distance from the start node.

- - - -
## Lowest Common Ancestor
### Files: TreeMkr.h/cpp (Line 271 ~ 297)

The goal of lowestCommonAncestor is literally to find the lowest common ancestor #### node of two nodes. It is not the latest common ancestor of two species. This function starts by adding all of the first node's ancestors to a vector minus the root. Then, it goes through all of the second node’s ancestors and compares them to each entry in the vector. If there are no matches, then this function returns the root due to both entries located under Animalia. 

- - - -
## Test Suite
### Files: TestCases.cpp

When building the test suite, we looked at all of our important functions and built the tests off of those. We used catch to test our functions like in the mps. Each algorithm was tested by determining what the output should be and comparing it with what we get from the function; if they are equal, then it shows success. If the test cases failed, then it shows that the algorithm was wrong.

