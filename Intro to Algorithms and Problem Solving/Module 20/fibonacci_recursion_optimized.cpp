#include<bits/stdc++.h>
using namespace std;

long long saved[101];
/*
Optimized:
O(2^n) => O(n)
*/
long long fibo(int n)
{
    if(n <= 2){return 1;}
    // Check if fib(n) is already calculated
    if(saved[n] != 0){
        return saved[n];
    }
    saved[n] = fibo(n - 1) + fibo(n - 2);
    return saved[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << "\n";
    return 0;
}
