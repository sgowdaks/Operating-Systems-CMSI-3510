#include <stdio.h>
#include <stdlib.h>

int main ()
{
  struct student_details{
   char name[30];
   char age[10];
   char classYear[10];
   char city[20];
   char major[30];
   char food[30];
};

  struct student_details student;


   printf("What is your name?  ");
   fgets(student.name, sizeof student.name, stdin);

   printf("What is your age?  ");
   fgets(student.age, sizeof student.age, stdin);

   printf("What is your classYear?  ");
   fgets(student.classYear, sizeof student.classYear, stdin);

   printf("What is your favourite city?  ");
   fgets(student.city, sizeof student.city, stdin);

   printf("What is your favourite food?  ");
   fgets(student.food, sizeof student.food, stdin);

   printf("What is your major? ");
   fgets(student.major, sizeof student.major, stdin);
   printf("\n");

   printf("Your name : %s \nage : %s \nclassYear : %s \nFavorite city : %s \nfavorite food : %s \nmajor : %s\n",student.name, student.age, student.classYear, student.city, student.food, student.major );

   return 0;
}

