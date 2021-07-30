#include <iostream>
#include <optional>
#include "node.h" 

/**
 * Represents a Stack.
 */
template <class T>
class Stack {
  public:
    /**
     * Creates a stack.
     * @param limit Maximum limit of nodes allowed in stack.
     */
    inline
    Stack(int limit = 1000) {
      this->headNode = nullptr;
      this->size = 0;
      this->limit = limit;
    }

    /**
     * Destructor cleanup, deallocates heap memory allocated by this class when it goes out of scope.
     */
    inline
    ~Stack() {
      Node<T> *currentNode = this->headNode;

      while (currentNode) {
        Node<T> *nextNode = currentNode->nextNode;
        delete currentNode;
        currentNode = nextNode;
      }
    }

    /**
     * Checks if the stack is empty.
     */
    inline
    bool isEmpty() {
      if (this->size == 0) {
        std::cout << "The stack is empty." << std::endl;
      }
      return this->size == 0;
    }

    /**
     * Checks if the stack is at its maximum capacity.
     */
    inline
    bool isFull() {
      if (this->size == this->limit) {
        std::cout << "The stack is full." << std::endl;
      }
      return this->size == this->limit;
    }

    /**
     * Adds a new headNode to the stack.
     * @param value The value of the new node.
     */
    inline
    void push(T value) {
      if (!this->isFull()) {
        this->headNode = new Node<T>(value, this->headNode);
        std::cout << "A node with the value " << this->headNode->value << " has been added to the stack." << std::endl;
        this->size = this->size + 1;
      }
    }

    /**
     * Removes the headNode from the stack and returns its value.
     * @returns The headNode value.
     */
    inline
    std::optional<T> pop() {
      std::optional<T> returnValue;

      if (!this->isEmpty()) {
        returnValue = this->headNode->value;
        Node<T> *nextNode = this->headNode->nextNode;
        delete this->headNode;
        this->headNode = nextNode;
        this->size = this->size - 1;
      }
      
      return returnValue;
    }

    /**
     * Returns the headNode value.
     * @returns The headNode value.
     */
    inline
    std::optional<T> peek() {
      std::optional<T> returnValue;

      if (!this->isEmpty()) {
        returnValue = this->headNode->value;
      }

      return returnValue;
    }
    
  private:
    /**
     * The first node in the stack.
     */
    Node<T> *headNode;

    /**
     * Current size of the stack.
     */
    int size;

    /**
     * Maximum limit of nodes allowed in stack.
     */
    int limit;
};
