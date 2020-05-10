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
     int totalLine;
     std:: string inputFacultyID;
     int inputFacultyID1;
     std:: string O5studentID;
//add getters and setters
     std::string m_FacultyLine;
     std::string m_FacultyID;
     int m_FacultyID1;
     int m_totalLine;



     void option2();
     void option4();
     void option5();




};
