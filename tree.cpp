////////////////////////////////////////////////////////////////////////////////
//
// Topic    : Tree problems (only Binary Trees and Binary Search Trees)
// Author   : Anh Tuan Do
// Created  : March 8th, 2011
//
////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
using namespace std;

// -----------------------------------------------------------------------------
// Struct represents a node in a tree
// -----------------------------------------------------------------------------
typedef struct Node {
  int id;
  int data;
  Node* leftChild;
  Node* rightChild;
} NODE;

// -----------------------------------------------------------------------------
// Create a node
// -----------------------------------------------------------------------------
NODE* createNode(int id, int value) {
  NODE* newNode = new NODE;
  if (newNode == NULL) {
    cout << "Not enough memory!" << endl;
  }
  newNode->id = id;
  newNode->data = value;
  newNode->leftChild = NULL;
  newNode->rightChild = NULL;
  return newNode;
}

// -----------------------------------------------------------------------------
// Create a binary tree
// -----------------------------------------------------------------------------
NODE* createBinaryTree() {
  NODE* n1 = createNode(1, 10);
  NODE* n2 = createNode(2, 6);
  NODE* n3 = createNode(3, 8);
  n1->leftChild = n2;
  n1->rightChild = n3;

  NODE* n4 = createNode(4, 20);
  NODE* n5 = createNode(5, 25);
  NODE* n6 = createNode(6, 4);
  n2->leftChild = n4;
  n2->rightChild = n5;
  n3->rightChild = n6;

  NODE* n7 = createNode(7, 1);
  NODE* n8 = createNode(8, 100);
  NODE* n9 = createNode(9, 2);
  n5->leftChild = n7;
  n5->rightChild = n8;
  n6->rightChild = n9;

  NODE* n10 = createNode(10, 3);
  NODE* n11 = createNode(11, 7);
  NODE* n12 = createNode(12, 5);
  NODE* n13 = createNode(13, 8);
  n7->leftChild = n10;
  n7->rightChild = n11;
  n8->leftChild = n12;
  n9->leftChild = n13;

  NODE* n14 = createNode(14, 6);
  n11->rightChild = n14;

  return n1;
}

// -----------------------------------------------------------------------------
// Create a binary search tree
// -----------------------------------------------------------------------------
NODE* createBinarySearchTree() {
  NODE* n1 = createNode(1, 50);
  NODE* n2 = createNode(2, 30);
  NODE* n3 = createNode(3, 100);
  n1->leftChild = n2;
  n1->rightChild = n3;

  NODE* n4 = createNode(4, 20);
  NODE* n5 = createNode(5, 35);
  NODE* n6 = createNode(6, 75);
  NODE* n7 = createNode(7, 200);
  n2->leftChild = n4;
  n2->rightChild = n5;
  n3->leftChild = n6;
  n3->rightChild = n7;

  NODE* n8 = createNode(8, 10);
  NODE* n9 = createNode(9, 25);
  NODE* n10 = createNode(10, 33);
  NODE* n11 = createNode(11, 45);
  NODE* n12 = createNode(12, 60);
  NODE* n13 = createNode(13, 150);
  NODE* n14 = createNode(14, 250);
  n4->leftChild = n8;
  n4->rightChild = n9;
  n5->leftChild = n10;
  n5->rightChild = n11;
  n6->leftChild = n12;
  n7->leftChild = n13;
  n7->rightChild = n14;

  NODE* n15 = createNode(15, 5);
  NODE* n16 = createNode(16, 12);
  NODE* n17 = createNode(17, 27);
  NODE* n18 = createNode(18, 125);
  NODE* n19 = createNode(19, 170);
  NODE* n20 = createNode(20, 1000);
  n8->leftChild = n15;
  n8->rightChild = n16;
  n9->rightChild = n17;
  n13->leftChild = n18;
  n13->rightChild = n19;
  n14->rightChild = n20;

  NODE* n21 = createNode(21, 1);
  n15->leftChild = n21;

  return n1;
}

// -----------------------------------------------------------------------------
// Find whether a node exists in a bianry tree
// -----------------------------------------------------------------------------
NODE* findNode(NODE* root, int value) {
  // BASE CASE: The tree is empty!
  if (root == NULL) {
    return NULL;
  }
  // We found the node at the root
  if (root->data == value) {
    return root;
  }
  // Check on the left branch
  NODE* result = findNode(root->leftChild, value);
  if (result != NULL) {
    return result;
  }
  // Check on the right branch
  result = findNode(root->rightChild, value);
  return result;
}

