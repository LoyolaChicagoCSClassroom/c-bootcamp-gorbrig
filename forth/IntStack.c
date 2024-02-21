#include "IntStack.h"

void IntStack::push(int value) { 
    stack.push_back(value); 
}

//push
// takes an integrr value as its paramater
// adds the value to the end of the stack. this pushes a new item onto the stack.


int IntStack::pop() { 
    if (stack.empty()) throw std::runtime_error("Stack underflow");  
    int value = stack.back(); 
    stack.pop_back(); 
    return value;  
}

//pop
//removes the top element from the stack and returns the value
//checks if the stack is empty before attempting to pop. If it s it throws an exception to signal a stack underflow
// grabs the value of the top element of the stack
// removes the last element from the vector, basicaly popping the top element off the stack
// return the value of the elment that was just popped off the stack 


int IntStack::top() const {
    if (stack.empty()) throw std::runtime_error("Stack underflow");
    return stack.back();
}

//top 
//const is a mamber function that returns the value of the top element of the stack without modifying the stack
//checks if the stack is empty and throws a runtime error of stack underflow if it is
//returns the value of the last element in the stack vector which is the top element of the stack 

void IntStack::dup() {
    push(top());
}

//dup
//is a method that duplicates the top element of the stack 
//calls the top method to get the current top element's value and then pushes this value onto the  stack again using the push method. effectivley duplicating the top element

void IntStack::swap() {
	if (stack.size() < 2) throw std::runtime_error("Not enough elements to swap");
    int top1 = pop();
    int top2 = pop();
    push(top1);
    push(top2);
}

//swap 
//makes sure there are at least 2 elements in the stack to swap. if not it throws an exception indicatng there aren't enough elements 
// pops the top elemet off the stack and stores its value in top1
// pops the next top element and stores its value in top2
//first pushes top1(which was the original top element) back onto the stack followed by top2. since push operation adds elements to the top this sequence reverses the order of the 2 elements effectivley swapping them. 

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


