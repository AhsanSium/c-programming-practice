#include<stdio.h>

long long int findMax(long long n1, long long n2, long long n3)
{
    if (n1 >= n2 && n1 >= n3) return n1;

    else if (n2 >= n1 && n2 >= n3) return n2;

    else return n3;
}

long long int findMax(long long n1, long long n2, long long n3)
{
    if (n1 >= n2 && n1 >= n3) return n1;

    else if (n2 >= n1 && n2 >= n3) return n2;

    else return n3;
}

int main()
{
    int T;
    scanf("%d", &T);

    while( T > 0)
    {
        long long int A,B,C,K;

        scanf("%lld %lld %lld %lld", &A, &B, &C, &K);

        printf("Max is %lld\n", findMax(A,B,C) );

        T--;
    }

    return 0;
}
