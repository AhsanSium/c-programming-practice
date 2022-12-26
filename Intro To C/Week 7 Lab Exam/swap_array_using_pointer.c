#include<stdio.h>

int *swap_two(int arr[],int Q,int n)
{
    int L,R,temp;

    for(int j=1;j<=Q;j++)
    {
         scanf("%d%d",&L,&R);
         int *a=&L;
         int *b=&R;

          temp=arr[*a];
          arr[*a]=arr[*b];
          arr[*b]=temp;

    }

    return arr;

}

int main()
{
    int n, Q;
    int *p;
    scanf("%d",&n);
    int arr[1000];
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&Q);

    p= swap_two(arr,Q,n);
    for(int i=1;i<=n;i++)
    {
       printf("%d ",*(p+i));

    }

    return 0;
}
