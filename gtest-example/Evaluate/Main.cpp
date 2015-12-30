#include "Pieces\Expression.h"

int main() {
  Stack<Symbol> r;
  int u=0;
  char * s=new char[64]; //"a+(b-c)*d-f/(g+h)0"; //
  cout << "Input expression: " << endl << "\t";
  cin >> s;
  Expression a1(s);
  cout << "Postfix form is " << endl <<"\t"<< a1 << endl;
  cout << "Result is " << endl <<"\t"<<  a1.eval() << endl;

  return 0;
}