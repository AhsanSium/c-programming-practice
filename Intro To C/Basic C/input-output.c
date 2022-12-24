#include<stdio.h>

int main(){

    double a;
    int radius;
    float pi = 3.1416;
    double area;


    printf("Enter a Number: \n" ,a);

    scanf("%lf",&a);

    printf("\n%lf\n\n\n\n\n" ,a);


    printf("Enter the Radius \n");

    scanf("%d", &radius);

    area = pi * radius * radius;

    printf("Area is %lf", area);
}
