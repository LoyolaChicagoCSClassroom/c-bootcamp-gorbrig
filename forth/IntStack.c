#include "IntStack.h"

void IntStack::push(int value) {
    stack.push_back(value);
}

int IntStack::pop() {
    if (stack.empty()) throw std::runtime_error("Stack underflow");
    int value = stack.back();
    stack.pop_back();
    return value;
}

int IntStack::top() const {
    if (stack.empty()) throw std::runtime_error("Stack underflow");
    return stack.back();
}

void IntStack::dup() {
    push(top());
}

void IntStack::swap() {
    if (stack.size() < 2) throw std::runtime_error("Not enough elements to swap");
    int top1 = pop();
    int top2 = pop();
    push(top1);
    push(top2);
}

// Implement other operations here...


