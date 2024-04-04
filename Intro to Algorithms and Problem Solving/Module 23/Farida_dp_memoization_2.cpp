#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];
int h[N];

int coins(int n)
{
    // 1. Handle base case
    if(n <= 1){
        return h[n];
    }

    // 2. check if ans already exists
    if(dp[n] != 0){return dp[n];}

    // 3. calculate the ans from sub-problem
    int ans = max( (coins(n - 2) + h[n]), coins(n - 1) );

    dp[n] = ans;
    return ans;
}

int main()
{
    int t, n;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n;
        if(n == 0){
             cout << "Case " << i << ": " << 0 <<"\n";
             continue;
        }
        for(int j = 1; j <= n; j++){
            cin >> h[j];
        }
        int ans = coins(n);
        cout << "Case " << i << ": " << ans;
        for(int j = 1; j <= n; j++){
            h[j] = 0;
            dp[j] = 0;
        }
        cout << "\n";
    }

    return 0;
}
