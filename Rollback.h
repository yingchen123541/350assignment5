#include "StudentRecord.h"
#include "FacultyRecord1.h"
//keep track of actions and User input
class Rollback{
public:
  //constructors
  Rollback();
  Rollback(int d);
  Rollback(Faculty d);
  Rollback(Student d);
  ~Rollback();
  //helper functions
  void setAddFac();
  bool getAddFac();

  void setDeleteFac();
  bool getDeleteFac();

  void setAddStud();
  bool getAddStud();

  void setDeleteFac();
  bool getDeleteFac();

  int getID();
  Student getStud();
  Faculty getFac();
  //variables

  bool isFacAdd;
  bool isFacDelete;
  bool isStudAdd;
  bool isStudDelete;
  int id;
  StudentRecord stud;
  FacultyRecord1 fac;

};

//default constructor
Rollback::Rollback(){
  isFacAdd = false;
  isFacDelete = false;
  isStudDelete = false;
  isStudAdd = false;
}

//overloaded constructor
Rollback::Rollback(int d){
  isFacAddt = false;
  isFacDelete = false;
  isStudDelete = false;
  isStudAdd = false;
  id = d;
}

Rollback::Rollback(FacultyRecord1 d){
  isFacAddt = false;
  isFacDelete = false;
  isStudDelete = false;
  isStudAdd = false;
  id = -1;
  fac = d;
}

Rollback::Rollback(StudentRecord d){
  isFacInsert = false;
  isFacDelete = false;
  isStudDelete = false;
  isStudInsert = false;
  id = -1;
  stud = d;
}

//destructor
Rollback::~Rollback(){

}

//every other function
//returns true if fucntion was returned
void Rollback::setDeleteFac(){
  isFacDelete = true;
}

bool Rollback::getDeleteFac(){
  return isFacDelete;
}

void Rollback::setAddFac(){
  isFacAdd = true;
}

bool Rollback::getAddFac(){
  return isFacAdd;
}

void Rollback::setDeleteStud(){
  isStudDelete = true;
}

bool Rollback::getDeleteStud(){
  return isStudDelete;
}

void Rollback::setAddStud(){
  isStudAdd = true;
}

bool Rollback::getAddStud(){
  return isStudAdd;
}

int Rollback::getID(){
  return id;
}

Student Rollback::getStudent(){
  return stud;
}

Faculty Rollback::getFaculty(){
  return fac;
}
