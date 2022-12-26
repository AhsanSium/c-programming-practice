#include<stdio.h>

int sum_of_odd_or_even(int N, int arr[])
{
   int sum = 0;

   for(int i = 0; i < N; i++)
   {
       if(arr[i] % 2 == 0 && (i+1) % 2 == 0)
       {
           sum = sum + (i + 1) + arr[i];
       }

       if(arr[i] % 2 != 0 && (i+1) % 2 != 0)
       {
           sum = sum + (i + 1) + arr[i];
       }
   }

   return sum;
}

int main()
{
    int N;
    scanf("%d",&N);

    int arr[N];

    for(int i = 0; i< N; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("%d", sum_of_odd_or_even(N, arr));

    return 0;
}

