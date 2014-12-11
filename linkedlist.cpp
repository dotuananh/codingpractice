////////////////////////////////////////////////////////////////////////////////
//
// Topic    : Linked List interview problems
// Author   : Anh Tuan Do
// Started  : March 7th, 2011
// Compile  : cl /EHsc linkedlist.cpp
// Run      : myprog.exe
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
using namespace std;

// -----------------------------------------------------------------------------
// Declare a NODE structure
// -----------------------------------------------------------------------------
typedef struct Node {
  Node* next;
  int data;
} NODE;

// -----------------------------------------------------------------------------
// Create a new node
// NOTE: Remember to check for memory allocation when creating a new node
// -----------------------------------------------------------------------------
NODE* createNewNode(int value) {
  NODE* newNode = new NODE;
  // ERROR: Not enough memory!
  if (newNode == NULL) {
    cout << "Cannot allocate memory for the new node!" << endl;
  }
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

// -----------------------------------------------------------------------------
// Add a new node to the begining of the list
// NOTE: When pass the head pointer, we should let it be NODE** not NODE*
// -----------------------------------------------------------------------------
void addBeginningNode(NODE** head, int value) {
  NODE* newNode = createNewNode(value);
  newNode->next = *head;
  *head = newNode;
}

// -----------------------------------------------------------------------------
// Add a new node at the end of the list
// NOTE: Remember the special cases (the list is empty or has only one node)
// -----------------------------------------------------------------------------
void addEndNode(NODE** head, int value) {
  NODE* newNode = createNewNode(value);

  // SPECIAL CASE: The list is empty.
  if (*head == NULL) {
    *head = newNode;
  }
  // NORMAL CASE
  else {
    // In this normal case, we'll traverse till the end of the list
    // and then add the new node there. The head pointer is still the same
    // because we only change the tail of the list.
    NODE* currentNode = *head;
    /*DEBUG*/cout << "Bookmark #1" << endl;
    /*DEBUG*/if (currentNode != NULL) { cout << "currentNode value = " << currentNode->data << endl;}
    // Go until we reach the end of the list
    while (currentNode->next != NULL) {
      /*DEBUG*/cout << "Bookmark #2" << endl;
      currentNode = currentNode->next;
    }
    /*DEBUG*/cout << "Bookmark #3" << endl;
    // Add the new node to the end of the list
    currentNode->next = newNode;
  }
}

// -----------------------------------------------------------------------------
// Check whether a node exists in the list
// -----------------------------------------------------------------------------
NODE* checkElementExists(NODE* head, int value) {
  // SPECIAL CASE: The list is empty, no need to check further
  NODE* currentNode = head;
  while (currentNode != NULL && currentNode->data != value) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

// -----------------------------------------------------------------------------
// Print the list
// -----------------------------------------------------------------------------
void printList(NODE* head) {
  cout << "The list: ";
  NODE* currentNode = head;
  while (currentNode != NULL) {
    cout << currentNode->data << " --> ";
    // We have reached the end of the list
    if (currentNode->next == NULL) {
      cout << "NULL";
      break;
    }
    // Move to the next node in the list;
    else {
      currentNode = currentNode->next;
    }
  }
  cout << endl;
}

// -----------------------------------------------------------------------------
// Delete an element in the list
// -----------------------------------------------------------------------------
void deleteNode(NODE** head, int value) {
  // We only delete the first node that contains this value
  // SPECIAL CASE: The list is empty, no need to delete
  if (*head == NULL) {
    return;
  }
  // SPECIAL CASE: the node is at the head of the list
  NODE* currentNode = *head;
  if (currentNode->data == value) {
    *head = currentNode->next;
    delete currentNode;
  }
  // NORMAL CASE
  else {
    // We have to find whether the node exists in the list
    NODE* nextNode = currentNode->next;
    while (nextNode != NULL && nextNode->data != value) {
      currentNode = nextNode;
      nextNode = nextNode->next;
    }
    // We found the node to delete!
    if (nextNode != NULL) {
      currentNode->next = nextNode->next;
      delete nextNode;
    }
  }
}

// -----------------------------------------------------------------------------
// Delete the whole list
// -----------------------------------------------------------------------------
void deleteList(NODE** head) {
  while (*head != NULL) {
    NODE* temp = *head;
    *head = temp->next;
    delete temp;
  }
}

// -----------------------------------------------------------------------------
// Get #i node
// -----------------------------------------------------------------------------
NODE* getNodeAt(NODE* head, int pos) {
  NODE* currentNode = head;
  int currentPos = 0;
  while (currentNode != NULL && currentPos < pos) {
    currentNode = currentNode->next;
    currentPos++;
  }
  return currentNode;
}

// -----------------------------------------------------------------------------
// Insert a new element
// -----------------------------------------------------------------------------
void insertNode(NODE** head, int value, int position) {
  NODE* newNode = createNewNode(value);
  // SPECIAL CASE: Insert at the head of the list
  if (position <= 0) {
    addBeginningNode(head, value);
  }
  // NORMAL CASE
  else {
    NODE* previousNode = getNodeAt(*head, position - 1);
    if (previousNode != NULL) {
      newNode->next = previousNode->next;
      previousNode->next = newNode;
    }
  }
}

// -----------------------------------------------------------------------------
// Find the Mth-to-last element in a list (*)
// [PIE - Chapter 4]
// -----------------------------------------------------------------------------
NODE* findMthToLast(NODE* head, int m) {
  NODE* nodeA = head;
  NODE* nodeB = getNodeAt(head, m);

  // SPECIAL CASE: The m value is greater than
  // the number of elements in the list
  if (nodeB == NULL) {
    cout << "This list has less than " << m << " elements" << endl;
    return NULL;
  }

  while (nodeB->next != NULL) {
    nodeA = nodeA->next;
    nodeB = nodeB->next;
  }

  return nodeA;
}

// -----------------------------------------------------------------------------
// Check if a list is cyclic or not
// [PIE - Chapter 4]
// -----------------------------------------------------------------------------
bool checkCyclic(NODE* head) {
  NODE* slowNode = head;
  NODE* fastNode = head;

  while (slowNode != NULL && fastNode != NULL) {
    // Increase the slow node by 1 element
    slowNode = slowNode->next;

    // Increase the fast node by 2 elements
    fastNode = fastNode->next;
    if (fastNode != NULL) {
      fastNode = fastNode->next;
    }

    // If both nodes point to the same node,
    // the list is cyclic
    if (slowNode == fastNode || fastNode->next == slowNode) {
      // Note: In this situation we cannot check slowNode->next == fastNode
      // because it will have wrong result if the list has 2 elements!!!
      return true;
    }
  }

  return false;
}

// -----------------------------------------------------------------------------
// Reverse a linked list
// -----------------------------------------------------------------------------
NODE* reverseList(NODE* head) {
  // The idea is to split the list into 2 parts. The first part is the new list
  // and the second part is the rest of the old list. The first part keeps
  // growing until the second part disappears.
  // For example: 1 <-- 2 <-- 5 | 6 --> 3 --> 5 --> 9 --> NULL

  NODE* currentNode = head;

  // SPECIAL CASE: the linked list is empty!
  if (currentNode == NULL) {
    return NULL;
  }
  NODE* nextNode = currentNode->next;
  // This is a special case, the node at the beginning of the list will become
  // the last one, so it will point to NULL
  currentNode->next = NULL;

  while (nextNode != NULL) {
    NODE* temp = nextNode->next; // keep the next pointer (e.g. 6)
    nextNode->next = currentNode; // swap the link (e.g. 5 --> 2)

    currentNode = nextNode;
    nextNode = temp;
  }

  return currentNode;
}

// -----------------------------------------------------------------------------
// Find the middle of a list
// -----------------------------------------------------------------------------
NODE* findMidNode(NODE* head) {
  // SPECIAL CASE: The linked list has 0 or 1 node
  if (head == NULL || head->next == NULL) {
    return head;
  }

  NODE* slowNode = head;
  NODE* fastNode = head->next;

  while (fastNode->next != NULL) {
    slowNode = slowNode->next;
    fastNode = fastNode->next;
    if (fastNode->next != NULL) {
      fastNode = fastNode->next;
    }
  }

  return slowNode;
}

// -----------------------------------------------------------------------------
// Swap each couple of items
// 1 --> 2 --> 3 --> 4 --> 5 --> 6 --> 7
// 2 --> 1 --> 4 --> 3 --> 6 --> 5 --> 7
// -----------------------------------------------------------------------------
NODE* swapNodes(NODE* head) {
  // SPECIAL CASE: The list has only one node or it's null
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // Swap the first 2 nodes
  NODE* p1 = head;
  NODE* p2 = head->next;
  p1->next = p2->next;
  p2->next = p1;
  head = p2;

  // Recursive till the end of the list
  p1->next = swapNodes(p1->next);
  return head;
}

// -----------------------------------------------------------------------------
// Remove duplicates from an unsorted list
// Cracking the Coding Interview 5th Edition
// Exercise 2.1
//
// Duplicates
//  1. Brute force - for each item, compare it with all the rest (n^2)
//  2. Sort - nlogn
//  3. Marking - for each item, if this is the first time,
//     mark it in a boolean table
//  4. Hash table
// -----------------------------------------------------------------------------
void removeDuplicates(NODE* head) {
  // SPECIAL CASE: If the list is null or has only one element,
  // we should quit immediately

//  // O(n^2) solution
//  // currentNode runs from Node 0 to n-1
//  NODE* currentNode = head;
//  while (currentNode != NULL && currentNode->next != NULL) {
//    // nextNode runs from Node 1 to n-1 (end of the list)
//    NODE* nextNode = currentNode;
//    while (nextNode != NULL && nextNode->next != NULL) {
//      // we found a duplicate here
//      if (nextNode->next->data == currentNode->data) {
//        NODE* temp = nextNode->next; // we're going to delete this node
//        nextNode->next = temp->next;
//        delete temp;
//      }
//      else {
//        // move on to the next one
//        nextNode = nextNode->next;
//      }
//    }
//    currentNode = currentNode->next;
//  }

  // O(n) solution
  unordered_map<int, int> map;
  NODE* currentNode = head;
  NODE* previousNode = currentNode;
  while (currentNode != NULL && currentNode->next != NULL) {
    // If the current value is not in the hash table we'll add it
    if (map.find(currentNode->data) == map.end()) {
      map.insert(make_pair(currentNode->data, currentNode->data));
      // move on to the next node
      previousNode = currentNode;
      currentNode = currentNode->next;
    }
    else {
      // If the current node value already appears in the hash table
      // that means this is not the first time we see that value.
      // Remove the current node.
      previousNode->next = currentNode->next;
      delete currentNode;
      currentNode = previousNode->next;
    }
  }
}

// -----------------------------------------------------------------------------
// Merge 2 shorted linked lists
// -----------------------------------------------------------------------------
NODE* mergeTwoShortedLinkedLists(NODE* head1, NODE* head2) {
  NODE* head;
  // Iterate each item of the two lists until we reach to the end of both lists
  while (head1 != NULL || head2 != NULL) {
    // If the current value of list1 is smaller than the current value of list2
    // OR
    // We've reached the end of list 2 where there's no need to compare them
    // --> add the value of list 1 to the new list
    if (head2 == NULL || head1->data <= head2->data) {
      addEndNode(&head, head1->data);
      // move to the next node in list 1, list 2 stays still
      head1 = head1->next;
    }
    // same logic here
    // if the current value of list2 is smaller than the current value of list1
    // OR
    // we've reached the end of list 1 where there's no need to compare them
    // --> add the value of list 2 to the new list
    else if (head1 == NULL || head2->data < head1->data) {
      addEndNode(&head, head2->data);
      // move to the next node in list 2, list 1 stays still
      head2 = head2->next;
    }
  }
  return head;
}

// -----------------------------------------------------------------------------
// Main function, nothing much in this one
// -----------------------------------------------------------------------------
int main (int argc, char* argv[]) {
  NODE* myList1 = NULL;

  // --- addBeginningNode --- //
  addBeginningNode(&myList1, 9);
  addBeginningNode(&myList1, 7);
  addBeginningNode(&myList1, 5);
  addBeginningNode(&myList1, 3);
  addBeginningNode(&myList1, 1);

  // --- addEndNode --- //
  NODE* myList2 = NULL;
  addEndNode(&myList2, 2);
  addEndNode(&myList2, 4);
  addEndNode(&myList2, 6);
  addEndNode(&myList2, 8);
  addEndNode(&myList2, 10);
  addEndNode(&myList2, 12);
  addEndNode(&myList2, 14);

  // --- Print the list --- //
  printList(myList1);
  printList(myList2);

  // --- Merge 2 shorted linked list --- //
  NODE* mergedList = mergeTwoShortedLinkedLists(myList1, myList2);
  printList(mergedList);

  // --- Remove duplicated items in a list --- //
  // removeDuplicates(myList);
  // printList(myList);

  // --- Check node exists --- //
//  NODE* node = checkElementExists(myList, 5);
//  if (node != NULL) {
//    cout << "Found: " << node->data << endl;
//  }
//  else {
//    cout << "Not found!" << endl;
//  }

  // --- Delete node --- //
//  deleteNode(&myList, 10);
//  printList(myList);

  // --- Delete list --- //
//  deleteList(&myList);
//  printList(myList);

  // --- Insert Node --- //
//  insertNode(&myList, 100, 0);
//  insertNode(&myList, 200, 3);
//  insertNode(&myList, 300, 100);
//  printList(myList);

  // --- Find Mth-To-Last --- //
//  NODE* temp = findMthToLast(myList, 4);
//  if (temp != NULL) {
//    cout << temp->data << endl;
//  }

  // --- Check Cyclic --- //
  // Create a cyclic list for testing
//  NODE* n1 = getNodeAt(myList, 5);
//  NODE* n2 = getNodeAt(myList, 3);
//  n1->next = n2;
//
//  if (checkCyclic(myList) == true) {
//    cout << "Cyclic!" << endl;
//  }
//  else {
//    cout << "No cyclic!" << endl;
//  }

  // --- Reverse a list --- //
//  printList(reverseList(myList));

  // --- Find the middle of a list --- //
//  NODE* n = findMidNode(myList);
//  if (n != NULL) {
//    cout << n->data << endl;
//  }

  // --- Swap each couple of nodes in a list --- //
//  NODE* newList = swapNodes(myList);
//  printList(newList);

  return 0;
}
