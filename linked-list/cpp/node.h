/**
 * Represents a node in the linked list.
 */
template <class T>
class Node {
  public:
    Node(T value, Node<T> *nextNode = nullptr) {
      this->value = value;
      this->nextNode = nextNode;
    }

    /**
     * Get the node value.
     * @returns The node value.
     */
    T getValue() {
      return this->value;
    }

    /**
     * Get the node value.
     * @returns The node value.
     */
    void setValue(T value) {
      this->value = value;
    }

    /**
     * Get the next node.
     * @returns The next node.
     */
    Node<T> *getNextNode() {
      return this->nextNode;
    }

    /**
     * Set the next node.
     */
    void setNextNode(Node<T> *node) {
      this->nextNode = node;
    };

  private:
    /**
     * The data held by the node.
     */
    T value;

    /**
     * The next node in the linked list.
     */
    Node<T> *nextNode;
};