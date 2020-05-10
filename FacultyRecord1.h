#include <iostream>
#include "GenLinkedList.h"
#include "StudentRecord.cpp"

using namespace std;

class FacultyRecord1{
public:
  //variables
  int facID;
  string name;
  string level;
  string department;
  int m_FacultyID1;
  int m_totalLine;
  GenLinkedList<int> *advlist;
  std::ifstream FacultyFile;
  std::string FacultyLine;
  std::string FacultyID;
  int FacultyID1;
  int totalLine;
  std:: string inputFacultyID;
  int inputFacultyID1;
  std:: string O5studentID;
  std::string m_FacultyLine;
  std::string m_FacultyID;

  std::ifstream StudentFile;
  std::string StudentLine;
  std::string StudentID;
  int StudentID1;

  //constructors
  FacultyRecord1();
  FacultyRecord1(int a, string b, string c, string d);
  ~FacultyRecord1();
  void setID(int a);
  int getID();
  void setName(string a);
  string getName();
  void setLevel(string a);
  string getLevel();
  void setDepartment(string a);
  string getDepartment();
  void printAdvisees();
  int getNumAdvisees();


  //modify the list
  void addAdv(int d);
  void removeAdv(int d);
  int getAdv(int d);
//run options
  void option2();
  void option4();
  void option5();
  void option6();


};

//default constructor
FacultyRecord1::FacultyRecord1(){
  facID = 0;
  name = "";
  level = "";
  department = "";
  advlist = new GenLinkedList<int>;
}

//overloaded constructor
FacultyRecord1::FacultyRecord1(int a, string b, string c, string d){
  facID = a;
  name = b;
  level = c;
  department = d;
 advlist = new GenLinkedList<int>;
}

//destructor
FacultyRecord1::~FacultyRecord1(){
}

//accessors and modifers
void FacultyRecord1::setID(int a){
  facID = a;
}

int FacultyRecord1::getID(){
  return facID;
}

void FacultyRecord1::setName(string a){
  name = a;
}

string FacultyRecord1::getName(){
  return name;
}

void FacultyRecord1::setLevel(string a){
  level = a;
}

string FacultyRecord1::getLevel(){
  return level;
}

void FacultyRecord1::setDepartment(string a){
  department = a;
}

string FacultyRecord1::getDepartment(){
  return department;
}
//list related functions
void FacultyRecord1::addAdv(int d){
  advlist->insertBack(d);
}

void FacultyRecord1::removeAdv(int d){
  advlist->remove(d);
}

void FacultyRecord1::printAdvisees(){
  advlist->printList();
}

int FacultyRecord1::getAdv(int d){
  return advlist->findPosition(d);
}

int FacultyRecord1::getNumAdvisees(){
  return advlist->getSize();
}

//option functions
void FacultyRecord1::option2(){
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


void FacultyRecord1::option4(){
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

void FacultyRecord1::option5(){
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

void FacultyRecord1::option6(){
string listbracket = "[";
string endbracket = "]";
string numberid;
int numberid1;
string adviseeID;
int Line=0;
int addLine=0;

GenLinkedList<int> *advlist = new GenLinkedList<int>;
cout << "enter a faculty ID to print their advisees " << endl;
cin >> adviseeID;
cout << endl;
FacultyFile.open("facultyTable.txt");

if (FacultyFile)
{
  while(getline(FacultyFile, FacultyLine)){
    Line=Line+1;
     FacultyID = FacultyLine.substr(0,1);
    // cout << FacultyID << endl;
     if(FacultyID==adviseeID)
     {
    //   cout << "at line " << Line << "find the faculty" << endl;
     }//end if
  }//end while
}//end if
FacultyFile.close();
//open the file again to read till reach Line with certain faculty
FacultyFile.open("facultyTable.txt");
if (FacultyFile)
{
  while(getline(FacultyFile, FacultyLine)){
   addLine=addLine+1;
   if(addLine==Line){
     for (int i=2; i<=FacultyLine.length(); ++i){
     string O6Character = FacultyLine.substr(i,1);
     //cout << O6Character << endl;
     if (O6Character=="0" || O6Character=="1" || O6Character=="2" || O6Character=="3" || O6Character=="4" || O6Character=="5" || O6Character=="6" || O6Character=="7" || O6Character=="8" || O6Character=="9"){
     numberid=O6Character;
     numberid1=stoi(numberid);
    cout << "numberid1 " << numberid1 << endl;

    //open and read from student class and insert into tree
     StudentFile.open("studentTable.txt");
     if (StudentFile)
     {
       BST<string> *masterStudent = new BST<string>;
       while (getline(StudentFile, StudentLine))
       {
           StudentID = StudentLine.substr(0,1);
           StudentID1 = stoi(StudentID);
           masterStudent->insert(StudentLine,StudentID1);
       }//end while
       masterStudent->returnT(numberid1);
     }//end if student file

     StudentFile.close();

   }//end if

   }// end for

   }//end if
  }//end while
}// end if

}//option 6
