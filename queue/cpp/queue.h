#include <iostream>
#include <vector>
#include <optional>

/**
 * Represents a Queue.
 */
template <class T>
class Queue {
  public:
    /**
     * Creates a Queue.
     * @param limit Maximum limit of nodes allowed in Queue.
     */
    inline
    Queue(int limit = 1000) {
      this->nodes = nullptr;
      this->limit = limit;
    }

    /**
     * Destructor cleanup, deallocates heap memory allocated by this class when it goes out of scope.
     */
    inline
    ~Queue() {
    }

    /**
     * Checks if the Queue is empty.
     */
    inline
    bool isEmpty() {
      if (this->nodes->size() == 0) {
        std::cout << "The Queue is empty." << std::endl;
      } else {
        std::cout << "Not" << std::endl;
      }
      return this->nodes->size() == 0;
    }

    /**
     * Checks if the Queue is at its maximum capacity.
     */
    inline
    bool isFull() {
      if (this->nodes->size() == this->limit) {
        std::cout << "The Queue is full." << std::endl;
      }
      return this->nodes->size() == this->limit;
    }

    /**
     * Adds a new headNode to the Queue.
     * @param value The value of the new node.
     */
    inline
    void queue(T value) {
      if (!this->isFull()) {
        this->nodes->push_back(value);
        std::cout << "A node with the value " << this->nodes->back() << " has been added to the Queue." << std::endl;
      }
    }

    /**
     * Removes the headNode from the Queue and returns its value.
     * @returns The headNode value.
     */
    // inline
    // std::optional<T> pop() {
    //   std::optional<T> returnValue;

    //   if (!this->isEmpty()) {
    //     returnValue = this->headNode->value;
    //     Node<T> *nextNode = this->headNode->nextNode;
    //     delete this->headNode;
    //     this->headNode = nextNode;
    //     this->nodes->size() = this->nodes->size() - 1;
    //   }
      
    //   return returnValue;
    // }

    /**
     * Returns the headNode value.
     * @returns The headNode value.
     */
    inline
    std::optional<T> peek() {
      std::optional<T> returnValue;

      if (!this->isEmpty()) {
        // returnValue = this->nodes[0];
        returnValue = 3;
      }

      return returnValue;
    }
    
  private:
    /**
     * Queue nodes.
     */
    std::vector<T> *nodes;

    /**
     * Maximum limit of nodes allowed in Queue.
     */
    int limit;
};
