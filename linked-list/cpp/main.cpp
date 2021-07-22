#include <iostream>
#include "linked-list.h"

int main() {
  LinkedList<int> linkedList(128);

  std::cout << "Adding 64 to head..." << std::endl;
  linkedList.addNodeToHead(64);
  std::cout << "Adding 32 to head..." << std::endl;
  linkedList.addNodeToHead(32);
  std::cout << "Adding 16 to head..." << std::endl;
  linkedList.addNodeToHead(16);
  std::cout << "Adding 8 to head..." << std::endl;
  linkedList.addNodeToHead(8);
  std::cout << "Adding 4 to head..." << std::endl;
  linkedList.addNodeToHead(4);

  std::cout << "Adding 256 to tail..." << std::endl;
  linkedList.addNodeToTail(256);
  std::cout << "Adding 512 to tail..." << std::endl;
  linkedList.addNodeToTail(512);
  std::cout << "Adding 1024 to tail..." << std::endl;
  linkedList.addNodeToTail(1024);
  std::cout << "Adding 2048 to tail..." << std::endl;
  linkedList.addNodeToTail(2048);
  std::cout << "Adding 4096 to tail..." << std::endl;
  linkedList.addNodeToTail(4096);

  std::cout << "Adding 1337 to index (2)..." << std::endl;
  linkedList.addNodeByIndex(1337, 2);
  std::cout << "-------" << std::endl;
  // Should return 4
  std::cout << "Head node: " << linkedList.getHeadNode()->getValue() << std::endl;
  // Should return 4096
  std::cout << "Tail node: " << linkedList.getTailNode()->getValue() << std::endl;
  // Should return 64
  std::cout << "Node by value (64): " << linkedList.getNodeByValue(64)->getValue() << std::endl;
  // Should return 1337
  std::cout << "Node by index (2): " << linkedList.getNodeByIndex(2)->getValue() << std::endl;
  std::cout << "-------" << std::endl;
  std::cout << "Removing head node..." << std::endl;
  linkedList.removeHeadNode();
  
  // Should return 8
  std::cout << "Head node: " << linkedList.getHeadNode()->getValue() << std::endl;
  std::cout << "-------" << std::endl;
  std::cout << "Removing tail node..." << std::endl;
  linkedList.removeTailNode();

  // Should return 2048
  std::cout << "Tail node: " << linkedList.getTailNode()->getValue() << std::endl;
  std::cout << "-------" << std::endl;
  std::cout << "Removing node by value (256)..." << std::endl;
  linkedList.removeNodeByValue(256);

  // Expect getting a node by value 256 to return 0
  std::cout << "Node by value (256): " << linkedList.getNodeByValue(256) << std::endl;
  std::cout << "-------" << std::endl;
  // Should return 16
  std::cout << "Node by index (2): " << linkedList.getNodeByIndex(2)->getValue() << std::endl;

  std::cout << "Removing node by index (2)..." << std::endl;
  linkedList.removeNodeByIndex(2);

  // Should return 32
  std::cout << "Node by index (2): " << linkedList.getNodeByIndex(2)->getValue() << std::endl;

  // Should return 8, 1337, 32, 64, 128, 512, 1024, 2048
  std::cout << linkedList.toString() << std::endl;
}