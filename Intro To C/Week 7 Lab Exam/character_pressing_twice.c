#include<stdio.h>

void broken_key(char str[],int n)
{
    for(int i=0;i<=n;i++)
    {
        if(i%2==0)
        {
            printf("%c",str[i]);
        }
        else
        {
            printf("%c%c",str[i],str[i]);
        }

    }
}


int main()
{
    char str[100];
    scanf("%s",str);

    int length = strlen(str);

    broken_key(str,length);

    return 0;
}

