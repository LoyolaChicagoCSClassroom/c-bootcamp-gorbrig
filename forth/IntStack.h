#ifndef INTSTACK_H
#define INTSTACK_H

#include <vector>
#include <stdexcept>

class IntStack {
public :
	void push(int value);
	int pop();
	int top() const;
	void dup();
	void swap();

private:
	std::vector<int> stack;
}

#endif 
