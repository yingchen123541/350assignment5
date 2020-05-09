#include<fstream>
#include "binarytree.h"

///same as student
// add advisees
//remove a
//print advisees
//these three methods, u must use a list. we make a list.


//function to add faculty information into tree
//string addFacultyTree(){

//open and read from faculty file
ifstream FacultyFile;
FacultyFile.open("facultyTable.txt");
string FacultyLine;
string FacultyID;
int FacultyID1;

if(!FacultyFile)
{
  cerr << "faculty file doesn't exist, empty tree" << endl;
  //initialize empty faculty tree

}//end if
else if (FacultyFile)
{
  //facultyTable successfully opened, add content into masterFaculty tree
  while (getline(FacultyFile, FacultyLine))
  {
    for(int z=0; z < 1; z++)
    {
      //only read the first character in each line
         FacultyID = FacultyLine.substr(z,1);
         FacultyID1 = stoi(FacultyID);
        cout << FacultyLine[z] << endl;

        YukiBSTree1 *masterFaculty = new YukiBSTree1;
        masterFaculty->insert(FacultyID1);
}// end for


  }// end while
FacultyFile.close();
}//end else if


//return masterFaculty;

//}//end add tree
