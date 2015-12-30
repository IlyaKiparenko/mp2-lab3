#include "Expression.h"

typedef double (*fun)(double ,double);
double p1(double a,double b) {
	return a+b;
}
double p2(double a,double b) {
	return a-b;
}
double p3(double a,double b) {
	return a*b;
}
double p4(double a,double b) {
	return a/b;
}
double p5(double a,double b) {
	return pow(a,b);
}

Op ops[]={Op('+',2,p1),Op('-',2,p2),Op('*',3,p3),Op('/',3,p4),Op('(',1),Op(')',1),Op('^',4,p5)};
int lenops=7;

bool isNum(char c){
  return ((c>='0') && (c<='9'));
}

int isOp(char c){
  int i=0;
  while((c!=ops[i].c) && (i<lenops)) i++;

  return (i<lenops)*(i+1);
}

bool isLetter(char c){
  return ((c>='A') && (c<='z'));
}

Expression::Expression(char* a) {
  Stack<Symbol*> s;
  Stack<Symbol*> out;
  int i=0;  // k=1 num
  int k=0;   // k=2 op
  int pk=0; // k=3 var
  char c;
  int pos=0;
  while((a[i-1]!=0) || (a[0]!=0)) {
    
    pk=0;
    c=a[i];
    switch (k) {
      case 1:{
        if(isNum(c) || (c=='e') || (c=='.') || ((a[i-1]=='e') && (c=='-')))
          pk=1;
        break;
      }
      case 3:{
        if(isLetter(c) || isNum(c))
          pk=3;
        break;
      }
      default:{
        if(isNum(c)) 
          pk=1;
        else 
          if(isOp(c)) { 
            if(c=='(')
              s.push(new Op(ops[isOp(c)-1]));
            else if(c==')') {
              Symbol* e;
              while ((((Op*)((e=s.pop()))) ->c != '(') && !s.isEmpty()) {
                out.a.add(e);
              }
            } else {
              Op u=ops[isOp(c)-1];
              Symbol* e;
              if(!s.isEmpty()) {
                while ((((Op*)((e=s.pop()))) ->priority >= u.priority) && !s.isEmpty()) {
                  out.a.add(e);
                }
                s.push(e);
              }
              s.push(new Op(ops[isOp(c)-1]));
            } 
            pos=i+1;
            k=0; pk=0;
          }else if(isLetter(c)) 
                  pk=3;
        k=pk;
        break;
      }
    }
    if(((k!=pk) && (k!=0)) || (a[i]==0)) {
      char* t= new char[i-pos+1];
      t[i-pos]=0;
      for( int j=0; j<i-pos; j++)
        t[j]=a[j+pos];
       
      if(k==1) {
        out.a.add(new Numb(atof(t)));
        delete[] t;
        
      }
      if(k==3) {
        out.a.add(new Var(t));
      }
      pos=i;
      k=0;
      if(c==0) break;
    }else
      i++;  
  }
  if (a[0]==0)
    throw exception("Empty string");
  Symbol* e;
  if(!s.isEmpty())
  do {
    e=s.pop();
    if(e->me()==3) {
      if (((Op*)e)->c=='(')
        throw exception("Wrong brackets"); 
    } else 
      throw exception("Wrong brackets"); 
    out.a.add(e);
  } while ( !s.isEmpty());
  expr=out; 
}


double Expression::eval() {
  Symbol* u;
	Stack<Symbol*> o;
	while(!expr.isEmpty()) {
		u=expr.pop();
		if(u->me()!=3) {
			o.push(new Numb(u->value(o)));
		}else 
			u->value(o);
	}
	return o.pop()->value(o);
}

double Expression::eval(List<Var> variables) {
  Var::save=variables;
  return Expression::eval();
}
