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
      this->limit = limit;
    }

    /**
     * Checks if the Queue is empty.
     */
    inline
    bool isEmpty() {
      if (this->nodes.size() == 0) {
        std::cout << "The Queue is empty." << std::endl;
      } 
      return this->nodes.size() == 0;
    }

    /**
     * Checks if the Queue is at its maximum capacity.
     */
    inline
    bool isFull() {
      if (this->nodes.size() == this->limit) {
        std::cout << "The Queue is full." << std::endl;
      }
      return this->nodes.size() == this->limit;
    }

    /**
     * Adds a new node to the Queue.
     * @param value The value of the new node.
     */
    inline
    void queue(T value) {
      if (!this->isFull()) {
        this->nodes.push_back(value);
        std::cout << "A node with the value " << this->nodes.back() << " has been added to the Queue." << std::endl;
      }
    }

    /**
     * Removes the first node from the Queue and returns its value.
     * @returns The first node value.
     */
    inline
    std::optional<T> dequeue() {
      std::optional<T> returnValue;

      if (!this->isEmpty()) {
        returnValue = this->nodes.front();
        this->nodes.erase(this->nodes.begin());
      }
      
      return returnValue;
    }

    /**
     * Returns the first node value.
     * @returns The first node value.
     */
    inline
    std::optional<T> peek() {
      std::optional<T> returnValue;

      if (!this->isEmpty()) {
        returnValue = this->nodes.front();
      }

      return returnValue;
    }
    
  private:
    /**
     * Queue nodes.
     */
    std::vector<T> nodes;

    /**
     * Maximum limit of nodes allowed in Queue.
     */
    int limit;
};
