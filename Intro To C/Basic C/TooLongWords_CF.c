#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d", &n);

    while(n >= 0){

        char name[110];

        fgets(name, sizeof(name), stdin);

        int l = strlen(name) - 1;


        if(l > 10){
            // Abbreviate
            printf("%c%d%c\n", name[0], l-2, name[l-1]);
        }
        else{
            // Print
            puts(name);

        }

        n --;
    }

}
