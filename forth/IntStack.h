#ifndef INTSTACK_H
#define INTSTACK_H

#include <vector>
#include <stdexcept>

class IntStack {
public :
	//stack operations
	void push(int value);
	int pop();
	int top() const;
	void dup();
	void swap();

	//Arithmetic operations
	void add();
	void subtract();
	void multiply();
	void divide();

private:
	std::vector<int> stack;
}

#endif 
