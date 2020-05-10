//same as student
// add advisees
//remove a
//print advisees
//these three methods, u must use a list. we make a list.

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
  int IDArray[100];
  BST<string> *masterFaculty = new BST<string>;
  while (getline(FacultyFile, FacultyLine))
  {
      //only read the first character in each line
         FacultyID = FacultyLine.substr(0,1);
         FacultyID1 = stoi(FacultyID);
         masterFaculty->insert(FacultyLine,FacultyID1);
        //std::cout << FacultyLine << std::endl;

        totalLine=totalLine+1;
  }// end while

  sort(IDArray, IDArray + totalLine);
  for (int a=0; a!=totalLine; ++a)
  {
  //  cout << IDArray[a] << endl;
  }// end for
    masterFaculty->printRoot();

FacultyFile.close();
}//end else if

}//end option2


void FacultyRecord::option4(){
  cout << "enter a faculty ID to output the faculty information" << endl;
  cin >> inputFacultyID;
  inputFacultyID1 = stoi(inputFacultyID);

  FacultyFile.open("facultyTable.txt");
  if (FacultyFile)
  {
    BST<string> *masterFaculty = new BST<string>;
    while (getline(FacultyFile, FacultyLine))
    {
        //only read the first character in each line
           FacultyID = FacultyLine.substr(0,1);
           FacultyID1 = stoi(FacultyID);
           masterFaculty->insert(FacultyLine,FacultyID1);
    }// end while
    bool findFaculty;
    findFaculty = masterFaculty->search(inputFacultyID1);
    if(findFaculty==true){
    cout << "facultyID exist" << endl;
    masterFaculty->returnT(inputFacultyID1);
    }//end if
    else if (findFaculty==false){
      cout << "the facultyID you enter is incorrect" << endl;
    }//end else if
  }// end if
  FacultyFile.close();
}// end option 4

void FacultyRecord::option5(){
  int findLine;
  int O5totalLine=0;
  cout << "enter a student ID to print that student's advisor information " << endl;
  cin >> O5studentID;
  cout << endl;
  //read from faculty file and substr each line and see whether line contain that student ID
  FacultyFile.open("facultyTable.txt");
  if (FacultyFile)
  {
    while (getline(FacultyFile, FacultyLine))
    {
      O5totalLine=O5totalLine+1;
      // cout << "at line: " << O5totalLine << endl;
        // substring characters in each line not including faculty ID
        for (int i=2; i<=FacultyLine.length(); ++i){
           string character = FacultyLine.substr(i,1);
        //   cout << character << endl;
           if (character==O5studentID)
           {
            // cout << "find the student's advisor, the advisor is in line " << O5totalLine << "in facultytable.txt" << endl;
             findLine=O5totalLine;
           }// end if
       }// end for
    }// end while
  }//end if
  FacultyFile.close();

  //read from the file again and get the faculty Id in certain line (findLine)
  FacultyFile.open("facultyTable.txt");
  if (FacultyFile)
  {
    BST<string> *masterFaculty = new BST<string>;
    int newTotalLine=0;
    while (getline(FacultyFile, FacultyLine))
    {
      FacultyID = FacultyLine.substr(0,1);
      FacultyID1 = stoi(FacultyID);
      masterFaculty->insert(FacultyLine,FacultyID1);
      newTotalLine=newTotalLine+1;
      if (newTotalLine==findLine)
      {
        //this new character is faculty's ID, use it as a key to print tree
        string Newcharacter = FacultyLine.substr(0,1);
        int Newcharacter1= stoi(Newcharacter);
        cout << "information of student with ID " << O5studentID << "'s advisor: " << endl;
        masterFaculty->returnT(Newcharacter1);
      }//end while
    }//end getline while

  }//end if








}//end option 5
