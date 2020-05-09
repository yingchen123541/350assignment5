//http://www.cplusplus.com/doc/oldtutorial/templates/
//https://www.geeksforgeeks.org/binary-tree-set-1-introduction/

#include <iostream>
#include <fstream>
//#include "binarytree.h"
#include "YukiBSTree1.cpp"

int main(){
  //template <class T>

  using namespace std;
//template <class T>

//string addStudentTree(){

//open and read from student file

  ifstream StudentFile;
  StudentFile.open("studentTable.txt");
  string StudentLine;
  string StudentID;
  int StudentID1;


  if(!StudentFile)
  {
    cerr << "student file doesn't exist, empty tree" << endl;
    //initialize empty student tree



  }//end if
  else if (StudentFile)
  {
    //studentTable successfully opened, add content into masterStudent tree
    while (getline(StudentFile, StudentLine))
    {
      for(int z=0; z < 1; z++)
      {
        //only read the first character in each line
           StudentID = StudentLine.substr(z,1);
           StudentID1 = stoi(StudentID);
          cout << StudentLine[z] << endl;

    YukiBSTree1 *masterStudent = new YukiBSTree1;
    masterStudent->insert(StudentID1);



  // node=StudentLine;
////////nidhi end

}// end for
}//end while
  StudentFile.close();

//  return masterStudent;

   }// end else if

//}

}
//add an add functions
//add a delete functions
//print advisor function?
//print all students function
