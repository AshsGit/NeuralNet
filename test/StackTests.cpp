#include "gtest/gtest.h"

#include "../include/stack.h"


struct LinkedStackTests
    : public ::testing::Test 
{
    Stack<float>* stack = new Stack<float>();
};

struct LinkedStackTests_pop
    : public ::testing::Test 
{
    Stack<float>* stack = new Stack<float>();
    LinkedStackTests_pop() {
        this->stack->push(3);
        this->stack->push(4);
        this->stack->push(5.5);
    }
};

TEST_F(LinkedStackTests, pop_on_empty_1) {
    ASSERT_THROW(stack->pop(), StackPopOnEmpty);
}
TEST_F(LinkedStackTests, pop_on_empty_2) {
    stack->push(3);
    ASSERT_NO_THROW(stack->pop());
    ASSERT_THROW(stack->pop(), StackPopOnEmpty);
}

TEST_F(LinkedStackTests, isEmpty) {
    ASSERT_EQ(stack->isEmpty(), true);
    stack->push(3);
    ASSERT_EQ(stack->isEmpty(), false);
    stack->push(3);
    ASSERT_EQ(stack->isEmpty(), false);
    stack->pop();
    ASSERT_EQ(stack->isEmpty(), false);
    stack->pop();
    ASSERT_EQ(stack->isEmpty(), true);
}

TEST_F(LinkedStackTests_pop, push_and_pop) {
    ASSERT_EQ(stack->pop(), 5.5);
    ASSERT_EQ(stack->pop(), 4);
    ASSERT_EQ(stack->pop(), 3);
    ASSERT_EQ(stack->isEmpty(), true);
}

TEST_F(LinkedStackTests_pop, pop_many_1) {
    vector<float> out;
    ASSERT_NO_THROW(
        out = stack->pop(3) 
    );
    ASSERT_EQ(out, (vector<float>{5.5, 4, 3}));
}

TEST_F(LinkedStackTests_pop, pop_many_2) {
    vector<float> out;
    ASSERT_THROW(
        out = stack->pop(4), 
        StackIrrecoverableDataLoss
    );
}

TEST_F(LinkedStackTests_pop, pop_many_3) {
    vector<float> out;
    ASSERT_NO_THROW(
        out = stack->pop(0)
    );
    ASSERT_EQ(out, (vector<float>{}));
}

TEST_F(LinkedStackTests, push_many_pop_many_order_preserved) {
    vector<float> in = {1,2,3,5};
    ASSERT_NO_FATAL_FAILURE(
        stack->push(in)
    );
    ASSERT_EQ(in, stack->pop(4)); // ensure order is preserved
}
