#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
//durakları id ye göre saklamak içn kullandım
class Tree {
private:
    TreeNode* root;// burası ağacın kök düğümü

    void insert(TreeNode*& node, Durak d);//durağı ağaca ekler
    void inorder(TreeNode* node);
    TreeNode* search(TreeNode* node, int id);

public:
    Tree();
    void ekle(Durak d);
    void listele(); 
    Durak* ara(int id);
};

#endif