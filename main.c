#define number 300
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct student{
    char first_name[80];
    char last_name[80];
    char student_id[11];
    float avrage_n;
};

void add_student(struct student *sp,int *as);
void add_delete(struct student *sp,int *as);
int search_student(struct student *sp,int *as);
void print_student(struct student *sp,int number_s);
void print_all_student(struct student *sp,int *as);
void save_student(struct student *sp,int *as);
void load_student(struct student *sp,int *as);
void sort_student(struct student *sp,int *as);







int main()
{
    struct student students[number];
    int active_students=0;
    //add_student(students,&active_students);
    //print_student(students,search_student(students,&active_students));
   // char aa[80]="matin";
    //load_student(students,&active_students);
    //print_all_student(students,&active_students);
    //sort_student(students,&active_students);
   // print_all_student(students,&active_students);

    int continue_program=1;
    char user_name[80];
    printf("please enter you name:");
    scanf("%s",user_name);
    printf("hi dear %s :)",user_name);



    while(continue_program==1){
       printf("\n**********************\nplease choose item in the following list:\n1- add student\n2- delete student\n3- View information all student\n4- search student with ID\n5- load student from file\n6- save student information into the file\n7- sort list according to student's average mark\n8- exit\n");


        int choose;
        scanf("%d",&choose);

        switch(choose){

        case 1:
            add_student(students,&active_students);
            break;

        case 2:
            add_delete(students,&active_students);
            break;

        case 3:
            print_all_student(students,&active_students);
            break;

        case 4:
            print_student(students,search_student(students,&active_students));
            break;

        case 5:
            load_student(students,&active_students);
            break;

        case 6:
            save_student(students,&active_students);
            break;

        case 7:
            sort_student(students,&active_students);
            break;

        case 8:
            printf("\n have a good time, hope so see you again :)");
            continue_program=0;
            break;

        default:
            printf("\n **you choose wrong, in fact this item not exist please try another time with more carefully!!");

        }

    }

    return 0;
}

int search_student(struct student *sp,int *as){
    char student_id_s[80];
    printf("please enter ID:");
    scanf("%s",student_id_s);

    for(int i=0;i<(*as);i++){
      if(strcmp(sp[i].student_id,student_id_s)==0){
        return i;
      }
    }


  return -1;

 }



 void sort_student(struct student *sp,int *as){

 struct student temp;
   for(int i=0;i<(*as);i++){
       for(int j=0;j<(*as)-i-1;j++){
           temp=sp[j];
           if(temp.avrage_n<sp[j+1].avrage_n){
            sp[j]=sp[j+1];
            sp[j+1]=temp;
           }
       }
    }
printf("students had successfully sorted \n\n");


 }


void add_student(struct student *sp,int *as){
    printf("please enter first name:");
    scanf("%s",sp[(*as)].first_name);
    printf("please enter last name:");
    scanf("%s",sp[(*as)].last_name);
    printf("please enter ID:");
    scanf("%s",sp[(*as)].student_id);
    printf("please enter avrage:");
    scanf("%f",&sp[(*as)].avrage_n);
    (*as)+=1;
    printf("student successfully added\n\n");

 }

 void save_student(struct student *sp,int *as){

     char file_name[80];
     printf("please enter file name:");
     scanf("%s",file_name);

    FILE *f=fopen(file_name,"w");
    if(f==NULL)
    printf("computer con't open file with this name please run again program");

    fprintf(f,"%d\n",(*as));

    for(int i=0;i<(*as);i++){
    fprintf(f,"%s %s %s %f\n",sp[i].first_name,sp[i].last_name,sp[i].student_id,sp[i].avrage_n);
  }

  fclose(f);

 }

 void load_student(struct student *sp,int *as){
     char file_name[80];
     printf("please enter file name:");
     scanf("%s",file_name);


    FILE *f=fopen(file_name,"r");
    if(f==NULL)
    printf("computer con't open file with this name please run again program");
    int count_s;
    fscanf(f,"%d",&count_s);

    for(int i=0;i<count_s;i++){
    fscanf(f,"%s",sp[(*as)+i].first_name);
    fscanf(f,"%s",sp[(*as)+i].last_name);
    fscanf(f,"%s",sp[(*as)+i].student_id);
    fscanf(f,"%f",&sp[(*as)+i].avrage_n);

     }
    *as=count_s+(*as);
    printf("\n %d student add to your structure:",count_s);
    fclose(f);


 }

 void print_student(struct student *sp,int number_s){

     if (number_s==-1){
       printf("this student not exist");

     }
     else{
      printf("%s %s is student with ID:%s and avrage mark:%f",sp[number_s].first_name,sp[number_s].last_name,sp[number_s].student_id,sp[number_s].avrage_n);
     }

  }

  void print_all_student(struct student *sp,int *as){
    for(int i=0;i<(*as);i++){
      printf("\n %s %s is student with ID:%s and avrage mark:%f",sp[i].first_name,sp[i].last_name,sp[i].student_id,sp[i].avrage_n);
  }

  }

  void add_delete(struct student *sp,int *as){


    int id=search_student(sp,as);



      for(int i=id;i<(*as);i++){
            sp[i]=sp[i+1];
      }

      printf("student deleted\n\n");
      (*as)=(*as)-1;


  }
