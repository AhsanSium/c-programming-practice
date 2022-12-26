#include<stdio.h>
#include<math.h>

void favoutite_num(int n,int arr[])
{
    int count=0;
    int *p;
    p = &arr[0];

    for(int i = 0; i < n; i++)
    {
        while(*p != 0)
        {
            int digit = *p % 10;
            if(digit == 7)
            {
                count++;
                 break;
            }
            *p = *p/10;
        }

        p++;
    }

    float q = ((float)(n) / 2);

    int result = ceil(q);

    if(count >= result)
    {
        printf("Beautiful\n");
    }

    if(count < result)
    {
        printf("Ugly\n");
    }

}

int main()
{
    int N;
    scanf("%d", &N);

    int arr[N];

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    favoutite_num(N, arr);

    return 0;

}

