/** DListNode.h
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: to define the basics of a linked list -- nodes
* Date: May 12, 2020
*/

#include <iostream>

template <class T>
class DListNode{
public:

	//Constructors
	DListNode();
	//overloaded constructors
	DListNode(T d);
	//destructor
	~DListNode();

  T data;
  DListNode *next;
  DListNode *prev;


};

//Default Constructord
template <class T>
DListNode<T>::DListNode(){

}

//Overloaded constructor
template <class T>
DListNode<T>::DListNode(T d){
  data = d;
  next = NULL; //null pointer
  prev = NULL;
}

//Destructor
template <class T>
DListNode<T>::~DListNode(){
  next = NULL;
  prev = NULL;
}
