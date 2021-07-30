from node import Node

# Represents a linked list.
class LinkedList:
  # The first node in the linked list.
  __headNode = None
  
  # Creates a linked list.
  def __init__(self, node):
    self.__headNode = node

  ## Find a node by testing function.
  # 
  # The find() method returns the first node in the 
  # linked list that satisfies the provided testing function.
  # 
  # If no nodes satisfy the testing function, undefined is returned.
  def __find(self, test):
    currentNode = self.getHeadNode()
    currentIndex = 0

    while currentNode:
      if test(currentNode, currentIndex):
        return currentNode
      else:
        currentIndex = currentIndex + 1
        currentNode = currentNode.getNextNode()

  # Converts linked list values into a single output value
  # 
  # The reduce() method executes a reducer function (that you provide)
  # on each node of the linked list, resulting in a single output value.
  def __reduce(self, initialValue, reducer):
    currentNode = self.getHeadNode()
    currentIndex = 0
    accumulator = initialValue

    while currentNode:
      accumulator = reducer(accumulator, currentNode.getValue(), currentIndex)
      currentIndex = currentIndex + 1
      currentNode = currentNode.getNextNode()

    return accumulator

  # Get the head node.
  def getHeadNode(self):
    return self.__headNode

  # Set a new head node.
  def setHeadNode(self, node):
    self.__headNode = node

  # Get the tail node.
  def getTailNode(self):
    return self.__find(lambda n, i: n.getNextNode() is None)

  # Get node by stored value.
  def getNodeByValue(self, value):
    return self.__find(lambda n, i: n.getValue() is value)

  # Get node by index in linked list.
  def getNodeByIndex(self, index):
    return self.__find(lambda n, i: i is index)

  # Add new node to the head of the linked list.
  def addNodeToHead(self, value):
    self.setHeadNode(Node(value, self.getHeadNode()))

  # Add new node to the tail of the linked list.
  def addNodeToTail(self, value):
    self.getTailNode().setNextNode(Node(value))

  # Add new node at specific index of linked list.
  def addNodeByIndex(self, value, index):
    if index is 0:
      self.addNodeToHead(value)
    else:
      node = self.getNodeByIndex(index - 1)
      node.setNextNode(Node(value, node.getNextNode()))

  # Remove head node.
  def removeHeadNode(self):
    newHead = self.getHeadNode().getNextNode()
    self.getHeadNode().setNextNode(None)
    self.setHeadNode(newHead)

  # Remove tail node.
  #
  # Gets the node before the tail node and removes the link to the tail node.
  # The old tail node will be naturally cleaned up via garbage collection
  def removeTailNode(self):
    node = self.__find(lambda n, i: n.getNextNode().getNextNode() is None)
    node.setNextNode(None)

  # Remove node by value.
  # 
  # Gets the node before the matching node and removes the link to the matching node.
  # The matching node will be naturally cleaned up via garbage collection
  def removeNodeByValue(self, value):
    if self.getHeadNode().getValue() is value:
      self.removeHeadNode()
    else:
      node = self.__find(lambda n, i: n.getNextNode().getValue() is value)

      if node:
        node.setNextNode(node.getNextNode().getNextNode())

  # Remove node by index.
  #
  # Gets the node before the matching node and removes the link to the matching node.
  # The matching node will be naturally cleaned up via garbage collection
  def removeNodeByIndex(self, index):
    if index is 0:
      self.removeHeadNode()
    else:
      node = self.__find(lambda n, i: i is index - 1)

      if node:
        node.setNextNode(node.getNextNode().getNextNode())

  # Appends a value to an array and then returns the array.
  def appendAndReturn(self, arr, value):
    arr.append(value)
    return arr

  # Transform linked list values into a stringified list, comma separated.
  def toString(self, separator = ", "):
    return separator.join(self.__reduce([], lambda a, v, i: self.appendAndReturn(a, str(v))))
      
# Tests

# Create link list and add values
ll = LinkedList(Node(4))
ll.addNodeToTail(8)
ll.addNodeToTail(16)
ll.addNodeToTail(32)
ll.addNodeToTail(64)
ll.addNodeToTail(128)

# Should return 4, 8, 16, 32, 64, 128
print(ll.toString()) 

# Should remove 4
ll.removeHeadNode()

# Should return 8, 16, 32, 64, 128
print(ll.toString())

# Should remove 128
ll.removeTailNode()

# Should return 8, 16, 32, 64
print(ll.toString())

# Should return 16
print(ll.getNodeByIndex(1).getValue())

# # Should remove 16
ll.removeNodeByIndex(1)

# Should return 8, 32, 64
print(ll.toString())

# Should add 24 at index 1
ll.addNodeByIndex(24, 1)

# Should return 8, 24, 32, 64
print(ll.toString())

# # Should return 32
print(ll.getNodeByValue(32).getValue())

# # Should remove 32 from the linked list
ll.removeNodeByValue(32)

# # Should return 8, 24, 64
print(ll.toString())