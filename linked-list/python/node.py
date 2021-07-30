# Represents a node in the linked list.
class Node:
  # The data held by the node.
  __value = None

  # The next node in the linked list.
  __nextNode = None

  # Creates a linked list node.
  def __init__(self, value, nextNode = None):
    self.__value = value
    self.__nextNode = nextNode

  # Get the node value.
  def getValue(self):
    return self.__value

  # Get the next node.
  def getNextNode(self):
    return self.__nextNode

  # Set the next node.
  def setNextNode(self, nextNode):
    self.__nextNode = nextNode