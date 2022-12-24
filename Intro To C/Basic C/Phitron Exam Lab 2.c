#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);

    while( n > 0){

        char str[20];

        scanf("%s", str);

        int flag = 1;
        int length = strlen(str);
        //printf("Size = %d", length);

        for(int i = 0; i < length / 2; i++){

            //printf("%c %c", str[i], str[length - i -1]);

            if(str[i] != str[length - i - 1]){
                flag = 0;
                break;
            }
        }

        if(flag == 0){
            printf("Case #1: Not Palindrome\n");
        }
        else if(flag == 1 && length > 7){
            printf("Case #2: %c%d%c\n", str[0], length - 2 ,str[length - 1] );
        }
        else if(length < 7 && length > 0){
            printf("Case #3: %s\n", str);
        }

        n --;
    }

    return 0;
}

