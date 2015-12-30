#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "Stack.h"
#include "Symbol.h"

class Expression {
 private:
  Stack<Symbol*> expr;
 public:
  Expression(char* a);
  friend ostream& operator <<(ostream& o,const Expression& l) {
    o << l.expr;
    return o;
  }
  double eval();
  double eval(List<Var> t);
};



#endif // EXPRESSION_H