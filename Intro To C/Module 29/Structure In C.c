//#include<stdio.h>
//#include<string.h>
//
//struct Student
//{
//    int roll;
//    char name[50];
//    int age;
//    float weight;
//};
//
//int main()
//{
//    struct Student s1; // s1 = { 12, "Ahsan", 25, 61.3 };
//
//    s1.roll = 12;
//    strcpy( s1.name ,"Ahsan");
//    s1.age = 25;
//    s1.weight = 61.3;
//
//    printf("Student Roll = %d, Name = %s, Age = %d, Weight = %f \n", s1.roll , s1.name, s1.age, s1.weight );
//
//
//    return 0;
//}

//#include<stdio.h>
//
//struct st
//{
//    int x;
//    int ar[5];
//};
//
//int main()
//{
//    printf("%d", sizeof(struct st));
//    return 0;
//}


//#include<stdio.h>
//struct st
//{
//    char x;
//    int ar[6];
//    int a;
//    double b;
//};
//
//int main()
//{
//    printf("%d", sizeof(struct st));
//    return 0;
//}

//# include <stdio.h>
//# include <string.h>
//
//struct Name
//{
//  char str[20];
//};
//
//int main()
//{
//  struct Name st1, st2;
//  strcpy(st1.str,"ProgrammingHero");
//  st2 = st1;
//  st1.str[0] = 'p';
//
//  printf("%s",st2.str);
//
//  return 0;
//}


#include<stdio.h>
struct Course {
    char name[];
    int price;
};

int main()
{
    struct Course c1 ={"C Programming",5000};
    return 0;
}


