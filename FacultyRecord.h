//#include "binarytree.cpp"
#include <iostream>
#include <fstream>

class FacultyRecord{
   public:
     FacultyRecord();
     FacultyRecord(int FacultyID1);
     ~FacultyRecord();
     std::ifstream FacultyFile;
     std::string FacultyLine;
     std::string FacultyID;
     int FacultyID1;
//add getters and setters
     std::string m_FacultyLine;
     std::string m_FacultyID;
     int m_FacultyID1;



     void option2();




};
