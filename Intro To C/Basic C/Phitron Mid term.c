#include<stdio.h>

int problem1()
{
    int n = 10;
int x = 5;
int index = 0;
int a[] = {12, 7, 3, 71, 2, 43, 38, 23, 45, 22};
int b[n];
for (int i=0; i<n; i++) {
	//Write Code Here
	b[i] = x + a[i];
}
for (int i=0; i<n; i++) {
	//Write Code Here
	printf("%d ",b[i]);
}

char s[] = "america";

puts(s);

}


int problem3()
{

//    size_t n = sizeof(arr)/sizeof(arr[0]);
//
//    printf("%d \n", n);

//    int arr[15];
//
//    for(int i = 0; i < 15; i++){
//        if( i == 0){
//            arr[i] = 1;
//        }
//        else{
//            arr[i] = arr[i - 1] * 2;
//        }
//    }
//
//    for(int i = 0; i < 15; i++){
//        printf("%d ", arr[i]);
//    }


//char a[10];
//	a[0] = 98;
//	a[1] = 97;
//	a[2] = 'n';
//	a[3] = 'a';
//	a[4] = 'n';
//	a[5] = 'a';
//	a[6] = '\0';

char a[10];
char ch = 'a';
for(int i = 0; i<8;i++)
{
a[i] = ch+8-i;
//printf("%d ", ch + 8 - i);
}
a[8] = '\0';


	//puts(a);

	printf("%d", ch);

}


/* Bubble sort code in C */
#include <stdio.h>

int problem11()
{

  int n = 11, c, d, swap;


  int array[11] = {7, 9, 12, 1, 3, 73, 11, 15, 62, 19, 4};

  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1])
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
     printf("%d ", array[d]);
    }
    printf("\n", array[c]);
  }

  printf("\n\nSorted list in ascending order:\n");

  for (c = 0; c < n; c++)
     printf("%d ", array[c]);

  return 0;
}



int main()
{
    //problem1();

    //problem3();

    problem11();

    return 0;
}
