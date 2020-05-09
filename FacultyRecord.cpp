
#include "FacultyRecord.h"


//default constructor
FacultyRecord::FacultyRecord()
{
  m_FacultyLine="unknown";
  m_FacultyID="unknown";
  m_FacultyID1=-1;
}

//overload constructor
FacultyRecord::FacultyRecord(int FacultyID1)
{
  m_FacultyLine=FacultyLine;
  m_FacultyID=FacultyID;
  m_FacultyID1=FacultyID1;
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
  while (getline(FacultyFile, FacultyLine))
  {
    for(int z=0; z < 1; z++)
    {
      //only read the first character in each line
         FacultyID = FacultyLine.substr(z,1);
         FacultyID1 = stoi(FacultyID);
         BST<string> *masterFaculty = new BST<string>;
         masterFaculty->insert(FacultyLine,FacultyID1);
        std::cout << FacultyLine << std::endl;

        }// end for
  }// end while
FacultyFile.close();
}//end else if

}//end option2
