#include<fstream>
#include "BSTree1.cpp"

string addStudentTree(){

//open and read from student file
  ifstream StudentFile;
  StudentFile.open("studentTable.txt");
  string StudentLine;


  if(!StudentFile)
  {
    cerr << "student file doesn't exist, empty tree" << endl;
    //initialize empty student tree
    BSTree1 *masterStudent = new BSTree1(10);
  }//end if
  else if (StudentFile)
  {
    //studentTable successfully opened, add content into masterStudent tree
    BSTree1 *masterStudent = new BSTree1(10);
    while (getline(StudentFile, StudentLine))
    {
      //for now only print out information line by line
      //maybe we can search through each line and do .contains(studentID) when need to print out information base on ID
      //or should we seperate each line by comma? but how to store in trees? how many tree nodes to use for one student's information?
    cout << StudentLine << endl;
    masterStudent->insert(StudentLine);
    }// end while
  }//end else if
  return masterStudent;
}
