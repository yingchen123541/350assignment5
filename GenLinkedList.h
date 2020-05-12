/** GenLinkedList.h
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: to make a data structure of linkedlist 
* Date: May 12, 2020
*/

#include <iostream>
#include "DListNode.h"

using namespace std;

template <class T>
class GenLinkedList{
private:
  //variables
  DListNode<T> *front;
  DListNode<T> *back;
  unsigned int size;

public:
  //Constructors
  GenLinkedList();
  ~GenLinkedList();

  //core functions
  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  DListNode<T>* remove(T d);
  int find(T d);
  T findPosition(int d);

  //helper functions
  bool isEmpty();
  void printList();
  T getFront();
  T getBack();
  unsigned int getSize();
};

//Default
template <class T>
GenLinkedList<T>::GenLinkedList(){
  size = 0;
  front = NULL; //null pointer
  back = NULL;
}

//Destructor
template <class T>
GenLinkedList<T>::~GenLinkedList(){
  DListNode<T>* curr = front;
  DListNode<T>* next = curr;
  while(curr != NULL){
    next = curr->next;
    delete curr;
    curr = next;
  }
  curr = NULL;
}


//inserts to the front of the list
template <class T>
void GenLinkedList<T>::insertFront(T d){
  DListNode<T> *node = new DListNode<T>(d);
  if(size == 0){
    back = node;
  }else{
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//inserts  to the back
template <class T>
void GenLinkedList<T>::insertBack(T d){
  DListNode<T> *node = new DListNode<T>(d);
  if(size == 0){
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//Returns the list size
template <class T>
unsigned int GenLinkedList<T>::getSize(){
  return size;
}

//prints the list to the console
template <class T>
void GenLinkedList<T>::printList(){
  DListNode<T> *curr = front;

  while(curr !=NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}
//removes the front
template <class T>
T GenLinkedList<T>::removeFront(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  DListNode<T> *ft = front;
  if(size == 1){ //Only one element
    back = NULL;
  }else{ //More than one element
    front->next->prev = NULL;
  }
  front = front->next;
  T temp = ft->data;
  ft->next = NULL;
  delete ft;
  size--;

  return temp;
}

//removes the back
template <class T>
T GenLinkedList<T>::removeBack(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  DListNode<T> *bt = back;
  if(size == 1){ //Only one element
    front = NULL;
  }else{ //More than one element
    back->prev->next = NULL;
  }
  back = back->prev;
  T temp = bt->data;
  bt->prev = NULL;
  delete bt;
  size--;

  return temp;
}

//will return + removes element
template <class T>
DListNode<T>* GenLinkedList<T>::remove(T d){
  DListNode<T> *curr = front;

  while(curr->data != d){
    curr = curr->next;
    if(curr == NULL){ //The value is not found
      return NULL;
    }
  }
  //Found it
  //Have to check if the node is in the front or back first
  if(curr == front){
    front = curr->next;
  }else{
    curr->prev->next = curr->next;
  }
  if(curr == back){
    back = curr->prev;
  }else{
    curr->next->prev = curr->prev;
  }

  curr->next = NULL;
  curr->prev = NULL;
  size--;
  return curr;
}

//returns the position
template <class T>
int GenLinkedList<T>::find(T d){
  int idx = 0;
  DListNode<T> *curr = front;

  while(curr != NULL){
    if(curr->data == d){
      break;
    }
    idx++;
    curr = curr->next;
  }
  if(curr == NULL){
    idx = -1;
  }
  return idx;
}

template <class T>
T GenLinkedList<T>::findPosition(int d){
  DListNode<T> *curr = front;
  int idx = 0;

  while(idx != d){
    curr = curr->next;
    idx++;
  }
  return curr->data;
}

//return the front value
template <class T>
T GenLinkedList<T>::getFront(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  T temp = front->data;
  return temp;
}

//return the back value
template <class T>
T GenLinkedList<T>::getBack(){
  if(size==0){
    cout << "Error: Cannot return a value, list empty." << endl;
    exit(0);
  }
  T temp = back->data;
  return temp;
}
