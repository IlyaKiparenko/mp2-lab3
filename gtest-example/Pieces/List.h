#ifndef LIST_H
#define LIST_H

#include "CNode.h"
#include <iostream>

using namespace std;

template<class Data>
class List {
private:
	CNode<Data>* start;
	CNode<Data>* end;
public:
	List():start(0),end(0) {	}
	List(Data& val) {
		start=new CNode<Data>(val);
		end=start;
	}
	List(Data* ar,int len) {
		if (len>0) {
			start=new CNode<Data>(ar[0]);
			CNode<Data>* t=start;
			for (int i=1; i<len; i++) {
				t->next=new CNode<Data>(ar[i]);
				t=t->next;
			}
			end=t;
		} else {
			start=0;
			end=0;
		}
	}
	List(const List<Data>& a) {
		CNode<Data>* t=a.start;
		if(t!=0) {
			start=new CNode<Data>(*t);
			end=start;
			while(t->next!=0) {
				t=t->next;
				add(t->val);
			}
      
		}	
	}
	~List(){
		if(start!=0) {
			while(start!=0) {
				end=start->next;
				delete start;
				start=end;
			}
		}
	}

	void add(Data val) {
		if(start==0) { 
			start=new CNode<Data>(val);
			end=start;
		} else {
			end=end->next=new CNode<Data>(val);
		}
	}
	void add(CNode<Data>* r,Data& val) {
		CNode<Data>* l=r->next;
		r->next=new CNode<Data>(val,l);
	}
	void add1(Data val) {
		start=new CNode<Data>(val,start);
		if(end==0) end=start;
	}

	CNode<Data>* del(Data q) {
		if(start!=0) {
			CNode<Data>* t=start;
			if((t->val)==q)
				return del1();
			else {
				while((t->next!=0) && ((t->next->val)!=q)) {
					t=t->next;
				}
				if(t->next!=0) 
					return del(t);
				else
					return 0;
			}
		} else
      throw exception("Empty list!");
	}

	Data* find(const Data& q) {
		if(start!=0) {
			CNode<Data>* t=start;
			if((t->val)==(q)) 
				return &(t->val);
			else {
				while((t->next!=0) && ((t->next->val)!=(q))) {
					t=t->next;
				}
				if(t->next!=0) 
					return &(t->next->val);
				else
					return 0;
			}
		} else return 0;
	}
	CNode<Data>* del(CNode<Data>* r) {
		CNode<Data>* l=r->next;
		if(l!=0){
			r->next=l->next;
			return l;
		} else 
      throw exception("Empty list!");
	}
	CNode<Data>* del1() {
		if(start==0) return 0;
		CNode<Data>* t=start;
		start=start->next;
		if(start==0) end=0;
		return t;
	}
  List& operator =(List& p) {
    this->~List();
    new (this) List(p);
    return *this;
  }
  int operator ==(List& p) {
    if (start == 0 && p.start == 0)
    return true;
    if (start == 0 || p.start == 0)
    return false;
    CNode<Data> *f1 = start;
    CNode<Data> *f2 = p.start;
    while (f1->next != 0) {
      if (f1->val != f2->val)
        return false;
      f1 = f1->next;
      f2 = f2->next;
    }
    return true;
  }

	friend ostream& operator <<(ostream& o,const List<Data>& l) {
		CNode<Data>* r=l.start;
		while(r!=0) {
			o << *(r->val) << ' ';
			r=r->next;
		}
		return o;
	}
	bool isEmpty() {
    return (start==0);
  }
  CNode<Data>* GetFirst() {
    return start;
  }

};

#endif // LIST_H