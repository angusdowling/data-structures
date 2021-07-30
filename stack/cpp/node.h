/**
 * Represents a node in the stack.
 */
template <typename T>
struct Node {
  /**
   * Default constructor
   */ 
  Node() = default;

  /**
   * Creates a node.
   * @param value Data of the node.
   * @param nextNode Next node linked to this one.
   */
  inline
  Node(T value, Node<T> *nextNode = nullptr) {
    this->value = value;
    this->nextNode = nextNode;
  }

  /**
   * Data of the node.
   */
  T value;

  /**
   * Next node linked to this one.
   */
  Node<T>* nextNode;
};