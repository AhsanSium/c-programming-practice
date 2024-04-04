#include<bits/stdc++.h>
using namespace std;

int const N = 1e6;
int dp[N];

int main()
{
    int n;
    cin >> n;

    // 1. define base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    // 2. Loop through each state
    for(int i = 4; i <= n; i++){
        // 2.1 find ans from smaller sub problems
        int first = (i % 3 == 0) ? ( dp[i / 3]):1000000;
        int second = (i % 2 == 0) ? (dp[i / 2]):1000000;
        int third = dp[i - 1];

        int ans = 1 + min({first, second, third});
        dp[i] = ans;
    }

    cout << dp[n] <<"\n";

    return 0;
}

