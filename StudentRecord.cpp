

#include "StudentRecord.h"
 #include <algorithm>

//new default constructor
StudentRecord::StudentRecord(){
  studID = 0;
  name = "";
  level = "";
  major = "";
  gpa = 0.0;
  advisor = 0;
}

//new overloaded constructor
StudentRecord::StudentRecord(int a, string b, string c, string d, double e, int f){
    studID = a;
    name = b;
    level = c;
    major = d;
    gpa = e;
    advisor = f;
}

StudentRecord::~StudentRecord()
{

}

//access + modifers
void StudentRecord::setID(int a){
  studID = a;
}

int StudentRecord::getID(){
  return studID;
}

void StudentRecord::setName(string a){
  name = a;
}

string StudentRecord::getName(){
  return name;
}

void StudentRecord::setLevel(string a){
  level = a;
}

string StudentRecord::getLevel(){
  return level;
}

void StudentRecord::setMajor(string a){
  major = a;
}

string StudentRecord::getMajor(){
  return major;
}

void StudentRecord::setGPA(double a){
  gpa = a;
}

double StudentRecord::getGPA(){
  return gpa;
}

void StudentRecord::setAdvisor(int a){
  advisor = a;
}

int StudentRecord::getAdvisor(){
  return advisor;
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
      //  std::cout << StudentLine << std::endl;
        IDArray[totalLine]=StudentID1;

       totalLine=totalLine+1;
    }//end while
    sort(IDArray, IDArray + totalLine);
    for (int a=0; a!=totalLine; ++a)
    {
    //  cout << IDArray[a] << endl;

    }// end for
    masterStudent->printRoot();


      StudentFile.close();
   }// end else if

}// end option1




// //old default constructor
// StudentRecord::StudentRecord()
// {
//   m_StudentLine="unknown";
//   m_StudentID="unknown";
//   m_StudentID1=-1;
//   m_totalLine=0;
// }
// //old overload constructor
// StudentRecord::StudentRecord(int StudentID1)
// {
//   m_StudentLine=StudentLine;
//   m_StudentID=StudentID;
//   m_StudentID1=StudentID1;
//   m_totalLine=totalLine;
// }














//add an add functions
//add a delete functions
//print advisor function?
//print all students function
