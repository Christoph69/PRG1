// tree.cpp
#include "../inc/tree.h"

bool insertNode(Knoten **wurzel, int data) {
  if ((*wurzel) == nullptr) {
    Knoten *node = new Knoten;

    if (node) {
      node->data  = data;
      node->left  = nullptr;
      node->right = nullptr;
      *wurzel     = node;
    }
    else return false;
  }
  else if (data < (*wurzel)->data) insertNode(&(*wurzel)->left, data);
  else if (data > (*wurzel)->data) insertNode(&(*wurzel)->right, data);
  return true;
}

void outputTree(Knoten **wurzel) {
  if (*wurzel != nullptr) {
    outputTree(&(*wurzel)->left);
    std::printf("%d\n", (*wurzel)->data);
    outputTree(&(*wurzel)->right);
  }
}
