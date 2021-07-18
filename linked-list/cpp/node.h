/**
 * Represents a node in the linked list.
 */
template <class T>
class Node {
  public:
    Node(int value);

    /**
     * Get the node value.
     * @returns The node value.
     */
    // T getValue();

    // /**
    //  * Get the next node.
    //  * @returns The next node.
    //  */
    // Node<T> *getNextNode();

    // /**
    //  * Set the next node.
    //  */
    // Node<T> *setNextNode();

  private:
    /**
     * The data held by the node.
     */
    int value;

    /**
     * The next node in the linked list.
     */
    // Node<T> *nextNode;
};