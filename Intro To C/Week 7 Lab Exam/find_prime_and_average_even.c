#include<stdio.h>

int prime_num(int n,int arr[])
{
    int *p;
    p=&arr[0];
    int count=0;
    for(int i=0;i<n;i++)
    {
        int flag=0;
        for(int j = 2; j < *p/2; j++)
        {
            if(*p % j == 0)
            {
                flag = 1;
                break;
            }

        }
        if(flag==0)
        {
            count++;
        }
        p++;
    }

    return count;
}

float average_num(int n,int arr[])
{
    int *ptr;
    ptr = &arr[0];
    int even = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        if(*ptr % 2 == 0)
        {
            even ++;
            sum = sum + *ptr;
        }
        ptr++;
    }
    float average = sum / even;
    return average;
}

int main()
{
    int N;
    scanf("%d",&N);
    int arr[100];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Prime numbers: %d\n",prime_num(N,arr));
    printf("Average of all even integers: %.2f\n",average_num(N,arr));

    return 0;
}

