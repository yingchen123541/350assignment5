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










///same as student
// add advisees
//remove a
//print advisees
//these three methods, u must use a list. we make a list.

// #include "FacultyRecord.h"
// #include "DListNode.h"
//  #include <algorithm>
//
//
// //default constructor
// FacultyRecord::FacultyRecord() {
//   facID = 0;
//   name = " ";
//   level = " ";
//   department = " ";
//   adlist = new DoubleLL<int>;
// //   m_FacultyLine="unknown";
// //   m_FacultyID="unknown";
// //   m_FacultyID1=-1;
// //   m_totalLine=0;
//  }
//
// //overload constructor
// FacultyRecord::FacultyRecord(int a, string b, string c, string d)
// {
//    facID = a;
//    name = b;
//    level = c;
//    department = d;
//    adlist = new DoubleLL<int>;
//   // m_FacultyLine=FacultyLine;
//   // m_FacultyID=FacultyID;
//   // m_FacultyID1=FacultyID1;
//   // m_totalLine=totalLine;
// }
//
// FacultyRecord::~FacultyRecord()
// {
//
// }
//
// void FacultyRecord::setID(int a){
//   facID = a;
// }
//
// int FacultyRecord::getID(){
//   return facID;
// }
//
// void FacultyRecord::setName(string a){
//   name = a;
// }
//
// string FacultyRecord::getName(){
//   return name;
// }
//
// void FacultyRecord::setLevel(string a){
//   level = a;
// }
//
// string FacultyRecord::getLevel(){
//   return level;
// }
//
// void FacultyRecord::setDepartment(string a){
//   department = a;
// }
//
// string FacultyRecord::getDepartment(){
//   return department;
// }
//
// void FacultyRecord::addAdvisee(int d){
//   adlist->insertBack(d);
// }
//
// void FacultyRecord::removeAdvisee(int d){
//   adlist->removePos(d);
// }
//
// void FacultyRecord::printAdvisees(){
//   list->printList();
// }
//
// int FacultyRecord::getAdvisee(int d){
//   list->findPosition(d);
// }
//
// int FacultyRecord::getNumAdvisees(){
//   return list->getSize();
// }
//
//
//
// void FacultyRecord::option2(){
//  //open and read from faculty file
//  FacultyFile.open("facultyTable.txt");
//  if(!FacultyFile)
//  {
//    std::cerr << "faculty file doesn't exist, empty tree" << std::endl;
//   //initialize empty faculty tree
// }//end if
// else if (FacultyFile)
// {
//   //facultyTable successfully opened, add content into masterFaculty tree
//   int IDArray[100];\
//   BST<string> *masterFaculty = new BST<string>;
//   while (getline(FacultyFile, FacultyLine))
//   {
//       //only read the first character in each line
//          FacultyID = FacultyLine.substr(0,1);
//          FacultyID1 = stoi(FacultyID);
//          masterFaculty->insert(FacultyLine,FacultyID1);
//         //std::cout << FacultyLine << std::endl;
//
//         totalLine=totalLine+1;
//   }// end while
//
//   sort(IDArray, IDArray + totalLine);
//   for (int a=0; a!=totalLine; ++a)
//   {
//   //  cout << IDArray[a] << endl;
//   }// end for
//     masterFaculty->printRoot();
//
// FacultyFile.close();
// }//end else if
//
// }//end option2
