#ifndef SYMBOL_H
#define SYMBOL_H

#include <string.h>
#include "Stack.h"

typedef double (*fun)(double ,double);

#define converse(a) new Symbol(a) 

class Symbol {
protected:
  virtual void print(ostream& o) const{};
public:
  virtual double value(Stack<Symbol*>&) const {return 0;};
  virtual int me(){ return 0;};
  bool operator ==(Symbol& l) {
    return false;
  }
  Symbol& operator= (Symbol& w){ return *this; } 
  friend ostream& operator <<(ostream& o,const Symbol& l);
};



class Numb : public Symbol {
public:
  double e;
  Numb(double r=0):e(r) { }
  virtual double value(Stack<Symbol*>& r) const {
    return e;
  }
  virtual int me() { return 1; }
  bool operator ==(Numb& l) {
    return (e==l.e);
  }
protected:
  
  virtual void print(ostream& o) const {
    o << e;
  }
};

class Var : public Symbol {
public:
   static List<Var> save;
  

  char* s;
  double val;
  Var(char* u=0,double k=0) {
    if(u!=0){
      s=new char[strlen(u)+1];
	    strcpy(s,u);
    }else 
      s=0;
	  val=k;
  }
  Var(const Var& r) {
	  s=new char[strlen(r.s)+1];
	  strcpy(s,r.s);
	  val=r.val;
  }
  ~Var() {
    delete[] s;
  }
  virtual int me() { return 2; }
  virtual double value(Stack<Symbol*>& e) const {
	  Var* r=save.find(*this);
	  if(r==0) {
		  cout << "What is a value for " << s << "?" << endl <<"\t";
		  double t;
		  cin >> t;
      Var p(s,t);
		  save.add(p);
		  return t;
	  }else {
		  return r->val;
	  }
  }
  bool operator ==(const Var& l) {
    return strcmp(s,l.s)==0;
  }
  bool operator !=(const Var& l) {
    return strcmp(s,l.s)!=0;
  }
  Var& operator= (const Var& r) {
    if(s!=0){
	    delete[] s;
	  }
	  s=new char[strlen(r.s)+1];
	  strcpy(s,r.s);
	  val=r.val;
    return *this;
  }

protected:
  
  virtual void print(ostream& o) const{
    o << s;
  }
};



class Op : public Symbol {
public:
  char  c;
  int priority;
  fun f;
  Op(char _c,int p=0,fun t=0) {
    c=_c;
    priority=p;
	f=t;
  }
  virtual int me() { return 3; }
  bool operator ==(Op& l) {
    return (c==l.c);
  }
  virtual double value(Stack<Symbol*>& e) const {
    double t= f(e.pop()->value(e),e.pop()->value(e));
	e.push(new Numb(t));
	return t;
  }
protected:
  
  virtual void  print(ostream& o) const {
    o << c;
  }
};


inline ostream& operator<< (ostream& o, const Symbol& l){
  l.print(o);
  return o;
}

#endif // SYMBOL_H