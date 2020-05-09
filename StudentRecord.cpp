//http://www.cplusplus.com/doc/oldtutorial/templates/
//https://www.geeksforgeeks.org/binary-tree-set-1-introduction/


#include "StudentRecord.h"
//default constructor
StudentRecord::StudentRecord()
{
  m_StudentLine="unknown";
  m_StudentID="unknown";
  m_StudentID1=-1;
}
//overload constructor
StudentRecord::StudentRecord(int StudentID1)
{
  m_StudentLine=StudentLine;
  m_StudentID=StudentID;
  m_StudentID1=StudentID1;
}

StudentRecord::~StudentRecord()
{

}



void StudentRecord::option1(){
  StudentFile.open("studentTable.txt");
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
           //make an array, add StudentLine[z] to array.
           //cout << StudentLine[z] << endl;
           cout << StudentLine << endl;

        }// end for
    ///////////////////////////////////////////
        //make a second for loop,
        // iterate thru the array, and use BST
        // BST.print(array[i])
    ///////////////////////////////////////////
        }//end while
      //  return StudentLine;
          StudentFile.close();
           }// end else if
//return "1";
}





















//add an add functions
//add a delete functions
//print advisor function?
//print all students function
