#include<stdio.h>

int main()
{
    int a, solution;

    scanf("%d", &a);

    if(a % 5 == 0){
        solution = a / 5;
    }
    else{
        solution = (a / 5) + 1;
    }

    // (a % 5 !=0) => 0 for True => 1
    // solution = (a / 5) + (a % 5 != 0)

    printf("%d", solution);

    return 0;
}
