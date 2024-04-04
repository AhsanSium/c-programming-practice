#include<bits/stdc++.h>
using namespace std;
static constexpr int N = 101;

long long dp[N];

int main()
{
    int n;
    cin >> n;

    // 1. Define base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    // 2. Loop through each state
    for(int i = 3; i <= n; i++){
        // 2.1 find the ans from smaller sub problems
        long long ans = dp[i - 3] + dp[i - 2] + dp[i - 1];
        dp[i] = ans;
    }

    cout << dp[n] << "\n";

    return 0;
}

