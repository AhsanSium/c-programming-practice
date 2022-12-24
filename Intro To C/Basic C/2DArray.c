#include<stdio.h>

// 2D Array is Diagonal or Not for Main Diagonal

int main()
{
    int row, col;
    scanf("%d %d", &row, &col);

    int a[row][col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &a[i][j]);
        }
    }

    if(row == col){

        int ans = 1;

        for(int i = 0; i < row; i++){

            for(int j = 0; j < col; j++){

                if( i == j){
                    continue;
                }
                if( a[i][j] != 0){
                    ans = 0;
                }
            }
        }

        if(ans == 0){
            printf("Not Diagonal \n");
        }
        else{
            printf("Diagonal \n");
        }
    }
    else{
        printf("Not Diagonal \n");
    }
}
