//http://www.cplusplus.com/doc/oldtutorial/templates/
//https://www.geeksforgeeks.org/binary-tree-set-1-introduction/

#include <iostream>
#include <fstream>
#include "binarytree.h"

int main(){
  template <class T>

  using namespace std;
//template <class T>

//string addStudentTree(){

//open and read from student file

  ifstream StudentFile;
  StudentFile.open("studentTable.txt");
  string StudentLine;
  string StudentID;


  if(!StudentFile)
  {
    cerr << "student file doesn't exist, empty tree" << endl;
    //initialize empty student tree



  }//end if
  else if (StudentFile)
  {
    //studentTable successfully opened, add content into masterStudent tree
  //  BSTree1 *masterStudent = new BSTree1(10);
    while (getline(StudentFile, StudentLine))
    {
      for(int z=0; z < 1; z++)
      {
        //only read the first character in each line
           StudentID = StudentLine.substr(z,1);
          cout << StudentLine[z] << endl;

///////////////nidhi start looking from here

    BST<T> *masterStudent = new BST<T>;
   masterStudent->insert(T node , int k)
   k=StudentID;
   node=StudentLine;
////////nidhi end

}// end for
}//end while
  StudentFile.close();

//  return masterStudent;

   }// end else if

//}

}
