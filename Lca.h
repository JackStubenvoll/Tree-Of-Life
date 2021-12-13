#pragma once

#include <vector>
#include "TreeMkr.h"

class Lca {
    TreeNode* lca(TreeNode* root, int n, int m);
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
}