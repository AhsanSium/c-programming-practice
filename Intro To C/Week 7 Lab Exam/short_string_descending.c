#include<stdio.h>
#include<string.h>

char* short_string_ascending(char s[], char t[])
{

   int len = strlen(s);
   char temp = "";

   for(int i = 0; i < len; i++)
   {

       t[i] = s[len -1 -i];
   }

   t[len] = '\0';

   return t;

}



int main()
{
    char s[100];
    char t[100];

    scanf("%s", &s);

    printf("Result:  %s", short_string_ascending(s, t));

    return 0;

}


