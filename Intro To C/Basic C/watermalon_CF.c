#include<stdio.h>

int main()
{

    int a = 0;

    scanf("%d", &a);

    if(a == 2){
        printf("NO");
        return 0;
    }

    if( a % 2 == 0){
        printf("YES");
    }
    else{
        printf("NO");
    }

    return 0;
}
