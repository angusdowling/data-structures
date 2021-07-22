#include <string>
#include <vector>
#include <functional>
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
    inline
    LinkedList(T value) {
      this->headNode = new Node<T>(value);
    }

    /**
     * Destructor cleanup, deallocates heap memory allocated by this class when it goes out of scope.
     */
    inline
    ~LinkedList() {
      Node<T> *currentNode = this->getHeadNode();

      while (currentNode) {
        Node<T> *nextNode = currentNode->getNextNode();
        delete currentNode;
        currentNode = nextNode;
      }
    }

    /**
     * Get the head node.
     * @returns The head node.
     */
    inline
    Node<T> *getHeadNode() {
      return this->headNode;
    }

    /**
     * Set a new head node.
     * @param node The new head node.
     */
    inline
    void setHeadNode(Node<T> *node) {
      this->headNode = node;
    }

    /**
     * Get the tail node.
     * @returns The tail node.
     */
    inline
    Node<T> *getTailNode() {
      std::function<bool (Node<T>*, int)> matcher = [](Node<T>* node, int i) { 
        return node->getNextNode() == nullptr; 
      };

      return this->find(matcher);
    }

    /**
     * Get node by stored value.
     * @param value value to match node stored value.
     * @returns matching node
     */
    inline
    Node<T> *getNodeByValue(T value) {
      std::function<bool (Node<T>*, int)> matcher = [value](Node<T> *node, int i) { 
        return node->getValue() == value;
      };

      return this->find(matcher);
    }

    /**
     * Get node by index in linked list.
     * @param index index to match node index.
     * @returns matching node
     */
    inline
    Node<T> *getNodeByIndex(int index) {
      std::function<bool (Node<T>*, int)> matcher = [index](Node<T> *node, int i) { 
        return index == i;
      };

      return this->find(matcher);
    }

    /**
     * Add new node to the head of the linked list.
     * @param value value of new head node.
     */
    inline
    void addNodeToHead(T value) {
      this->setHeadNode(new Node<T>(value, this->getHeadNode()));
    }

    /**
     * Add new node to the tail of the linked list.
     * @param value value of new tail node.
     */
    inline
    void addNodeToTail(T value) {
      this->getTailNode()->setNextNode(new Node<T>(value));
    }

    /**
     * Add new node at specific index of linked list.
     * @param value value of new node.
     * @param index index to add node at.
     */
    inline
    void addNodeByIndex(T value, int index) {
      if (index == 0) {
        this->addNodeToHead(value);
      } else {
        Node<T> *node = this->getNodeByIndex(index - 1);
        node->setNextNode(new Node<T>(value, node->getNextNode()));
      }
    }

    /**
     * Remove head node.
     */
    inline
    void removeHeadNode() {
      Node<T> *newHead = this->getHeadNode()->getNextNode();
      delete this->getHeadNode();
      this->setHeadNode(newHead);
    }

    /**
     * Remove tail node.
     * 
     * Gets the node before the tail node and removes the link to the tail node.
     */
    inline
    void removeTailNode() {
      std::function<bool (Node<T>*, int)> matcher = [](Node<T> *node, int i) { 
        return node->getNextNode()->getNextNode() == nullptr;
      };

      Node<T> *node = this->find(matcher);
      delete node->getNextNode();
      node->setNextNode(nullptr);
    }

    /**
     * Remove node by value.
     * 
     * Gets the node before the matching node and removes the link to the matching node.
     * 
     * @param value Value of node to remove.
     */
    inline
    void removeNodeByValue(T value) {
      if (this->getHeadNode()->getValue() == value) {
        this->removeHeadNode();
      } else {
        std::function<bool (Node<T>*, int)> matcher = [value](Node<T> *node, int i) { 
          return node->getNextNode()->getValue() == value;
        };

        Node<T> *node = this->find(matcher);

        if (node) {
          Node<T> *newNextNode = node->getNextNode()->getNextNode();
          delete node->getNextNode();
          node->setNextNode(newNextNode);
        }
      }
    }

    /**
     * Remove node by index.
     * 
     * Gets the node before the matching node and removes the link to the matching node.
     * 
     * @param index Index of node to remove.
     */
    inline
    void removeNodeByIndex(int index) {
      if (index == 0) {
        this->removeHeadNode();
      } else {
        std::function<bool (Node<T>*, int)> matcher = [index](Node<T> *node, int i) { 
          return i == index - 1;
        };

        Node<T> *node = this->find(matcher);

        if (node) {
          Node<T> *newNextNode = node->getNextNode()->getNextNode();
          delete node->getNextNode();
          node->setNextNode(newNextNode);
        }
      }
    }

    /**
     * Transform linked list values into a stringified list, comma separated.
     * @returns Stringified list of node values.
     */
    inline
    std::string toString(std::string separator = ", ") {
      std::function<void (std::vector<T>*, T, int)> reducer = [](std::vector<T> *accumulator, T value, int i) { 
        accumulator->push_back(value);
      };

      std::vector<T> accumulator;
      this->reduce(reducer, &accumulator);
      return this->join(&accumulator, separator);
    }

  private:
    /**
     * The first node in the linked list.
     */
    Node<T> *headNode;

    /**
     * Combine the individual values of a vector into a string output.
     * 
     * @param value Vector of values to join together.
     * @param separator Characters used to separate values in the string output.
     * 
     * @returns String of combined values.
     */
    inline
    std::string join(const std::vector<T> *value, const std::string separator = ", ") {
      std::string accumulator;
      
      for (const T &piece : *value) {
        accumulator = !accumulator.empty() 
          ? accumulator + separator + std::to_string(piece) 
          : accumulator + std::to_string(piece);
      }

      return accumulator;
    }

    /**
     * Find a node by testing function.
     * 
     * The find() method returns the first node in the 
     * linked list that satisfies the provided testing function.
     * 
     * If no nodes satisfy the testing function, undefined is returned.
     * 
     * @param test Testing function.
     * @returns Node that matches the testing function.
     */
    inline
    Node<T> *find(const std::function<bool (Node<T>*, int)> test) {
      Node<T> *currentNode = this->getHeadNode();
      int currentIndex = 0;

      while (currentNode) {
        if (test(currentNode, currentIndex)) {
          return currentNode;
        }

        currentNode = currentNode->getNextNode();
        currentIndex = currentIndex + 1;
      }

      return currentNode;
    } 

    /**
     * Aggregates linked list values into a single output value
     * 
     * The reduce() method executes a reducer function (that you provide)
     * on each node of the linked list, resulting in a single output value.
     * 
     * @param reducer Reducer function.
     * @returns Single output defined by reducer function.
     */
    inline
    void reduce(
      std::function<void (std::vector<T>*, T, int)> reducer,
      std::vector<T> *accumulator
    ) {
      int currentIndex = 0;
      Node<T> *currentNode = this->getHeadNode();

      while (currentNode) {
        reducer(accumulator, currentNode->getValue(), currentIndex);
        currentIndex = currentIndex + 1;
        currentNode = currentNode->getNextNode();
      }
    }
};
