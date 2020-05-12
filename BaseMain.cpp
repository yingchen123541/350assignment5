/** BaseMain.cpp
* Name1: Yuki Chen
* Student ID1: 2320235
* Email1: yingchen@chapman.edu
* Name2: Nidhi Vedantam
* Student ID2: 2328859
* Email2: vedantam@chapman.edu
* Assignment5
* purpose: simulate student and faculty database
//open and read from two files (student and faculty) and add information into trees
//also use a stack to allow the user to undo actions
* get input from user to make edit or access student + faculty trees
* output results
* Date: May 12, 2020
*/

//if those two files don't exist initialize two empty trees
// tree name: masterFaculty, masterStudent
#include "binarytree.cpp"
#include "FacultyRecord1.h"
//#include "Rollback.h"
#include "genstack.cpp"
#include "StackEx.h"



using namespace std;
//main class
int main(){

  ifstream StudentFile;
  string StudentLine;
  string StudentID;
  int StudentID1;
  string inputStudentID;
//creating a stack for rolllback option
   genstack<char> rbstack;
  char addS = '0';
  char delS = '1';
  char addF = '2';
  char delF = '3';
  // 0 = Add student , 1 = delete student
  // 2 = add faculty, 3 = delete faculty


  ifstream FacultyFile;
  string FacultyLine;
  string FacultyID;
  int FacultyID1;
  string inputFacultyID;
//create rollback object which is a Stack

//output menu information
   for (int i=0; i<1000; i++){
   string userinput;
   cout << endl;
   cout << "Do you want to see the menu? press '0' for no, '1' for yes" << endl;
   cin >> userinput;
   if(userinput == "0"){
     break;
   }
   //printing menu options for the user
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
//wouldn't all students already have faculty advisor
   cout << "10. Delete a faculty member given the id." << endl;
   //make changes to original student txt
   cout << "11. Change a student’s advisor given the student id and the new faculty id." << endl;
   //check if fac exists, then change ID
   cout << "12. Remove an advisee from a faculty member given the ids" << endl;
   //rewrite file
   cout << "13. Rollback" << endl;
   //simulates an undo but not for options 11 + 12
   cout << "14. Exit" << endl;
   cout << "enter a number between 1-14 to choose an item from the menu" << endl;

   int choice;
   cin >> choice;
//making an object from student + fac class
   StudentRecord* printstud = new StudentRecord();
   FacultyRecord1* printfacu = new FacultyRecord1();



//based on user input will pick an option from the menu
//to display student database
   if (choice==1)
   {
     cout << endl;
     cout << "OPTION 1: " << endl;
     printstud -> option1();
    }//end if
  //to display fac database
   else if (choice==2)
   {
     cout << endl;
     cout << "OPTION 2: " << endl;
     printfacu -> option2();
 }//end else if
 //to find a student based on their ID
   else if (choice==3)
   {
     cout << endl;
     cout << "OPTION 3: " << endl;
     printstud -> option3();

   }//end else if
   //to find a fac based on their ID
   else if (choice==4)
   {
     cout << endl;
     cout << "OPTION 4: " << endl;
     printfacu -> option4();
   }//end else if
   //printing fac advisor based on stud ID
   else if (choice==5)
   {
     //like given 5, print out 7, Bob, assistant prof, English, [4,5]
     cout << endl;
     cout << "OPTION 5: " << endl;
     printfacu -> option5();
   }//end else if
   //printing student info based on fac ID
   else if (choice==6)
   {
      cout << endl;
      cout << "OPTION 6: " << endl;
      printfacu -> option6();
   }//end else if
   //adding a new student
   else if (choice==7)
   {
     cout << endl;
    cout << "OPTION 7: pushing onto the stack.." << endl;
    //cout << rbstack.currentsize() << endl;
//pushing onto the stack an undo-able action has occured
   rbstack.push(addS);
    cout << "stack size:" << rbstack.currentsize() << endl;
    printstud -> option7();
  //  printstud -> option7();


   }//end else if
   //delete a student based on ID
   else if (choice==8)
   {
     cout << endl;
     cout << "OPTION 8: " << endl;
    rbstack.push(delS);
    cout << "stack size:" << rbstack.currentsize() << endl;
     printstud -> option8();


     //code
   }//end else if
   //add a new fac member based on iD
   else if (choice==9)
   {
     cout << endl;
    rbstack.push(addF);
     cout << "stack size:" << rbstack.currentsize() << endl;
     cout << "OPTION 9: " << endl;
     printfacu -> option9();
     //code
   }//end else if
   //delete a new fac member based on ID
   else if (choice==10)
   {
    cout << "Delete a faculty member given the id." << endl;
     cout << endl;
    rbstack.push(delF);
    cout << "stack size:" << rbstack.currentsize() << endl;
     cout << "OPTION 10: " << endl;
     printfacu -> option10();
     //rollbackobject.setAddFac(true);
    //add to stack rollback.insert
     //code
   }//end else if
   //change student advisor
   else if (choice==11)
   {
     cout << endl;
     cout << "OPTION 11: " << endl;
     printstud -> option11();
     //code
   }//end else if
   //remove an advisee
   else if(choice==12)
   {
     cout << endl;
     cout << "OPTION 12: ";
     printfacu -> option12();

   }//end else if
   //rollback class -- only works for options 7-10
   else if (choice==13)
   {
     cout << "Rollback... " << endl;
    if (rbstack.top() == '0'){
      int inp;
      cout << "Do you wish to delete the recently added student? (0- no, 1-yes)" << endl;
      cin >> inp;
      if(inp == 1){
        cout << "popping previous action from stack." << endl;
        //removing action from the stack, so allows user to undo even more
        rbstack.pop();
        cout << "stack size is now: " << rbstack.currentsize() << endl;
        cout << "removing students from database... to confirm ";
        printstud -> option8();
       }
       //if user wants to add recently deelted stud
     }else if (rbstack.top() == '1'){
           int inp;
           cout << "Do you wish to add the recently deleted student? (0- no, 1-yes)" << endl;
           cin >> inp;
           if(inp == 1){
             rbstack.pop();
             cout << "stack size is now: " << rbstack.currentsize() << endl;
             cout << "adding student back to database... to confirm ";
             printstud -> option7();
            }
            //if user wish to delete the recently added faculty
          }else if (rbstack.top() == '2'){
                int inp;
                cout << "Do you wish to delete the recently added faculty? (0- no, 1-yes)" << endl;
                cin >> inp;
                if(inp == 1){
                  rbstack.pop();
                  cout << "stack size is now: " << rbstack.currentsize() << endl;
                  cout << "deleting faculty from database... to confirm ";
                  printfacu -> option10();
                 }
                 //if user wish to add the recently deleted faculty
           }else if (rbstack.top() == '3'){
                 int inp;
                 cout << "Do you wish to add the recently deleted faculty? (0- no, 1-yes)" << endl;
                 cin >> inp;
                 if(inp == 1){
                   rbstack.pop();
                   cout << "stack size is now: " << rbstack.currentsize() << endl;
                   cout << "adding faculty from database... to confirm ";
                   printfacu -> option9();
                  }
                  //stack is empty, all actions have been undone or there are no actions yet
            }else if (rbstack.isEmpty()){
              cout << "there are no actions to undo.." << endl;
            }

     //code
   }//end else if
   //exit
   else if (choice==14)
   {
     cout << "Exit" << endl;
     exit(1);
   }//end else if


 }// end for

































  return 0;

}//end main
