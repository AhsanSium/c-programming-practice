#include<stdio.h>
#include<string.h>

int main()
{
    int t;
    scanf("%d", &t);

    while( t > 0 ){

        char str[50];

        scanf("%s", str);

        int length = strlen(str);

        printf("Length: %d\n", length);

        t --;

    }

    return 0;
}
