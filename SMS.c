#include <stdio.h>
//#include <conio.h>


struct student{
  char first_name[20];
  char last_name[20];
  int roll_no;
  char Class[10];
  char address[30];
  float per;
};


//beginning of main function--------------------------------------------------------
void main(){
  int choice;
  while(choice != 5 ){
    printf("\t\t\t= = = = STUDENT MANAGEMENT SYSTEM = = = =");
    printf("\n\n\nOptions: \n");
    printf("\t\t\t\t1. Add student record\n");
    printf("\t\t\t\t2. Student records\n");
    printf("\t\t\t\t3. Search student record\n");
    printf("\t\t\t\t4. Delete record\n");
    printf("\t\t\t\t5. Exit\n");
    printf("\t\t\t\t ___________________________________ \n");
    printf("\t\t\t\t");
    scanf("%d",&choice);

  
}
//End of main function-------------------------------------------------------------


