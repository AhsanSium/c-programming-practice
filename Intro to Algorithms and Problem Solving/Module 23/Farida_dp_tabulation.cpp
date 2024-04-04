#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];
int h[N];

int main()
{
    int t, n;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> h[j];
        }
        // handle corner case
        if(n == 0){
             cout << "Case " << i << ": " << 0 <<"\n";
             continue;
        }

        // 1. handle base case
        dp[0] = 0;
        dp[1] = h[1];

        // 2. Loop through the states
        for(int j = 2; j <= n; j++){
            // 2.1 Calculate the optimum value for each smaller problem
            int ans = max( (dp[j - 2] + h[j]), dp[j - 1] );
            dp[j] = ans;
        }

        cout << "Case " << i << ": " << dp[n];
        for(int j = 1; j <= n; j++){
            h[j] = 0;
            dp[j] = 0;
        }
        cout << "\n";
    }

    return 0;
}

