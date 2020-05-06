#include<fstream>
#include "BSTree1.cpp"


//function to add faculty information into tree
string addFacultyTree(){

//open and read from faculty file
ifstream FacultyFile;
FacultyFile.open("facultyTable.txt");
string FacultyLine;
string FacultyID;

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
    for(int z=0; z < 1; z++)
    {
      //only read the first character in each line
         FacultyID = FacultyLine.substr(z,1);
        cout << FacultyLine[z] << endl;
}// end for

  //masterFaculty->insert(FacultyLine);
  }// end while

}//end else if


//return masterFaculty;
FacultyFile.close();
}//end add tree