// -----------------------------------------------------------------------------
// Search for a node in a binary search tree
// -----------------------------------------------------------------------------
NODE* findNode2(NODE* root, int value) {
  // We can solve this problem using recursion but while is much better
  while (root != NULL) {
    if (root->data == value) {
      break;
    }
    if (root->data > value) {
      root = root->leftChild;
    }
    else {
      root = root->rightChild;
    }
  }
  return root;
}

// -----------------------------------------------------------------------------
// Preorder traversal (node -> left -> right)
// -----------------------------------------------------------------------------
void preOrderTraversal(NODE* root) {
  if (root == NULL) {
    return;
  }
  cout << root->data << endl;
  preOrderTraversal(root->leftChild);
  preOrderTraversal(root->rightChild);
}

// -----------------------------------------------------------------------------
// Inorder traversal (left -> node -> right)
// -----------------------------------------------------------------------------
void inOrderTraversal(NODE* root) {
  if (root == NULL) {
    return;
  }
  inOrderTraversal(root->leftChild);
  cout << root->data << endl;
  inOrderTraversal(root->rightChild);
}

// -----------------------------------------------------------------------------
// Postorder traversal (left -> right -> node)
// -----------------------------------------------------------------------------
void postOrderTraversal(NODE* root) {
  if (root == NULL) {
    return;
  }
  postOrderTraversal(root->leftChild);
  postOrderTraversal(root->rightChild);
  cout << root->data << endl;
}

// -----------------------------------------------------------------------------
// Find min value in a BST
// -----------------------------------------------------------------------------
void printMinValue(NODE* root) {
  // SPECIAL CASE: the tree is empty
  if (root == NULL) {
    return;
  }
  int min;
  while (root != NULL) {
    min = root->data;
    root = root->leftChild; // MIN
    //root = root->rightChild; // MAX
  }
  cout << min << endl;
}

// -----------------------------------------------------------------------------
// Find the lowest common ancestor of two nodes
// -----------------------------------------------------------------------------
NODE* findLowestCommonAncestor(NODE* root, int value1, int value2) {
  // SPECIAl CASE: the tree is empty!
  if (root == NULL) {
    return NULL;
  }
  // Both values are on the left of the root
  if (root->data > value1 && root->data > value2) {
    return findLowestCommonAncestor(root->leftChild, value1, value2);
  }
  // Both values are on the right of the root
  if (root->data < value1 && root->data < value2) {
    return findLowestCommonAncestor(root->rightChild, value1, value2);
  }
  // Otherwise, this root is the answer!
  return root;

}

// -----------------------------------------------------------------------------
// Find the lagest node that is smaller than n
// -----------------------------------------------------------------------------
int maxNumber = -1;
int findLargest(NODE* root, int value) {
  if (root != NULL) {
    maxNumber = findLargest(root->leftChild, value);
    if (root->data < value) {
      maxNumber = root->data;
    }
    maxNumber = findLargest(root->rightChild, value);
  }
  return maxNumber;
}

// -----------------------------------------------------------------------------
// Insert/delete a node in a binary tree
// Insert/delete a node in a binary search tree
// Implement haep
// Check a tree is a BST or not
// Check a tree in a balance BST
// Check a tree is symmetric
// Implement BFS and DFS
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Main function, nothing much in this one
// -----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  NODE* myTree = createBinarySearchTree();

  // --- findNode --- //
//  NODE* temp = findNode(myTree, 100);
//  if (temp != NULL) {
//    cout << "Node #" << temp->id << ", value = " << temp->data << endl;
//  }

  // --- findNode2 --- //
//  NODE* temp = findNode2(myTree, 171);
//  if (temp != NULL) {
//    cout << "Node #" << temp->id << ", value = " << temp->data << endl;
//  }

  // --- Traversal functions --- //
//  preOrderTraversal(myTree);
//  inOrderTraversal(myTree);
//  postOrderTraversal(myTree);

  // --- Min Max --- //
//  printMinValue(myTree);

  // --- Find lowest common ancestor --///
//  NODE* t = findLowestCommonAncestor(myTree, 1, 1000);
//  if (t != NULL) {
//    cout << "Node #" << t->id << ", value = " << t->data << endl;
//  }

  // --- Find lowest common ancestor --//
//  cout << "Number = " << findLargest(myTree, 152);

  return 0;
}
*/
