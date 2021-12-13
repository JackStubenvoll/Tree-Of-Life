#pragma once

#include <vector>
#include <algorithm>
#include <string>

#include "TreeMkr.h"

class Distance {
    public:

    int distanceRoot(struct Node* root, int r);

    int distanceBetween(struct Node* root, int a, int b);

    int findShortestDist(Node *root, int a, int b);

}