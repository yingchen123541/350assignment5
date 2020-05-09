
#include "FacultyRecord.h"
 #include <algorithm>

//default constructor
FacultyRecord::FacultyRecord()
{
  m_FacultyLine="unknown";
  m_FacultyID="unknown";
  m_FacultyID1=-1;
  m_totalLine=0;
}

//overload constructor
FacultyRecord::FacultyRecord(int FacultyID1)
{
  m_FacultyLine=FacultyLine;
  m_FacultyID=FacultyID;
  m_FacultyID1=FacultyID1;
  m_totalLine=totalLine;
}

FacultyRecord::~FacultyRecord()
{

}

void FacultyRecord::option2(){
 //open and read from faculty file
 FacultyFile.open("facultyTable.txt");
 if(!FacultyFile)
 {
   std::cerr << "faculty file doesn't exist, empty tree" << std::endl;
  //initialize empty faculty tree
}//end if
else if (FacultyFile)
{
  //facultyTable successfully opened, add content into masterFaculty tree
  int IDArray[100];\
  BST<string> *masterFaculty = new BST<string>;
  while (getline(FacultyFile, FacultyLine))
  {
      //only read the first character in each line
         FacultyID = FacultyLine.substr(z,1);
         FacultyID1 = stoi(FacultyID);
         masterFaculty->insert(FacultyLine,FacultyID1);
        std::cout << FacultyLine << std::endl;

        totalLine=totalLine+1;
  }// end while

  sort(IDArray, IDArray + totalLine);
  for (int a=0; a!=totalLine; ++a)
  {
    cout << IDArray[a] << endl;


    /////////not sure what to put inside printTree method /////////
    masterFaculty->printTree(IDArray[a]);
  }// end for

FacultyFile.close();
}//end else if

}//end option2
