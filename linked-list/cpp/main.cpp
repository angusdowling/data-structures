#include <iostream>
#include "node.h"

int main() {
  Node<int> headNode(4);

  // std::cout << headNode.getValue() << "\n";


  // LinkedList<int> linkedList(&headNode);

  // linkedList.addNodeToTail(8);
  // linkedList.addNodeToTail(16);
  // linkedList.addNodeToTail(32);
  // linkedList.addNodeToTail(64);
  // linkedList.addNodeToTail(128);

  // // Should return 4, 8, 16, 32, 64, 128
  // std::cout << linkedList.toString() << "\n";

  // // Should remove 4
  // linkedList.removeHeadNode();

  // // Should return 8, 16, 32, 64, 128
  // std::cout << linkedList.toString() << "\n";

  // // Should remove 128
  // linkedList.removeTailNode();

  // // Should return 8, 16, 32, 64
  // std::cout << linkedList.toString() << "\n";

  // // Should return 16
  // std::cout << linkedList.getNodeByIndex(1).getValue() << "\n";

  // // Should remove 16
  // linkedList.removeNodeByIndex(1);

  // // Should return 8, 32, 64
  // std::cout << linkedList.toString() << "\n";

  // // Should add 24 at index 1
  // linkedList.addNodeByIndex(24, 1);

  // // Should return 8, 24, 32, 64
  // std::cout << linkedList.toString() << "\n";

  // // Should return 32
  // std::cout << linkedList.getNodeByValue(32).getValue() << "\n";

  // // Should remove 32 from the linked list
  // linkedList.removeNodeByValue(32);

  // // Should return 8, 24, 64
  // std::cout << linkedList.toString() << "\n";
}