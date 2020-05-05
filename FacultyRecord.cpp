#include<fstream>
#include "BSTree1.cpp"

//function to add faculty information into tree
string addFacultyTree(){

//open and read from faculty file
ifstream FacultyFile;
FacultyFile.open("facultyTable.txt");
string FacultyLine;

if(!FacultyFile)
{
  cerr << "faculty file doesn't exist, empty tree" << endl;
  //initialize empty faculty tree
  BSTree1 *masterFaculty = new BSTree1(10);
}//end if
else if (FacultyFile)
{
  //facultyTable successfully opened, add content into masterFaculty tree
  BSTree1 *masterFaculty = new BSTree1(10);
  while (getline(FacultyFile, FacultyLine))
  {
    //for now only print out information line by line
    //maybe we can search through each line and do .contains(studentID) when need to print out information base on ID
    //or should we seperate each line by comma? but how to store in trees? how many tree nodes to use for one faculty's information?
  cout << FacultyLine << endl;
  masterFaculty->insert(FacultyLine);
  }// end while

}//end else if

return masterFaculty;
}//end add tree
