#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, count = 0;
    scanf("%d", &n);
    int arr[n];
    scanf("%d", &k);

    for( int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        if(arr[i] >= k){
            count ++;
            printf("Count = %d  array = %d  K = %d \n", count, arr[i], k);
        }
    }
    // for( int i = 0; i < n; i++){
    //     printf("%d ", arr[i]);
    // }
    printf("%d", count);

    return 0;
}
