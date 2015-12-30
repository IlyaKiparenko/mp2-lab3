#include "Pieces\Stack.h"
#include "gtest\gtest.h"


TEST(Stack, can_create_Stack) {
  Stack<int> *s;
  ASSERT_NO_THROW(s = new Stack<int>());
}

TEST(Stack, can_create_copied_Stack) {
  Stack<int> s1;
  s1.push(1);
  s1.push(8);
  ASSERT_NO_THROW(Stack<int> s2(s1));
}

TEST(Stack, copied_Stack_is_equal_to_sourse_one) {
  Stack<int> s1;
  s1.push(3);
  Stack<int> s2(s1);
  EXPECT_EQ(true, s1 == s2);
}

TEST(Stack, copied_Stack_has_its_own_memory) {
  Stack<int> s1;
  s1.push(1);
  s1.push(2);
  Stack<int> s2(s1);
  s2.pop();
  s2.push(3);
  EXPECT_EQ(false, s1 == s2);
}

TEST(Stack, IsEmpty_returns_1_when_Stack_is_empty) {
  Stack<int> s;
  EXPECT_EQ(1, s.isEmpty());
}

TEST(Stack, IsEmpty_returns_0_when_Stack_isnt_empty) {
  Stack<int> s;
  s.push(1);
  EXPECT_EQ(0, s.isEmpty());
}

TEST(Stack, IsFull_returns_0_when_Stack_isnt_full) {
  Stack<int> s;
  s.push(1);
  EXPECT_EQ(0, s.isFull());
}

TEST(Stack, can_push_new_element) {
  Stack<int> s;
  ASSERT_NO_THROW(s.push(1));
}

TEST(Stack, cant_pop_element_fron_empty_Stack) {
  Stack<int> s;
  ASSERT_ANY_THROW(s.pop());
}

TEST(Stack, can_pop_element_from_not_empty_Stack) {
  Stack<int> s;
  s.push(1);
  ASSERT_NO_THROW(s.pop());
}

TEST(Stack, poped_element_is_equal_to_pushed_one) {
  Stack<int> s;
  s.push(1);
  EXPECT_EQ(1, s.pop());
}

