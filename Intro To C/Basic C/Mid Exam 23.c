#include<stdio.h>
#include<string.h>

int isPresent(char arr[], char target)
{
    int length = strlen(arr);

    for(int i = 0; i < length; i++){
        if( arr[i] == target){
            return 1;
        }
    }

	return -1;
}

int main(){

        char arr[100];

        scanf("%s", arr);

        if(isPresent(arr, '1') == 1 && isPresent(arr, '9') == 1 && isPresent(arr, '7') == 1){
            printf("Yes");
        }
        else{
            printf("No");
        }

//        int test = isPresent(arr, '1');
//
//        printf("\n\n%d\n", test);

        return 0;
}
