 
//
// Created by George Thiruvathukal on 2/17/24.
//

#include <gtest/gtest.h>

#include "int_stack.hh"

TEST(IntStackTests, Initialization)
{
    int_stack_t stack1;
    int_stack_init(&stack1, 10);
    ASSERT_EQ(int_stack_size(&stack1), 0);
    ASSERT_EQ(int_stack_capacity(&stack1), 10);
}

TEST(IntStackTests, PushToCapacityAndOverflow)
{
    // create stack that can hold 10 items
    int_stack_t stack1;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);

    // fill it
    for (int i=0; i < capacity; i++) {
        int result = int_stack_push(&stack1, i);
        ASSERT_TRUE(result);
    }

    // ensure it's full
    ASSERT_EQ(int_stack_size(&stack1), capacity);

    // try to add one more
    int result = int_stack_push(&stack1, capacity+1);

    // and make sure it is an overflow (error)
    ASSERT_FALSE(result);
}


TEST(IntStackTests, PushToCapcacityPopUntilUnderflow
)
{
    // create stack that can hold 10 items [similar to previous test]
    int_stack_t stack1;
    const int capacity = 10;
    int_stack_init(&stack1, capacity);

    // fill it
    for (int i=0; i < capacity; i++) {
        int result = int_stack_push(&stack1, i);
        ASSERT_TRUE(result);
    }

    // now drain it one item at a time, ensuring each item is the value expected
    for (int i=capacity-1; i >= 0; i--) {
        int top_value;
        int result = int_stack_pop(&stack1, &top_value);
        ASSERT_EQ(i, top_value);
    }

    // try to remove from empty stack and ensure it fails
    int top_value;
    int result = int_stack_pop(&stack1, &top_value);
    ASSERT_FALSE(result);
}

TEST(IntStackTests, Init) {
	int_stack_t stack;
	int_stack_init(&stack, 5); // initalize stack with capacity of 5
	ASSERT_EQ(stack.size, 0); //stack size shuld be 0
	ASSERT_EQ(stack.capacity, 5); // stack capacity should be 5
}

TEST(IntStackTests, Push) {
	int_stack_t stack;
	int_stack_init(&stack, 2); // initilize stack with capacity of 2 
	ASSERT_TRUE(int_stack_push(&stack, 10)): // pushing 1st element 
	ASSERT_TRUE(int_stack_push(&stack, 20)); // pushing the 2nd element
	ASSERT_FALSE(int_stack_push(&stack, 30)); // pushing the 3rd elemet. Shouldn't work because capacity is reached
	ASSERT_EQ(stack.size, 2); //stack size should be 2
}

TEST(IntStackTests, pop)  {
	int_stack_t stack;
	int_stack_init(&stack, 5); // initalize stack with capacity of 5
	int_stack_push(&stack, 10); //push 1st element
	int_stack_push(&stack, 20); //push 2nd element 

	int top_value; 
	ASSERT_TRUE(int_stack_pop(&stack, &top_value)); //pop top value 
	ASSERT_EQ(top_value, 20); //the value poped should be last pushed 20 
	ASSERT_TRUE(int_stack_pop(&stack, &top_value)); //pop next top vale 
	ASSERT_EQ(top_value, 10); //top value should now be 10
	ASSERT_FALSE(int_stack_pop(&stack, &top_value)); //should fail because the stack is empty
}

TEST(IntStacktests, Top) {
	int_stack_t stack;
	int_stack_init(&stack, 5);
	int_stack_push(&stack, 10);
	int)stack_push(&stack, 20);

	int top_value;
	ASSERT_TRUE(int_stack_top(&stack, &top_value)); //should get the top value
	ASSERT_EQ(top_value, 20); //the top value should be the last pushed 20

	int_stack_pop(&stack, &top_value); // pops the top value to get the nexxt top value
	ASSERT_TRUE(int_stack_top(&stack, &top_value));
	ASSERT_EQ(top_value, 10); // now top should be 10

	int_stack_pop(&stack, &top_value);
	ASSERT_FALSE(int_stack_top(&stack, &top_value)); should fail because the stack is now empty 
}

TEST(IntStackTests, Dup) {
 	int_stack_t stack;
	int_stack_init(&stack, 10); // initialize stack with a capacity of 10
	int_stack_push(&stack, 5); //pusehes 5 onto the stack
	int_stack_dup(&stack); //operates duplicate

	int top_value;
	ASSERT_TRUE(int_stack_top(&stack, &top_value)); // checks if the duplication was sucessful
	ASSERT_EQ(top_value, 5);
	ASSERT_EQ(int_stack_size(&stack), 2); //confirms that the duplicated calue was added to the stack
}


TEST(IntStackTests, Swap) {
	int_stack_t stack; 
	int_stack_init(&stack, 3); //initalize stack capacity to 3
	int_stack_push(&stack, 10);
	int_stack_push(&stack, 20);
	ASSERT_EQ(int_stack_swap(&stack), 1); //should swap
	
	int top_value;
	int_stack_top(&stack, &top_value);
	ASSERT_EQ(top_value, 10); //after swap top value should be 10
}

//arithmetic

TEST(IntStackTests, Add) {
	int_stack_t stack;
	int_stack_init(&stacl, 3); //initalizes the capacity tp 3
	int_stack_push(&stack, 10);
	int_stack_push(&stack, 20);
	ASSERT_EQ(int_stack_add(&stack), 1); //addition should happen

	int top_value;
	int_stack_top(&stack, &top_value);
	ASSERT_EQ(top_value, 30); // checks if the result is cirect 
}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
