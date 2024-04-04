#include<bits/stdc++.h>
using namespace std;
const int N = 101;
/*

 - 1. Define state: fib(n) -> calculates the n'th fibonacci number
 - 2. Recursive Equation: fib(n - 1) + fib(n - 2)
 - 3. Base case: fib(1) = 1, fib(2) = 1

*/

long long dp[N];
long long fib(int n)
{
    // 1. handle base case
    if(n == 0){return 0;}
    if(n <= 2) return 1;

    // 2. if current state is already solved return result
    if(dp[n] != -1){return dp[n];}

    // 3. calculate the result from smaller sub problems
    long long ans = fib(n - 1) + fib(n - 2);
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        // mark all states as unvisited
        dp[i] = -1;
    }
    // memset(dp, -1, sizeof(dp));

    cout << fib(n) << "\n";

    return 0;
}
