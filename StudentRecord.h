
#include <iostream>
#include <fstream>

class StudentRecord{
   public:
     StudentRecord();
     StudentRecord(int StudentID1);
     ~StudentRecord();
     std::ifstream StudentFile;
     std::string StudentLine;
     std::string StudentID;
     int StudentID1;
     int totalLine;
//add getters and setters
     std::string m_StudentLine;
     std::string m_StudentID;
     int m_StudentID1;
     int m_totalLine;



     void option1();




};