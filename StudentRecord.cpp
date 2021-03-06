/** StudentRecord.cpp
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: define variables used in studentRecord.cpp
* Date: May 12, 2020
*/

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
//destructor
StudentRecord::~StudentRecord()
{

}

//access + modifers
void StudentRecord::setID(int a){
  studID = a;
}
//getter and setter
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
  //convert string to int
  inputStudentID1 = stoi(inputStudentID);

  StudentFile.open("studentTable.txt");
  if (StudentFile)
  {
    //initialize tree
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
      //find the student Id
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
//read from a file then output to another file
  StudentFile.open("studentTable.txt");
  OutputFile.open("studentTable1.txt");
  if (StudentFile)
  {
    BST<string> *masterStudent = new BST<string>;
    cout << "delete student with ID " << inputStudentID1 << endl;
    while (getline(StudentFile, StudentLine))
    {
      //read in the first character as ID
        StudentID = StudentLine.substr(0,1);
        StudentID1 = stoi(StudentID);
        //insert information into tree
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
      //output to a file
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
//making changes to faculty file when change in student file
            O6Character = FacultyLine.substr(0,1);
            O6Character1=stoi(O6Character);
           if (O6Character1 == inputStudentID1){
          numberid1=O6Character1;

          cout << "numberid1 " << numberid1 << endl;
         for (int i=2; i<=FacultyLine.length(); ++i){
         }
//insert into tree
       masterStudent->insert(StudentLine,StudentID1);
       if(StudentID1!=inputStudentID1){
         OutputFile << StudentLine <<  endl;

       }//end if
       else if (StudentID1!=inputStudentID1)
       {
      //   cout << "delete student" << endl;
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

    OutputFile.close();
    StudentFile.close();
    //
    // ifstream temFile;
    // string temLine;
    // string newF;
    // int l;
    // int l1;
    // temFile.open("facultyTable.txt");
    // if (temFile)
    // {
    //   while (getline(temFile, temLine))
    //   {
    //     l=l+1;
    //       for(int i=2; i<=temLine.length(); ++i){
    //          newF = temLine.substr(i,1);
    //          if(newF==inputStudentID){
    //            l=l1;
    //            cout << "find advisee at line " << l1 << endl;
    //            cout << newF << endl;
    //          }
    //        }//end for
    //   }// end while
    // //  cout << newF << endl;
    // }//end if



}
}
}//end option 8


  void StudentRecord::option7(){
    ifstream FacultyFile;
    ofstream OutputFile1;
    OutputFile1.open("studentTable.txt", ios::app);
  //add a new student into tree and write to the file
  string studentid;
  string studentName;
  string studentLevel;
  string Major;
  string studentGPA;
  string studentAdv;
  string StudentID;
  int StudentID1;
  //string comma=",";
  //get input from user
  cout << "enter student ID" << endl;
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

     //initialize tree
     BST<string> *masterStudent = new BST<string>;
     while (getline(StudentFile, StudentLine))
     {
       StudentID = StudentLine.substr(0,1);
       StudentID1 = stoi(StudentID);
       masterStudent->insert(StudentLine,StudentID1);
     }// end while
   }// end if
 //   FacultyFile.open("facultyTable.txt");
 //   int Ll=0;
 //   int Ll1=0;
 //   if(FacultyFile){
 //   while (getline(FacultyFile, FacultyLine))
 //   {
 //     Ll=Ll+1;
 //     FacultyID = FacultyLine.substr(0,1);
 //     FacultyID1 = stoi(FacultyID);
 //     if(studentAdv==FacultyID){
 //       cout << "faculty exist at line " << Ll << endl;
 //       Ll=Ll1;
 //     }//end if
 //   }//end while
 // }//end if
 // FacultyFile.close();
 //
 // FacultyFile.open("facultyTable.txt");
 //
 // if (FacultyFile)
 // {
 //   while(getline(FacultyFile, FacultyLine)){
 //    int adddLine=adddLine+1;
 //    if(adddLine==Ll1){
 //
 //    }//end if
 //
 //   }//end while
 // }//end if
 //
 //
 //
 //


}//end option 7


void StudentRecord::option11(){
  //initialize tree
  BST<string> *masterStudent = new BST<string>;
  string O11StudentID;
  int O11StudentID1;
  string O11FacultyID;
  int NumLine=0;
  int findline;
  string sCharacter;

  //Change a student’s advisor given the student id and the new faculty id.
  //get input from user
  cout << "enter student ID" << endl;
  cin >> O11StudentID;
  cout << "enter new faculty ID" << endl;
  cin >> O11FacultyID;


  ofstream OutputFile3;
  OutputFile3.open("studentTable4.txt");
  int i=0;
  StudentFile.open("studentTable.txt");
  if (StudentFile)
  {
    //print 7 times cause there are 7 lines in file
   while (i<6)
   {
     i=i+1;
     getline(StudentFile, StudentLine);
      NumLine=NumLine+1;
      StudentID = StudentLine.substr(0,1);
      //convert string to int
      StudentID1 = stoi(StudentID);
      if(StudentID!=O11StudentID){
      OutputFile3 << StudentLine << endl;

    }
      else if(StudentID==O11StudentID)
      {
      //  O11StudentID1=stoi(O11StudentID);
            cout << "find the student at line " << NumLine << endl;
            findline= NumLine;
            //don't read in the last two character
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


StudentFile.close();
OutputFile3.close();

StudentFile.open("studentTable4.txt");
OutputFile3.open("studentTable.txt");

if (StudentFile){
  //read all lines then outpue to a file
  while (getline(StudentFile, StudentLine)){
    OutputFile3 << StudentLine << endl;
  }//end while
}//end if

StudentFile.close();
OutputFile3.close();


}
