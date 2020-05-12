/** GenLinkedList.h
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

// based on the algorithm given in the textbook
#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
#include "StackEx.h"

using namespace std;
//template classes, also known as general classes, easier to reuse code and not have to
//make new code for each data type.
template <typename T>
class genstack
{
  public:
    //default constructor
    genstack();
    //overlpaded constructor
    genstack(int cap);
    ~genstack();

    //main functions
    //insert
    void push(char t);
    //remove
    void pop() throw(StackEx);

    //helper functions
    //returns how many elements are in the stack
    int currentsize() const;
    //returns the top element
    char top() const throw(StackEx);
    //returns true or false of the stack is empty
    bool isEmpty() const;
    //returns true or false of the stack if full
    bool isFull() const;
    //removes the top elemt of the stack
    void remove();

  private:
    T* myArray;
    int cap;
    int first;
    char t;

};

#endif
