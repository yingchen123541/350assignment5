
#include <iostream>
#include <fstream>

class StudentRecord{
   public:
     StudentRecord();
     StudentRecord(int a, string b, string c, string d, double e, int f);
     ~StudentRecord();
     std::ifstream StudentFile;
     std::string StudentLine;
     std::string StudentID;
     std::string inputStudentID;


//add getters and setters
//helper functions
      void setID(int a);
      int getID();
      void setName(string a);
      string getName();
      void setLevel(string a);
      string getLevel();
      void setMajor(string a);
      string getMajor();
      void setGPA(double a);
      double getGPA();
      void setAdvisor(int a);
      int getAdvisor();
      void option1();
      void option3();
      void deleteStud();

////////////
     std::string m_StudentLine;
     std::string m_StudentID;
     int m_StudentID1;
     int m_totalLine;
     //variables
     int studID;
     string name;
     string level;
     string major;
     double gpa;
     int advisor;
     int StudentID1;
     int totalLine;


};
