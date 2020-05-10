#include <iostream>
#include <fstream>

class FacultyRecord{
   public:
     FacultyRecord();
     FacultyRecord(int FacultyID1);
     ~FacultyRecord();
     std::ifstream FacultyFile;
     std::string FacultyLine;
     std::string FacultyID;
     int FacultyID1;
     int totalLine;
     std:: string inputFacultyID;
     int inputFacultyID1;
     std:: string O5studentID;
//add getters and setters
     std::string m_FacultyLine;
     std::string m_FacultyID;
     int m_FacultyID1;
     int m_totalLine;



     void option2();
     void option4();
     void option5();




};



// #include "DoubleLL.h"
// #include <iostream>
// #include <fstream>
//
//
// class Faculty{
// public:
//   //variables
//
//
//   //constructors
//   Faculty();
//   Faculty(int a, string b, string c, string d);
//   ~Faculty();
//
//   //helper functions
//
//
//   //modify the advisee list
//
// class FacultyRecord{
//    public:
//      FacultyRecord();
//      FacultyRecord(int a, string b, string c, string d);
//      ~FacultyRecord();
//
//      void setID(int a);
//      int getID();
//      void setName(string a);
//      string getName();
//      void setLevel(string a);
//      string getLevel();
//      void setDepartment(string a);
//      string getDepartment();
//      void printAdvisees();
//      int getNumAdvisees();
//
// //list function
//      void addAdv(int d);
//      void removeAdv(int d);
//      int getAdv(int d);
//
//      int facID;
//      string name;
//      string level;
//      string department;
//      DoubleLL<int> *adlist;
//
//      std::ifstream FacultyFile;
//      std::string FacultyLine;
//      std::string FacultyID;
//      int FacultyID1;
//      int totalLine;
// //add getters and setters
//      std::string m_FacultyLine;
//      std::string m_FacultyID;
//      int m_FacultyID1;
//      int m_totalLine;
//
//
//
//      void option2();
//
//
// };
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
// // void FacultyRecord::addAdvisee(int d){
// //   adlist->insertBack(d);
// // }
// //
// // void FacultyRecord::removeAdvisee(int d){
// //   adlist->removePos(d);
// // }
// //
// // void FacultyRecord::printAdvisees(){
// //   list->printList();
// // }
// //
// // int FacultyRecord::getAdvisee(int d){
// //   list->findPosition(d);
// // }
// //
// // int FacultyRecord::getNumAdvisees(){
// //   return list->getSize();
// // }
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
