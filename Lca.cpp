#include "Lca.h"


TreeNode* lca(TreeNode* root, int n, int m){
    if (root==NULL) {
        return NULL;
    }
    if (root->val == n || root->val == m) {
        return root;
    }

    TreeNode* lca1 = lca(root->left, n, m);
    TreeNode* lca2 = lca(root->right, n, m);
    
    if (lca1 != NULL && lca2 != NULL) {
        return root;
    } 
    
    if (lca1 != NULL) {
        return lca1;
    }

    if (lca2 != NULL) {
        return lca2;
    }
}
 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {    
    TreeNode* lca_;
    lca_ = LCA(root, p->val, q->val)
    return lca_;
}
