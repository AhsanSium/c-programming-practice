#include<stdio.h>
#include<math.h>

struct Point
{
    int x;
    int y;
};

double distance (struct Point p, struct Point q)
{
    return sqrt ( pow(q.x - p.x , 2 ) + pow( q.y - p.y , 2) );
}

int main()
{
    struct Point p1, p2;

    printf("\nEnter The Points: \n");

    scanf("%d %d", &p1.x, &p1.y);

    scanf("%d %d", &p2.x, &p2.y);

    printf("The Distance Between them = %.2lf \n", distance(p1, p2));

    return 0;
}
