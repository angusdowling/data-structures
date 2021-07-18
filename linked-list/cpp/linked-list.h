#include <string>
#include <vector>
#include "node.h" 

/**
 * Represents a node in the linked list.
 */
template <class T>
class LinkedList {
  public:
    /**
     * Creates a linked list.
     * @param node Node to be set as the first node in the linked list.
     */
    LinkedList(Node<T> *node);

    // /**
    //  * Get the head node.
    //  * @returns The head node.
    //  */
    // Node<T> getHeadNode();

    // /**
    //  * Set a new head node.
    //  * @param node The new head node.
    //  */
    // void setHeadNode(Node<T> node);

    // /**
    //  * Get the tail node.
    //  * @returns The tail node.
    //  */
    // Node<T> getTailNode();

    // /**
    //  * Get node by stored value.
    //  * @param value value to match node stored value.
    //  * @returns matching node
    //  */
    // Node<T> getNodeByValue(T value);

    // /**
    //  * Get node by index in linked list.
    //  * @param index index to match node index.
    //  * @returns matching node
    //  */
    // Node<T> getNodeByIndex(int index);

    // /**
    //  * Add new node to the head of the linked list.
    //  * @param value value of new head node.
    //  */
    // void addNodeToHead(T value);

    // /**
    //  * Add new node to the tail of the linked list.
    //  * @param value value of new tail node.
    //  */
    // void addNodeToTail(T value);

    // /**
    //  * Add new node at specific index of linked list.
    //  * @param value value of new node.
    //  * @param index index to add node at.
    //  */
    // void addNodeByIndex(T value, int index);

    // /**
    //  * Remove head node.
    //  */
    // void removeHeadNode();

    // /**
    //  * Remove tail node.
    //  * 
    //  * Gets the node before the tail node and removes the link to the tail node.
    //  * The old tail node will be naturally cleaned up via garbage collection
    //  */
    // void removeTailNode();

    // /**
    //  * Remove node by value.
    //  * 
    //  * Gets the node before the matching node and removes the link to the matching node.
    //  * The matching node will be naturally cleaned up via garbage collection
    //  * 
    //  * @param value Value of node to remove.
    //  */
    // void removeNodeByValue(T value);

    // /**
    //  * Remove node by index.
    //  * 
    //  * Gets the node before the matching node and removes the link to the matching node.
    //  * The matching node will be naturally cleaned up via garbage collection
    //  * 
    //  * @param index Index of node to remove.
    //  */
    // void removeNodeByIndex(int index);

    // /**
    //  * Transform linked list values into a stringified list, comma separated.
    //  * @returns Stringified list of node values.
    //  */
    // std::string toString(std::string separator = ",");

  private:
    /**
     * The first node in the linked list.
     */
    Node<T> *headNode;

    // /**
    //  * Find a node by testing function.
    //  * 
    //  * The find() method returns the first node in the 
    //  * linked list that satisfies the provided testing function.
    //  * 
    //  * If no nodes satisfy the testing function, undefined is returned.
    //  * 
    //  * @param test Testing function.
    //  * @returns Node that matches the testing function.
    //  */
    // Node<T> find(bool (*test)(Node<T> node, int index));  

    // /**
    //  * Converts linked list values into a single output value
    //  * 
    //  * The reduce() method executes a reducer function (that you provide)
    //  * on each node of the linked list, resulting in a single output value.
    //  * 
    //  * @param reducer Reducer function.
    //  * @returns Single output defined by reducer function.
    //  */
    // template<class InputIt>
    // Node<T> reduce(
    //   bool (*reducer)(InputIt accumulator, T value, int index), 
    //   std::vector<T> initialValue
    // );
};