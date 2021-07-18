#include <vector>
#include <iostream>
#include "linked-list.h"

template <class T>
LinkedList<T>::LinkedList(Node<T> *node) {
  this->headNode = node;
}

// template <class T>
// Node<T> LinkedList<T>::getHeadNode() {
//   return this->headNode;
// }

// template <class T>
// void LinkedList<T>::setHeadNode(Node<T> node) {
//   this->headNode = node;
// }

// template <class T>
// Node<T> LinkedList<T>::find(bool (*test)(Node<T> node, int index)) {
//   Node<T> currentNode = this->getHeadNode();
//   int currentIndex = 0;

//   while (currentNode) {
//     bool test = test(currentNode, currentIndex);
//     if (test) {
//       return currentNode;
//     } else {
//       currentIndex = currentIndex + 1;
//       currentNode = currentNode->getNextNode();
//     }
//   }
// }

// template <class T>
// template <class InputIt>
// Node<T> LinkedList<T>::reduce(
//   bool (*reducer)(InputIt accumulator, T value, int index),
//   std::vector<T> initialValue
// ) {
//   Node<T> currentNode = this->getHeadNode();
//   std::vector<T> accumulator = initialValue;
//   int currentIndex = 0;

//   while (currentNode) {
//     accumulator = reducer(accumulator, currentNode.getValue(), currentIndex);
//     currentIndex = currentIndex + 1;
//     currentNode = currentNode.getNextNode();
//   }
// }