#include "gtest/gtest.h"

#include "../include/stack.h"


struct LinkedStackTests 
    : public ::testing::Test 
{
    Stack* stack = new ::linked::Stack();
};

TEST_F(LinkedStackTests, pop_on_empty_1) {
    ASSERT_THROW(stack->pop(), StackPopOnEmpty);
}
TEST_F(LinkedStackTests, pop_on_empty_2) {
    stack->push(3);
    ASSERT_NO_THROW(stack->pop());
    ASSERT_THROW(stack->pop(), StackPopOnEmpty);
}
TEST_F(LinkedStackTests, push_and_pop) {
    ASSERT_NO_THROW({
        stack->push(3);
        stack->push(4);
        stack->push(5.5);
    });
    ASSERT_EQ(stack->pop(), 5.5);
    ASSERT_EQ(stack->pop(), 4);
    ASSERT_EQ(stack->pop(), 3);
    ASSERT_EQ(stack->isEmpty(), true);
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
