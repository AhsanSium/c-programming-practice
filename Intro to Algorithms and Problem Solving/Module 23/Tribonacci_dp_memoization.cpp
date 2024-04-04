#include<bits/stdc++.h>
using namespace std;
static constexpr int N = 101;

long long dp[N];
long long tribonacci(int n)
{
    // 1. Base case
    if(n == 0){return 0;}
    if(n <= 2){return 1;}
    if( n == 3){return 2;}

    // 2. check if the ans is already calculated
    if(dp[n] != 0){return dp[n];}

    // 3. Calculate the ans from smaller sub-problems
    int ans = tribonacci(n - 3) + tribonacci(n - 2) + tribonacci(n - 1);
    dp[n] = ans;

    return ans;
}

int main()
{
    int n;
    cin >> n;

    cout << tribonacci(n) << "\n";

    return 0;
}
