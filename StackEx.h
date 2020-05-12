/** stackEx.h
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: roll back function for option 13
* Date: May 12, 2020
*/

#ifndef STACKEX_H
#define STACKEX_H
//class for stack empty error exception!!!
#include <iostream>
#include <exception>
using namespace std;

class StackEx : public exception{
public:
  virtual const char* what() const throw(){
    return "Stack empty ERROR!";
  }
};

#endif
