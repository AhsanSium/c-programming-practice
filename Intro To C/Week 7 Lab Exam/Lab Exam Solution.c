#include<stdio.h>

int get_sum(int n)
{
    int count = 0,sum = 0, sign = 1;

    for(int i = 1; i <= n; i ++)
    {
        //printf("%d*%d  ", i, sign);

        if(sign == 1){
            sum = sum + i;
        }
        if(sign == -1){
            sum = sum - i;
        }

        count ++;

        if(count >= 3){
            count = 0;
            sign = sign * (-1);
        }
    }

    return sum;

}



int main()
{
    int a;

    scanf("%d", &a);

    printf("%d",get_sum(a));

    return 0;

}

