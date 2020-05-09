

#include "StudentRecord.h"
 #include <algorithm>
//default constructor
StudentRecord::StudentRecord()
{
  m_StudentLine="unknown";
  m_StudentID="unknown";
  m_StudentID1=-1;
  m_totalLine=0;
}
//overload constructor
StudentRecord::StudentRecord(int StudentID1)
{
  m_StudentLine=StudentLine;
  m_StudentID=StudentID;
  m_StudentID1=StudentID1;
  m_totalLine=totalLine;
}

StudentRecord::~StudentRecord()
{

}

void StudentRecord::option1(){
  StudentFile.open("studentTable.txt");
  if(!StudentFile)
  {
    std::cerr << "student file doesn't exist, empty tree" << std::endl;
    //initialize empty student tree
  }//end if
  else if (StudentFile)
  {
    //studentTable successfully opened, add content into masterStudent tree
    int IDArray[100];
    BST<string> *masterStudent = new BST<string>;
    while (getline(StudentFile, StudentLine))
    {
          //only read the first character in each line
        StudentID = StudentLine.substr(0,1);
        StudentID1 = stoi(StudentID);
        masterStudent->insert(StudentLine,StudentID1);
        //cout << StudentLine[z] << endl;
        std::cout << StudentLine << std::endl;
        IDArray[totalLine]=StudentID1;

       totalLine=totalLine+1;
    }//end while
    sort(IDArray, IDArray + totalLine);
    for (int a=0; a!=totalLine; ++a)
    {
      cout << IDArray[a] << endl;


      /////////not sure what to put inside printTree method /////////
      masterStudent->printTree(IDArray[a]);
    }// end for


      StudentFile.close();
   }// end else if

}// end option1 





















//add an add functions
//add a delete functions
//print advisor function?
//print all students function
