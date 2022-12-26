#include<stdio.h>

int get_conclusive_even(N)
{
    for(int j=1;j<=N;j++)
    {
        if(j%2==0 && (j+j+2+j+4+j+6)==N)
        {
            printf("%d %d %d %d\n",j,j+2,j+4,j+6);
        }
    }

}

int main()
{
    int T, N;
    scanf("%d",&T);

    for(int i=0;i<T;i++)
    {
        scanf("%d",&N);
        get_conclusive_even(N);
    }

    return 0;
}

