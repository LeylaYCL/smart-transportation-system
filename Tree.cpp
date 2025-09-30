#include "Tree.h"
#include <iostream>

Tree::Tree() {
    root = nullptr;
}

void Tree::insert(TreeNode*& node, Durak d) {
    if (!node) {
        node = new TreeNode(d);
    } else if (d.id < node->durak.id) {
        insert(node->left, d);//durak sıralamaları için
    } else {
        insert(node->right, d);
    }
}

void Tree::ekle(Durak d) {
    insert(root, d);
}

void Tree::inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->durak.id << " - " << node->durak.ad << "\n";
    inorder(node->right);
}

void Tree::listele() {
    inorder(root);
}

TreeNode* Tree::search(TreeNode* node, int id) {
    if (!node) return nullptr;
    if (id == node->durak.id) return node;
    if (id < node->durak.id) return search(node->left, id);
    return search(node->right, id);
}

Durak* Tree::ara(int id) {
    TreeNode* sonuc = search(root, id);
    if (sonuc) return &sonuc->durak;
    return nullptr;
}