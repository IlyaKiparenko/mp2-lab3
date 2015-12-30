#include "Pieces\List.h"
#include "gtest\gtest.h"

TEST(List, can_create_List) {
  List<int> *w;
  ASSERT_NO_THROW(w = new List<int>);
}

TEST(List, can_create_copied_List) {
  List<int> w;
  w.add(1);
  ASSERT_NO_THROW(List<int> List2(w));
}

TEST(List, copied_List_is_equal_to_sourse_one) {
  List<int> w;
  w.add(1);
  List<int> List2(w);
  EXPECT_EQ(List2.GetFirst()->val, 1);
}

TEST(List, copied_List_has_its_own_memory) {
  List<int> w;
  w.add(1);
  List<int> List2(w);
  List2.add(2);
  List2.del(1);
  EXPECT_NE(List2.GetFirst()->val, w.GetFirst()->val);
}

TEST(List, can_find_element) {
  List<int> w;
  w.add(2);
  w.add(3);
  w.add(4);
  w.add(5);
  ASSERT_TRUE(w.find(3) != 0);
}


TEST(List, can_delete_element) {
  List<int> w;
  w.add(2);
  w.add(3);
  w.add(4);
  w.add(5);
  ASSERT_NO_THROW(w.del(5));
  EXPECT_EQ(0,w.find(5));
}

TEST(List, return_null_when_delete_not_actual_value) {
  List<int> w;
  w.add(2);
  w.add(3);
  w.add(4);
  w.add(5);
  EXPECT_EQ(0, w.del(11));
}

TEST(List, can_delete_first_element) {
  List<int> w;
  w.add(2);
  w.add(3);
  w.add(4);
  w.add(5);
  ASSERT_NO_THROW(w.del(2));
}

TEST(List, throws_when_try_delete_in_empty_List) {
  List<int> List;
  ASSERT_ANY_THROW(List.del(1));
}

TEST(List, can_insert_first_element) {
  List<int> List;
  ASSERT_NO_THROW(List.add1(5));
  EXPECT_EQ(5, List.GetFirst()->val);
}

TEST(List, can_insert_last_element) {
  List<int> List;
  List.add1(2);
  ASSERT_NO_THROW(List.add(5));
}

TEST(List, can_insert_last_element_when_List_is_empty) {
  List<int> List;
  ASSERT_NO_THROW(List.add(5));
  EXPECT_EQ(5, List.GetFirst()->val);
}

TEST(List, can_get_first) {
  List<int> List;
  List.add(5);
  List.add(6);
  List.add(7);
  ASSERT_NO_THROW(List.GetFirst());
  EXPECT_EQ(5, List.GetFirst()->val);
}
