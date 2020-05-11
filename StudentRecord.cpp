

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
    bool findStudent;
    findStudent = masterStudent->search(inputStudentID1);
    if(findStudent==true){
    cout << "studentID exist" << endl;
    masterStudent->returnT(inputStudentID1);
    }//end if
    else if (findStudent==false){
      cout << "the studentID you enter is incorrect" << endl;
    }//end else if

  }// end if
    StudentFile.close();
}//end option 3


void StudentRecord::option8(){
  cout << "enter a student ID to delete student information" << endl;
  cin >> inputStudentID;
  ofstream OutputFile;
  int inputStudentID1;
  inputStudentID1 = stoi(inputStudentID);

  StudentFile.open("studentTable.txt");
  OutputFile.open("studentTable1.txt");
  if (StudentFile)
  {
    BST<string> *masterStudent = new BST<string>;
    cout << "delete student with ID " << inputStudentID1 << endl;
    while (getline(StudentFile, StudentLine))
    {
        StudentID = StudentLine.substr(0,1);
        StudentID1 = stoi(StudentID);
        masterStudent->insert(StudentLine,StudentID1);
        if(StudentID1!=inputStudentID1){
          OutputFile << StudentLine <<  endl;

        }//end if
        else if (StudentID1!=inputStudentID1)
        {
          cout << "delete student" << endl;
        }//end else if

    }//end while

  }// end if
    StudentFile.close();
    OutputFile.close();

    StudentFile.open("studentTable1.txt");
    OutputFile.open("studentTable.txt");

    if (StudentFile)
    {
      while (getline(StudentFile, StudentLine)){
          OutputFile << StudentLine <<  endl;
      }// end while

    }// end if

//making changes to the faculty list
//imm comment it out but sos pls
ifstream FacultyFile;
 FacultyFile.open("facultyTable.txt");
 OutputFile.open("fTable1.txt");
 string FacultyLine;
string O6Character;
int O6Character1;
int numberid1;
BST<string> *masterStudent = new BST<string>;
 if (FacultyFile)
 {

   cout << "deleting student with ID from faculty list " << endl;
  while (getline(FacultyFile, FacultyLine))
  {
    //   if(addLine==Line){
        // if(addLine==Line){

            O6Character = FacultyLine.substr(0,1);
            O6Character1=stoi(O6Character);
           if (O6Character1 == inputStudentID1){
          numberid1=O6Character1;

          cout << "numberid1 " << numberid1 << endl;
         for (int i=2; i<=FacultyLine.length(); ++i){
         }

       masterStudent->insert(StudentLine,StudentID1);
       if(StudentID1!=inputStudentID1){
         OutputFile << StudentLine <<  endl;

       }//end if
       else if (StudentID1!=inputStudentID1)
       {
         cout << "delete student" << endl;
       }//end else if

   }//end while


// //should cahnge to faculty file
 StudentFile.close();
 OutputFile.close();

 StudentFile.open("studentTable1.txt");
 OutputFile.open("studentTable.txt");

 if (StudentFile)
 {
   while (getline(StudentFile, StudentLine)){
       OutputFile << StudentLine <<  endl;
   }// end while
 }// end if











/////////////////////////////////////////////////


    OutputFile.close();
    StudentFile.close();



}
}
}//end option 8


  void StudentRecord::option7(){
    ofstream OutputFile1;
    OutputFile1.open("studentTable.txt", ios::app);
  //add a new student into tree and write to the file
  string studentid;
  string studentName;
  string studentLevel;
  string Major;
  string studentGPA;
  string studentAdv;
  //string comma=",";
  cout << "confirm student ID" << endl;
  cin >> studentid;
  cout << "enter student name" << endl;
  cin >> studentName;
  cout << "enter student level" << endl;
  cin >> studentLevel;
  cout << "enter student major" << endl;
  cin >> Major;
  cout << "enter student gpa" << endl;
  cin >> studentGPA;
  cout << "enter student advisor ID" << endl;
  cin >> studentAdv;

   OutputFile1 << studentid << " ";
   //OutputFile1 << comma;
   OutputFile1 << studentName << " ";
   //OutputFile1 << comma;
   OutputFile1 << studentLevel << " ";
  // OutputFile1 << comma;
   OutputFile1 << Major << " ";
  // OutputFile1 << comma;
   OutputFile1 << studentGPA << " ";
  // OutputFile1 << comma;
   OutputFile1 << studentAdv << " " << "\n";

   OutputFile1.close();

   StudentFile.open("studentTable.txt");
   if (StudentFile)
   {
     //add new students into tree
     BST<string> *masterStudent = new BST<string>;
     while (getline(StudentFile, StudentLine))
     {
       StudentID = StudentLine.substr(0,1);
       StudentID1 = stoi(StudentID);
       masterStudent->insert(StudentLine,StudentID1);
     }// end while
   }// end if

}//end option 7

//ask lucas
void StudentRecord::option11(){
  string O11StudentID;
  string O11FacultyID;
  int NumLine=0;
  int findline;
  string sCharacter;
  //Change a student’s advisor given the student id and the new faculty id.
  cout << "enter student ID" << endl;
  cin >> O11StudentID;
  cout << "enter new faculty ID" << endl;
  cin >> O11FacultyID;

  ofstream OutputFile3;
  OutputFile3.open("studentTable4.txt", ios::app);

  StudentFile.open("studentTable.txt");
  if (StudentFile)
  {
    while (getline(StudentFile, StudentLine))
    {

      NumLine=NumLine+1;
      StudentID = StudentLine.substr(0,1);
      StudentID1 = stoi(StudentID);
      if(StudentID!=O11StudentID){
      OutputFile3 << StudentLine << endl;

    }
      else if(StudentID==O11StudentID)
      {
            cout << "find the student at line " << NumLine << endl;
            findline= NumLine;
            for (int i=0; i<StudentLine.length()-2; ++i){
               sCharacter = StudentLine.substr(i,1);
               if(StudentID==O11StudentID){
              OutputFile3 << sCharacter;
            }
            }//end for
            OutputFile3 << " " << O11FacultyID << '\n';

          }//end else if




}//end while
}//end if

}//end option11












//add an add functions
//add a delete functions
//print advisor function?
//print all students function
