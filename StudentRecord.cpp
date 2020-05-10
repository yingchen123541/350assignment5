

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
    BST<string> *masterStudent = new BST<string>;
  }//end if
  else if (StudentFile)
  {
    //studentTable successfully opened, add content into masterStudent tree
    BST<string> *masterStudent = new BST<string>;
    int IDArray[100];
    //BST<string> *masterStudent = new BST<string>;
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

void StudentRecord::option3(){
  cout << "enter a student ID to display student information" << endl;
  cin >> inputStudentID;
  int inputStudentID1;
  inputStudentID1 = stoi(inputStudentID);

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
    bool find;
    find = masterStudent->search(inputStudentID1);
    if(find==true){
    cout << "studentID exist" << endl;
    masterStudent->returnT(inputStudentID1);
    }//end if
    else if (find==false){
      cout << "the studentID you enter is incorrect" << endl;
    }//end else if

  }// end if
    StudentFile.close();
}//end option 3















//add an add functions
//add a delete functions
//print advisor function?
//print all students function
