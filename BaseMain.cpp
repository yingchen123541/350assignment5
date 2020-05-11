//open and read from two files (student and faculty) and add information into trees
//if those two files don't exist initialize two empty trees
// tree name: masterFaculty, masterStudent
#include "binarytree.cpp"
#include "FacultyRecord1.h"
//#include "Rollback.h"
#include "genstack.cpp"

//#include "StudentRecord.cpp"
//#include "doublelinkedlist.cpp"


using namespace std;

int main(){

  ifstream StudentFile;
  string StudentLine;
  string StudentID;
  int StudentID1;
  string inputStudentID;



  ifstream FacultyFile;
  string FacultyLine;
  string FacultyID;
  int FacultyID1;
  string inputFacultyID;


//output menu information
   for (int i=0; i<1000; i++){
   string userinput;
   cout << endl;
   cout << "Do you want to see the menu? press '0' for no, '1' for yes" << endl;
   cin >> userinput;
   if(userinput == "0"){
     break;
   }
   cout << "Here's the menu: " << endl;
   cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
   cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
   cout << "3. Find and display student information given the students id" << endl;
   cout << "4. Find and display faculty information given the faculty id" << endl;
   cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
   cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
   cout << "7. Add a new student" << endl;
   // add to tree and add to file student txt
   // make changes to original fac txt
   cout << "8. Delete a student given the id" << endl;
    //make changes to original fac txt
   cout << "9. Add a new faculty member" << endl;
   //we have to make additional changes to the original file
   cout << "10. Delete a faculty member given the id." << endl;
   //make changes to original student txt
   cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
   //check if fac exists, then change ID
   cout << "12. Remove an advisee from a faculty member given the ids" << endl;
   //rewrite file
   cout << "13. Rollback" << endl;
   cout << "14. Exit" << endl;
   cout << "enter a number between 1-14 to choose an item from the menu" << endl;

   int choice;
   cin >> choice;

   StudentRecord* printstud = new StudentRecord();
   FacultyRecord1* printfacu = new FacultyRecord1();

   if (choice==1)
   {
     cout << endl;
     cout << "OPTION 1: " << endl;
     printstud -> option1();
    }//end if
   else if (choice==2)
   {
     cout << endl;
     cout << "OPTION 2: " << endl;
     printfacu -> option2();
 }//end else if
   else if (choice==3)
   {
     cout << endl;
     cout << "OPTION 3: " << endl;
     printstud -> option3();

   }//end else if
   else if (choice==4)
   {
     cout << endl;
     cout << "OPTION 4: " << endl;
     printfacu -> option4();
   }//end else if
   else if (choice==5)
   {
     //like given 5, print out 7, Bob, assistant prof, English, [4,5]
     cout << endl;
     cout << "OPTION 5: " << endl;
     printfacu -> option5();
   }//end else if
   else if (choice==6)
   {
     cout << endl;
     cout << "OPTION 6: " << endl;
     printfacu -> option6();

   }//end else if
   else if (choice==7)
   {
     cout << endl;
     cout << "OPTION 7: " << endl;
     printstud -> option7();
     //code
   }//end else if
   else if (choice==8)
   {
     cout << endl;
     cout << "OPTION 8: " << endl;
     printstud -> option8();
     //code
   }//end else if
   else if (choice==9)
   {
     cout << endl;
     cout << "OPTION 9: " << endl;
     printfacu -> option9();
     //code
   }//end else if
   else if (choice==10)
   {
     cout << "Delete a faculty member given the id." << endl;
     cout << endl;
     cout << "OPTION 10: " << endl;
     printfacu -> option10();
     //code
   }//end else if
   else if (choice==11)
   {
     cout << "Change a student’s advisor given the student id and the new faculty id." << endl;
     //code
   }//end else if
   else if(choice==12)
   {
     cout << "Remove an advisee from a faculty member given the ids" << endl;
     //code
   }//end else if
   else if (choice==13)
   {
     cout << "Rollback" << endl;
     //code
   }//end else if
   else if (choice==14)
   {
     cout << "Exit" << endl;
     exit(1);
   }//end else if


 }// end for

































  return 0;

}//end main
