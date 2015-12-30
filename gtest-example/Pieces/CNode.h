#ifndef CNODE_H
#define CNODE_H

template <class Data>
class CNode {
public:
  Data val;
  CNode<Data>* next;

  CNode(Data v,CNode<Data>* q=0) {
  	val=v;
	  next=q;
  }
};



#endif // CNODE_H