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

	//Arithmetic operations
	void add();
	void subtract();
	void multiply();
	void divide();

	//stack manipulation 
	void dup();	
        void swap();
	void over();
	void rot();
	void drop();

	//double element operations 
	void twoSwap();
	void twoDup();
	void twoOver();
	void twoDrop();


void

private:
	std::vector<int> stack;
}

#endif 
