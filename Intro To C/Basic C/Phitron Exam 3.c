#include <stdio.h>
#include <math.h>

// Swap Numbers
//int main()
//{
//    int a=5, b=13;
//
//    a = a + b;
//
//    b = a - b;
//
//    a = a - b;
//
//    printf("\nA = %d ; B = %d", a, b);
//
//    return 0;
//}




// Smallest and Largest of Four

//int main()
//{
//    int a, b, c, d;
//    int largest, smallest;
//
//    scanf("%d %d %d %d", &a, &b, &c, &d);
//
//    // max and min of a, b
//
//    if(a > b){
//        largest = a;
//        smallest = b;
//    }
//    else{
//        largest = b;
//        smallest = a;
//    }
//
//    // max and min of c, d & compare
//
//    if(c > d){
//        if(largest < c){
//            largest = c;
//        }
//        if(smallest > d){
//            smallest = d;
//        }
//    }
//    else{
//        if(largest < d){
//            largest = d;
//        }
//        if(smallest > c){
//            smallest = c;
//        }
//    }
//
//    printf("Largest = %d \nSmallest = %d", largest, smallest);
//
//    return 0;
//}






// Number of Digits in an Integer

//int main()
//{
//    long long int a, b = 0;
//
//    scanf("%lld", &a);
//
//    while(a > 0){
//        a = a / 10;
//        b ++;
//        //printf("A = %lld     B = %lld \n", a, b);
//    }
//
//    printf("%lld digits", b);
//
//    return 0;
//}



// Sum of Digits in an Integer

int main()
{
    long long int a = 0, b = 0;

    scanf("%lld", &a);

    while(a > 0){
        b = b + (a % 10);
        a = a / 10;
        //printf("A = %lld     B = %lld \n", a, b);
    }

    printf("%lld", b);

    return 0;
}





// Sequence

//int main()
//{
//    long long int n = 0;
//
//    scanf("%lld", &n);
//
//    while(n > 0){
//
//        if(n == 1){
//            printf("%lld", n);
//        }
//        else{
//            printf("%lld, ", n);
//        }
//
//        if(n % 2 == 0){
//            n = n / 2;
//        }
//        else{
//            n --;
//        }
//
//    }
//
//    return 0;
//}






// Input Divisible or not

//int main()
//{
//    long long int a = 0, b = 0;
//    printf("Enter the first number: ");
//    scanf("%lld", &a);
//    printf("Enter the second number: ");
//    scanf("%lld", &b);
//
//    if(a % b == 0){
//        printf("The first number is divisible by the first second number.");
//    }
//    else if(b % a == 0){
//        printf("The second number is divisible by the first number.");
//    }
//    else{
//        printf("None of them are divisible by the other.");
//    }
//
//    return 0;
//}




// LCM of an Integer

//int main()
//{
//    long long int a = 0, b = 0, max = 0;
//
//    scanf("%lld", &a);
//    scanf("%lld", &b);
//
//    if(a > b) max = a;
//    else max = b;
//
//    while(1){
//        if(max % a == 0 && max % b == 0){
//
//            printf("The LCM of %lld and %lld is %lld.", a, b, max);
//            break;
//        }
//
//        max++;
//    }
//
//    return 0;
//}



// GCD of an Integer

//int main()
//{
//    long long int a = 0, b = 0, i = 1, gcd = 0;
//
//    scanf("%lld %lld", &a, &b);
//
//
//    for(i; i <= a && i <= b; i++){
//        if(a % i == 0 && b % i == 0){
//            gcd = i;
//        }
//    }
//
//    printf("The GCD of %lld and %lld is %lld.", a, b, gcd);
//
//    return 0;
//}





//int main()
//{
//    long long int a = 0,i = 1;
//
//    scanf("%lld", &a);
//
//    printf("The factors of %lld are: ", a);
//
//    for(i; i <= a; i++){
//        if(a % i == 0){
//                (i == a) ? printf("%lld. ", i) : printf("%lld, ", i);
//        }
//    }
//
//    return 0;
//}





//int main()
//{
//    long long int a = 0,i = 2, square_root;
//
//    scanf("%lld", &a);
//
//    square_root = sqrt(a);
//
//    // printf("%lld", square_root);
//
//    if(a == 1 || a == 2){
//        printf("Prime");
//
//        return 0;
//    }
//
//    for(i; i <= square_root; i++){
//        if(a % i == 0){
//            printf("Composite");
//            return 0;
//        }
//    }
//
//    printf("Prime");
//
//    return 0;
//}


