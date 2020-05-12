/** genstack.cpp
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: to make a data structure of stack for rollback
* Date: May 12, 2020
*/




#include "genstack.h"
//inclduing header class

//constructors
template <typename T>
genstack<T>::genstack(){
  cap = 128;
  first = -1;
  myArray = new T[cap];
}
//overloaded
template <typename T>
genstack<T>::genstack(int max){
  cap= max;
  first = -1;
  t = '1';
  myArray = new T[cap];
}
//deconstructor will delete
template <typename T>
genstack<T>::~genstack(){
  delete this->myArray;
}
// push onto the stack
template <typename T>
void genstack<T>::push(char t){
  //first checking if the stack is empty
  //if (!this->isFull()){
    myArray[++first] = t;

}
//popping values off the stack
template <typename T>
void genstack<T>::pop() throw(StackEx){
  if (!this->isEmpty()){
    --first;
  }else{
    //if stack is empty cannot pop, throw exception class
    throw StackEx();
  }
}
// to find out the current size of the stack
template <typename T>
int genstack<T>::currentsize() const{
  return first + 1;
}
// to see if the stack is empty
template <typename T>
bool genstack<T>::isEmpty() const{
  return (first == -1);
}
//to check if the stack is full
template <typename T>
bool genstack<T>::isFull() const
{
  return (first == cap - 1);
}
// to check the top value of the stack
template <typename T>
char genstack<T>::top() const throw(StackEx){
  if (!this->isEmpty()){
    return this->myArray[first];
  }else{
    throw StackEx();
  }
}
//remove the first value of the stack
template <typename T>
void genstack<T>::remove(){
  this->first = -1;
}
