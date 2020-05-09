#include "binarytree.cpp"
#include <iostream>
#include <fstream>

class StudentRecord{
   public:
     StudentRecord();
     StudentRecord(int StudentID1);
     ~StudentRecord();
     ifstream StudentFile;
     string StudentLine;
     string StudentID;
     int StudentID1;
//add getters and setters
     string m_StudentLine;
     string m_StudentID;
     int m_StudentID1;



     void option1();




};
