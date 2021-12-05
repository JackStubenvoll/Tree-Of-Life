#include "find.h"
template <class K, class V>
V BTree<K, V>::findNode(const K& key) const
{
    return root == nullptr ? V() : find(root, key);
}


template <class K, class V>
V BTree<K, V>::find(const BTreeNode* subroot, const K& key) const
{
   

    size_t first_larger_idx = insertion_idx(subroot->elements, key);

    if (first_larger_idx < subroot->elements.size())
    {
        if (subroot->elements[first_larger_idx] == key)
            return subroot->elements[first_larger_idx].value;
    }
    if (subroot->is_leaf)
        return V();
    else
        return find(subroot->children[first_larger_idx], key);
}
