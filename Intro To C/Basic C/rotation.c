#include<bits/stdc++.h>
#include<graphics.h>
#define PI acos(-1)
using namespace std;

void line()
{
    double x1,x2,y1,y2,x4,y4,angle=0,ang;
    cout<<"Enter Line Coordinate\n";
    cin>>x1>>y1>>x2>>y2;

    line(x1,y1,x2,y2);
    cout<<"Enter Rotation Angal\n";

    cin>>ang;

    angle=(ang*3.14)/180;
    setcolor(RED);
    x4=x2-(((x2-x1)*cos(angle))-((y2-y1)+sin(angle)));
    y4=y2-(((x2-x1)*sin(angle))+((y2-y1)*cos(angle)));

    line(x2,y2,x4,y4);
    setcolor(RED);

    getch();
    closegraph();
}
void rectangle()
{
    double x1,x2,y1,y2,x4,y4,angle,a;
    cout<<"Enter Rectangle Coordinate\n";
    cin>>x1>>y1>>x2>>y2;

    setcolor(3);
    rectangle(x1,y1,x2,y2);
    cout<<"Enter angle \n";
    cin>>a;
    a=(a*3.14)/180;

    double xr=x1+((x2-x1)*cos(a)-(y2-y1)*sin(a));
    double yr=y1+((x2-x1)*sin(a)+(y2-y1)*cos(a));

    setcolor(2);
    rectangle(x1,y1,xr,yr);

    getch();
    closegraph();
}
void triangle()
{
    double x1,y1,x2,y2,x3,y3,angle,c,s;
    cout<<"Enter triangle Coordinate\n";

    setcolor(RED);

    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    //setbkcolor(WHITE);
    cleardevice();
    line(x1,y1,x2,y2);
    line(x2,y2, x3,y3);
    line(x3, y3, x1, y1);
    //getch();
    //setbkcolor(BLACK);
    cout<<"Enter angle \n";

    cin>>angle;
    //setbkcolor(WHITE);
    c = cos(angle *M_PI/180);
    s = sin(angle *M_PI/180);
    x1 = floor(x1 * c + y1 * s);
    y1 = floor(-x1 * s + y1 * c);
    x2 = floor(x2 * c + y2 * s);
    y2 = floor(-x2 * s + y2 * c);
    x3 = floor(x3 * c + y3 * s);
    y3 = floor(-x3 * s + y3 * c);

    cleardevice();

    line(x1, y1 ,x2, y2);
    line(x2,y2, x3,y3);
    line(x3, y3, x1, y1);

    getch();
    closegraph();
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\Tc\\BGI");

    char ch;
    cin>>ch;

    if(ch=='L')
    {
        line();
    }
    if(ch=='R')
    {
        rectangle();
    }
    if(ch=='T')
    {
        triangle();
    }
}

