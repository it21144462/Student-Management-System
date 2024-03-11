#include <stdio.h>
//#include <conio.h>

void addstudent();
void studentrecord();
void searchstudent();
void deletestudent();
void clearScreen();
void backToMain();
void displayDots();

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

    switch(choice){
      case 1:  
              clearScreen();
              addstudent();
              clearScreen();
              break;
      case 2:
              clearScreen();
              studentrecord(); 
              backToMain();
              clearScreen();
              break;
      case 3:
              clearScreen();
              searchstudent();
              backToMain();
              clearScreen();
              break;
      case 4:
              clearScreen();
              deletestudent();
              backToMain();
              clearScreen();
              break;
      case 5:
              clearScreen();
                printf("Program Terminated - Thank you for using the system");
                exit(0);
      
      default:                      
              clearScreen();
              printf("\t\t\tInvalid Number ======>>> \n\n");
              printf("\t\t\tPlease Enter a Valid Number \n\n");
              backToMain();
              clearScreen();
              break;
    }
  }
}
//End of main function-------------------------------------------------------------




//function to add records-------------------------------------
void addstudent(){
char newRecord;
FILE *fp;
struct student stu;

  do{
    clearScreen();
    printf("\t\t\t\t= = = = ADD STUDENT RECORD = = = =\n");
    fp = fopen("student_records.txt","a");

    printf("\n\t\t\tEnter the first name  : ");
    scanf("%s",&stu.first_name);
    printf("\t\t\tEnter the last name   : ");
    scanf("%s",&stu.last_name);
    printf("\t\t\tEnter the Enroll number : ");
    scanf("%d",&stu.roll_no);
    printf("\t\t\tEnter the class       : ");
    scanf("%s",&stu.Class);
    printf("\t\t\tEnter the address     : ");
    scanf("%s",&stu.address);
    printf("\t\t\tEnter the Attendence as a percentage  : ");
    scanf("%f",&stu.per);
    printf("\t\t\t\t ___________________________________ \n");

    if (fp == NULL){
      fprintf(stderr,"Error in opening file\n");
    }else{
      // fwrite(&stu,sizeof(stu),1,fp);
      // fclose(fp);
      printf("\n\t\t\tRecord added successfully\n\n");
    }

    fwrite(&stu,sizeof(stu),1,fp);
    fclose(fp);

    printf("\t\t\tDo you want to add New Record (y/n) : ");
    scanf("%s",&newRecord);

  }while(newRecord == 'y' || newRecord == 'Y');

}

//function to display records-------------------------------------
void studentrecord(){
  FILE *fp;
  struct student stu;
  fp = fopen("student_records.txt","r");
  printf("\t\t\t\t= = = = STUDENT RECORDS = = = =\n");

  if (fp == NULL){
    fprintf(stderr,"\t\t\t\tError in opening file\n");
  }else{
    printf("\n\t\t\t\tRecords\n");
    printf("\t\t\t\t_____________________________ \n\n");
  }

  while(fread(&stu,sizeof(struct student),1,fp)){
    printf("\n\t\t\t\tStudent name : %s %s",stu.first_name,stu.last_name);
    printf("\n\t\t\t\tEnroll number : %d",stu.roll_no);
    printf("\n\t\t\t\tClass       : %s",stu.Class);
    printf("\n\t\t\t\tAddress     : %s",stu.address);
    printf("\n\t\t\t\tAttendence Percentage  : %.2f",stu.per);
    printf("\n\t\t\t\t_____________________________ \n");
  }
  fclose(fp);
  return -1;
}

//function to search records-------------------------------------
void searchstudent(){
  FILE *fp;
  struct student stu;
  int roll_no,matchFound=0;
  
  fp = fopen("student_records.txt","r");
  
  printf("\t\t\t\t= = = = SEARCH STUDENT RECORDS = = = =\n");
  printf("\n\t\t\tEnter the Enroll number to search : ");
  scanf("%d",&roll_no);

  while(fread(&stu,sizeof(struct student),1,fp)){
   if(stu.roll_no == roll_no){
     matchFound = 1; // use to catch the matching pair availability
     printf("\n\t\t\t\tStudent name : %s %s",stu.first_name,stu.last_name);
     printf("\n\t\t\t\tEnroll number : %d",stu.roll_no);
     printf("\n\t\t\t\tClass       : %s",stu.Class);
     printf("\n\t\t\t\tAddress     : %s",stu.address);
     printf("\n\t\t\t\tAttendence Percentage  : %.2f",stu.per);
     printf("\n\t\t\t\t_____________________________ \n");
   } 
  }
  // if(matchFound != 1){
  //   printf("\t\t\t\tRecord not found\n");
  // }
  //both can be used but below one is more accurate

  //display message if the seach record is not found
  if(!matchFound){ 
    //this !matchFound is same as if(matchFound == 0), compare if value is 0 or not
    printf("\n\t\t\t\tRecord not found\n");
  }
  
  fclose(fp);
  return -1;
}

//function to delete records-------------------------------------
void deletestudent(){
  FILE *fp, *fp1;
  struct student stu;
  int roll_no,matchFound=0;

  fp = fopen("student_records.txt","r");// txt file currently data is stored
  fp1 = fopen("temp_student_records.txt","w"); // txt file use to temperory store the data

  printf("\t\t\t\t= = = = DELETE STUDENT RECORDS = = = =\n\n\n");
  printf("\t\t\tEnter the Enroll number to delete : ");
  scanf("%d",&roll_no);
  
  if (fp == NULL){
    fprintf(stderr,"\t\t\t\tError in opening file\n");
  }
  
  while(fread(&stu,sizeof(struct student),1,fp)){
     if(stu.roll_no == roll_no){
       matchFound = 1; // use to catch the matching pair availability
     } else{
       fwrite(&stu,sizeof(struct student),1,fp1);
     }
   }
  fclose(fp);//closing the txt files after editing
  fclose(fp1);

  if(matchFound){
    remove("student_records.txt");
    rename("temp_student_records.txt","student_records.txt");
    printf("\n\t\t\t\tRecord deleted successfully\n");
  }
  if(!matchFound){
    printf("\n\t\t\t\tRecord not found\n");
  }
  
}

//function to clear screen-------------------------------------
void clearScreen() {
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix-like systems (Linux, macOS)
#endif
}

//function to get back to main menu-------------------------------------
void backToMain() {
    char keyToMenue;
    printf("\n\t\t\tProceed Back to Main (y/Y) : ");
    scanf("%s",&keyToMenue);

  if(keyToMenue == 'y' || keyToMenue == 'Y'){
    displayDots();
    return -1;   // Signal to leave the current screen
  }else {
    displayDots();
    return 0;   // Signal to stay in the current screen
  }
  
}

//function to display waiting time-------------------------------------
void displayDots() {
    printf("\n\t\t\t\t Waiting");
    fflush(stdout);  // Flush the output buffer to ensure immediate display

    // Sleep for 300 milliseconds
    usleep(300000);
    printf(".");
    fflush(stdout);
    usleep(300000);
    printf(".");
    fflush(stdout);
    usleep(300000);
    printf(".");
    fflush(stdout);
    usleep(300000);
    printf(".");
    fflush(stdout);
    usleep(900000);
    printf("\t\tBack to menue");
    printf(".\n");
    usleep(900000);
}