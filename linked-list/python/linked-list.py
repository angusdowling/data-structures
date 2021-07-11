# This is an implementation of a mono-directional Linked List

class Node:
  def __init__(self, value, next_node = None):
    self.value = value
    self.next_node = next_node

  def get_value(self):
    return self.value

  def get_next_node(self):
    return self.next_node

  def set_next_node(self, next_node):
    self.next_node = next_node

class LinkedList:
    def __init__(self, value):
      head_node = Node(value)
      self.head_node = head_node

    def get_head_node(self):
      return self.head_node

    def get_tail_node(self):
      current_node = self.get_head_node()

      while current_node:
        if current_node.get_next_node() == None:
          return current_node

        current_node = current_node.get_next_node()

    def get_node_by_value(self, value):
      current_node = self.get_head_node()

      while current_node:
        if current_node.get_value() is value:
          return current_node
        
        current_node = current_node.get_next_node()

    def get_node_by_index(self, index):
      current_node = self.get_head_node()
      current_index = 0

      while current_node:
        if current_node is not None:
          if current_index is index:
            return current_node

        current_index = current_index + 1
        current_node = current_node.get_next_node()

    def add_node_to_head(self, new_value):
      new_node = Node(new_value, self.get_head_node())
      self.head_node = new_node

    def add_node_to_tail(self, new_value):
      new_node = Node(new_value)
      tail_node = self.get_tail_node()
      tail_node.set_next_node(new_node)

    def add_node_by_index(self, new_value, index):
      current_node = self.get_head_node()
      current_index = 0

      if index is current_index:
        add_node_to_head(new_value)
      else:
        while current_node:
          next_index = current_index + 1
          next_node = current_node.get_next_node()

          if next_node:
            if index is next_index:
              new_node = Node(new_value)
              new_node.set_next_node(next_node)
              current_node.set_next_node(new_node)

          current_index = current_index + 1
          current_node = next_node

    def remove_head_node(self):
      new_head = self.get_head_node().get_next_node()
      self.head_node.set_next_node(None)
      self.head_node = new_head

    def remove_tail_node(self):
      current_node = self.get_head_node()

      while current_node:
        next_node = current_node.get_next_node()

        # If the next node is the last node
        if next_node:
          if next_node.get_next_node() is None:
            current_node.set_next_node(None)

        current_node = next_node

    def remove_node_by_value(self, value):
      current_node = self.get_head_node()

      if current_node.get_value() is value:
        remove_head_node()
      else:
        while current_node:
          next_node = current_node.get_next_node()

          if next_node:
            if next_node.get_value() is value:
              current_node.set_next_node(next_node.get_next_node())

          current_node = next_node

    def remove_node_by_index(self, index):
      current_node = self.get_head_node()
      current_index = 0

      if current_index is index:
        remove_head_node()
      else:
        while current_node:
          next_index = current_index + 1
          next_node = current_node.get_next_node()

          if next_node is not None:
            if next_index is index:
              current_node.set_next_node(next_node.get_next_node())

          current_index = current_index + 1
          current_node = next_node

    def stringify_list(self):
      current_node = self.get_head_node()
      stringified_value = ''

      while current_node:
        value = current_node.get_value()
        next_node = current_node.get_next_node()

        if value is not None:
          stringified_value += str(value)

        if next_node:
          if next_node.get_value() is not None:
            stringified_value += ", "

        current_node = next_node

      return stringified_value

      
# Tests

# Create link list and add values
ll = LinkedList(4)
ll.add_node_to_tail(8)
ll.add_node_to_tail(16)
ll.add_node_to_tail(32)
ll.add_node_to_tail(64)
ll.add_node_to_tail(128)

# Should remove 4
ll.remove_head_node()

# Should remove 128
ll.remove_tail_node()

# Should return 16
print(ll.get_node_by_index(1).get_value())

# Should remove 16
ll.remove_node_by_index(1)

# Should add 24 at index 1
ll.add_node_by_index(24, 1)

# Should return 32
print(ll.get_node_by_value(32).get_value())

# Should remove 32 from the linked list
ll.remove_node_by_value(32)

# Should return 8, 24, 64
print(ll.stringify_list())