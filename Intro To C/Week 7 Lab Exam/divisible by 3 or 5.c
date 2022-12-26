#include<stdio.h>

int is_divisible_by_3(int num)
{
    if(num % 3 == 0){
        return 1;
    }else{
        return -1;
    }
}

int is_divisible_by_5(int num)
{
    if(num % 5 == 0){
        return 1;
    }else{
        return -1;
    }

}

int main()
{
    int N;
    scanf("%d",&N);

    int arr[N];
    int sum = 0;

    for(int i = 0; i< N; i++)
    {
        scanf("%d", &arr[i]);

        if(is_divisible_by_3(arr[i]) && is_divisible_by_5(arr[i]) == 1){
            sum ++;
        }
        else if(is_divisible_by_3(arr[i]) == 1 && is_divisible_by_5(arr[i]) == -1){
            sum ++;
        }
        else if(arr[i] == -1 && is_divisible_by_5(arr[i]) == 1){
            sum ++;
        }
        else{
            sum = -1;
        }
    }

    printf("%d", sum);

    return 0;
}

