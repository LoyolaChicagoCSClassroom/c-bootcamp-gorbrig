#include "IntStack.h"

//stack classes 

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

//arithmetic 

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

//stack manipulation 

void IntStack::over() {
	if(stack.size() < 2) throw std::runtime_error("Not enough elements for 'over'");
	int n1 = stack.at(stack.size() - 2);
	push(n1);
}

//over 
//checks if the stack has at least 2 elements if not it throws a runtime error indicating that the operation cannot be preformed 
// grabs the second item from the top of the stack and stores it in n1
//pushed n1 onto the stack effectivley duplicating the second to top element to the top of the stack 

void IntStack::rot() {
	if(stack.size() < 3) throw std::runtime_error("Not enough elements for 'rot'");
	int n1 = pop();// pop the top element 
	int n2 = pop();//pop the next top element 
	int n3 = pop();//pop the 3 top element
	push(n2);//pushes the 2nd element back first, it beomces third 
	push(n1);//pushes the top element 
	push(n3);//pushes the 3rd element, now it becomes the top
}

//rotates
//checks if the stack has at least 3 elements if not throws a runtime error
//pops the top 3 elements from the stack in a row and stores them in n1, n2, and n3
//pushes n2 back on the stack first then n1 and then n3. this order rotates the top 3 elements so that the 3rd element movces the top

void IntStack::drop() {
	if(stack.empty()) throw std::runtimee_error("Stack underflow on 'drop'");
	pop();//simply pops the top elements without using its value 
}

//Drop 
//checks if the stack is empty if it is it throws a runtime error 
// removes the top element from the stack. the removed element is not used ot returned. 


//Double element operations 

void IntStack::twoSwap() {
	if(stack.size() < 4) throw std::runtome_error("Not enough elements for '2SWAP'");
	int d1_top = pop();
	int d1_bottom = pop();
	int d2_top = pop();
	int d2_bottom = pop();
	push(d1_bottom);
	push(d1_top);
	push(d2_bottom);
	push(d2_top);
}
	
//twoSwap 
//verrifies that there are at least 4 elements on the stack to swap 2 pairs. throws error if not 
// pops the top 4 elements from the stack labeling them from top to bottom. each represent a pair to be swapped. 
/pushes the elements back onto the stack in a swapped order. first the bottom pair in the origional order then the top pair. 

void IntStack::twoDup() {
	if(stack.size < 2) throw std::runtie_error("Not enough elements for '2DUP'");
	int top = stack.at(stack.size() - 1);
	int second_top = stack.at(stack.size() - 2);
	push(second_top);
	push(top);
}

//twoDuplicate
//checks that there are at least 2 elements on the stack to duplicate the top pair. throws an error if not 
// grabs the top 2 elements without removing them 
// pushes the top 2 elements back onto the stack in the same order, effectively duplicating the top pair of elements. 

void IntStack::twoOver() {
	if(stack.size() < 4) throw std::runtime_error("Not enough elements for '2OVER'");
	int second_top = stack.at(stack.size() - 2);
	int third_top = stack.at(stack.size() - 3);
	push(third_top);
	push(second_top);
}

//twoOver 
//checks that there are lat least 4 elements on the stack. throws an error if not 
//grabs the 2nd and 3rd elements from the top of the stack.
//pushes those 2 elements onto the stack duplication the 2nd pair to the top of the stack 


void IntStack::twoDrop() {
	if(stack.size() < 2) throw std::runtime_error("Not enough elements for '2DROP'");
	pop();//preforms pop(0 twice to drop the top 2 elements 
	pop();
}

// twoDrop
//removes the top 2 elements from the stack 




