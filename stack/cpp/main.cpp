#include <iostream>
#include <optional>
#include "stack.h"

int main() {
  Stack<int> stack(10);
  std::optional<int> currentValue;
  // Should output "The stack is empty."
  currentValue = stack.peek();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }
  
  // Should output "The stack is empty."
  currentValue = stack.pop();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.push(4);
  stack.push(5);
  stack.push(6);
  stack.push(7);
  stack.push(8);
  stack.push(9);
  stack.push(10);

  // Should output "Stack is full." 
  stack.push(11);

  // Should be 10
  currentValue = stack.peek();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = stack.pop();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = stack.pop();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = stack.pop();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = stack.pop();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = stack.pop();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = stack.pop();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  currentValue = stack.peek();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }

  stack.push(12);

  // Should be 12
  currentValue = stack.peek();
  if (currentValue.has_value()) {
    std::cout << "peeking the top value: " << currentValue.value() << std::endl;
  }
}