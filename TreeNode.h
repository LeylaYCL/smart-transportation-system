#ifndef TREENODE_H
#define TREENODE_H

#include "Durak.h"

class TreeNode {
public:
    Durak durak;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Durak d);
};

#endif