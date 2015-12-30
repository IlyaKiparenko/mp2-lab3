#ifndef STACK_H
#define STACK_H

#include "List.h"

template <class Data>
class Stack {
public:
  List<Data> a;
  Stack() {
  }
  Stack(Data* ar,int len) {
    a(ar,len);
  }
  Stack(List<Data>& t) {
    a=t;
  }
  Stack(Stack& s) {
    a=s.a;
  }
  
  void push(Data k) {
    a.add1(k);
  } 
  Data& pop() {
	  if(!isEmpty())
		  return a.del1()->val;
    else
      throw exception("Empty Stack");
  }
  friend ostream& operator <<(ostream& o,const Stack<Data>& l) {
    o << l.a;
    return o;
  }
  bool isEmpty() {
    return a.isEmpty();
  }
  int isFull() {
    CNode<Data>* k;
    try {
      k= new CNode<Data>(0);
    } catch(...) {
      return 1;
    }
    delete k;
    return 0;
  }

  int operator ==(Stack<Data>& r) {
    return (a==r.a);
  }

};


#endif // STACK_H