#include "Pieces\Expression.h"
#include "gtest\gtest.h"

TEST(Expression, can_create_expression) {
  EXPECT_NO_THROW(Expression a("1+1"));
}

TEST(Expression, can_calculate_expresion_in_a_postfix_notation) {
  char* str1 = "a+b*c";
  double d2 = 7;
  List<Var> l;
  Var a("a",1),b("b",2),c("c",3);
  l.add(a);
  l.add(b);
  l.add(c);
  Expression k(str1);
  double d1 = k.eval(l);
  EXPECT_EQ(d1, d2);
}
TEST(Expression, throws_when_input_invalid) {
  char* str1 = "a+(b-c";
  EXPECT_ANY_THROW(Expression a(str1));
}

TEST(Expression, throws_when_try_convert_empty_writing) {
  char* str1 = "";
  EXPECT_ANY_THROW(Expression a(str1));
}