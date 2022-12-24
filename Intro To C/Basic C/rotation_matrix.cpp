#include<bits/stdc++.h>
#include<graphics.h>
#include<windows.h>
#include<math.h>

using namespace std;
void mul(float mat[10][3],int vertex[10][3],int n);
void rotate(int vertex[10][3],int n);

int main()
{
  int i,x,y;
  initwindow(800,800);

   setcolor(10);
   line(0,400,800,400);
   line(400,0,400,800);

   setcolor(3);
  int vertex[10][3],n;
  cout<<"\nEnter the no. of vertex : ";
  cin>>n;
   for(i=0;i<n;i++)
     {
	    cout<<"Enter the points (x,y): ";
	    cin>>x>>y;
	    vertex[i][0]=x;
	    vertex[i][1]=y;
	    vertex[i][2]=1;
     }

      for(i=0;i<n-1;i++)
    {
       line(400+vertex[i][0],400-vertex[i][1],400+vertex[i+1][0],400-vertex[i+1][1]);
         if(i==0)
        outtextxy(400+vertex[i][0],400-vertex[i][1],"1st");
       if(i==1)
        outtextxy(400+vertex[i][0],400-vertex[i][1],"2nd");
     }
     line(400+vertex[n-1][0],400-vertex[n-1][1],400+vertex[0][0],400-vertex[0][1]);
      outtextxy(400+vertex[n-1][0],400-vertex[n-1][1],"3rd");
     rotate(vertex,n);
	 getch();
	 return 0;
}

void mul(float mat[3][3],int vertex[10][3],int n)
{
  int i,j,k;
 float res[10][3];

  for(i=0;i<n;i++)
   {
     for(j=0;j<3;j++)
      {
	     res[i][j]=0;
         for(k=0;k<3;k++)
	      {
	         res[i][j] = res[i][j] + vertex[i][k]*mat[k][j];
	       }
     }
   }

   setcolor(15);
   for(i=0;i<n-1;i++)
    {
       line(400+res[i][0],400-res[i][1],400+res[i+1][0],400-res[i+1][1]);
       if(i==0)
        outtextxy(400+res[i][0],400-res[i][1],"1st");
       if(i==1)
        outtextxy(400+res[i][0],400-res[i][1],"2nd");
     }
     line(400+res[n-1][0],400-res[n-1][1],400+res[0][0],400-res[0][1]);
       outtextxy(400+res[n-1][0],400-res[n-1][1],"3rd");

}


void rotate(int vertex[10][3],int n)
{
   float rotate_array[3][3];

   int x;

   cout<<"\nEnter rotate angel: ";
   cin>>x;
   float radian=float(x)*3.14f/180;
float   co=cos(radian);
float   sg=sin(radian);
		 rotate_array[0][0]=co;
	     rotate_array[1][0]=sg*(-1);
	     rotate_array[2][0]=0;
	     rotate_array[0][1]=sg;
	     rotate_array[1][1]=co;
	     rotate_array[2][1]=0;
	     rotate_array[0][2]=0;
	     rotate_array[1][2]=0;
	     rotate_array[2][2]=1;
	     mul(rotate_array,vertex,n);

 }

 /*
10 15
65 15
65 45
10 45
*/

/*50 50
  0 0
  100 0
*/


