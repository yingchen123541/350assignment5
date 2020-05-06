#include<fstream>
#include "BSTree1.cpp"

//string addStudentTree(){

//open and read from student file

  ifstream StudentFile;
  StudentFile.open("studentTable.txt");
  string StudentLine;
  string StudentID;


  if(!StudentFile)
  {
    cerr << "student file doesn't exist, empty tree" << endl;
    //initialize empty student tree
  //  BSTree1 *masterStudent = new BSTree1(10);
  }//end if
  else if (StudentFile)
  {
    //studentTable successfully opened, add content into masterStudent tree
  //  BSTree1 *masterStudent = new BSTree1(10);
    while (getline(StudentFile, StudentLine))
    {
      for(int z=0; z < 1; z++)
      {
        //only read the first character in each line
           StudentID = StudentLine.substr(z,1);
          cout << StudentLine[z] << endl;

  //  masterStudent->insert(StudentLine);
    }// end while
  }//end else if
  StudentFile.close();

  //return masterStudent;
//}
}
