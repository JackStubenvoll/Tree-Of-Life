#include "Distance.h"
using namespace std;
 
struct Node {
    struct Node* left, *right;
    int keyNodes;
};
 
int distanceRoot(struct Node* root, int r) {
    int distance;

    if (root->keyNodes == r) {
        return 0;
    } 
    
    else if (root->keyNodes > r) {
        distance = 1 + distanceRoot(root->left, r);
        return distance;
    } 
    
    else {
        distance = 1 + distanceRoot(root->right, r);
        return distance;
    }
}
 
int distanceBetween(struct Node* root, int a, int b) {
    int distance;

    if (!root) {
        return 0;
    }

    if (root->keyNodes > a && root->keyNodes > b) {
        distance = distanceBetween(root->left, a, b);
        return distance; 
    }
 
    
    if (root->keyNodes >= a && root->keyNodes <= b) {
        distance = distanceRoot(root, a) + distanceRoot(root, b);
        return distance;
    }
}
 
int findShortestDist(Node *root, int a, int b) {
    int distance;

    if (a > b) {
       swap(a,b);
    }

    distance = distanceBetween(root, a, b);  
    
    return distance;
}

