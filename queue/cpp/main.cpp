#include <iostream>
#include <optional>
#include "queue.h"

int main() {
  Queue<int> queue(10);
  std::optional<int> currentValue;

  queue.queue(5);
  currentValue = queue.peek();

  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  queue.queue(7);
  currentValue = queue.peek();

  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = queue.dequeue();

  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }
}