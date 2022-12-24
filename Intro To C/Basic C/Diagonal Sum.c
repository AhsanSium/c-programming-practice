#include <stdio.h>

int main()
{
	int A[3][3];
	int i, j;
	int size;
	int row_sum, col_sum, diagonal_sum;
	int magic = 0;


    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            scanf("%d", &A[i][j]);
        }
    }


    diagonal_sum = 0;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(i==j) {
                diagonal_sum = diagonal_sum + A[i][j];
            }
        }
    }


    for(i=0; i<3; i++) {
        row_sum = 0;
        for(j=0; j<3; j++) {
            row_sum = row_sum + A[i][j];
        }
        if(row_sum != diagonal_sum) {
            printf("NO");
            return 0;
        }
    }


    for(i=0; i<3; i++) {
        col_sum = 0;
        for(j=0; j<3; j++) {
            col_sum =  col_sum + A[j][i];
        }
        if(col_sum != diagonal_sum) {
            printf("NO");
            return;
        }
    }

    printf("YES");

	return 0;
}
