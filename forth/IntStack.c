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

void IntStack::add() {
	int n2 = pop(); // pop the top element 
	int n1 = pop(); // pop the next top element
	push(n1 + n2); //push the sum of the 2 elements back onto the stack 
}

void IntStack::subtract() {
	int n2 = pop(); //pop the top element 
	int n1 = pop(); //pop the next top element 
	push(n1-n2); //push the difference of the 2 elements back on the stack}

void IntStack::multiply() {
	int n2 = pop(); //pop the top element
	int n1 = pop(); //pop the next top element 
	push(n1 * n2); //push the product of the 2 elements back onto the stack 
}

void IntStack::divide() {
	int n2 = pop(); //pop the top element 
	if(n2 ==0) throw std::runtime_error("Division by zero");
	int n1 pop(); //pop the next top element 
	push(n1 / n2); //push the quotient of the 2 elements back on the stack 
}






// Implement other operations here...


