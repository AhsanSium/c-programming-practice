/// Problem Link: https://lightoj.com/problem/coin-change-i
/*
- state: dp(n, k) -> number of ways to make sum = k from coins 1 to n without crossing limit
- recurrence: dp(n, k) = dp(n - 1, k) +
                         dp(n - 1, k - coin[n]) +
                         dp(n - 1, k - 2 * coin[n]) +
                         ....
                         dp(n - 1, k - limit[n] * coin[n])

- base case: dp(0, 0) = 1
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 60;
const int M = 1001;
const int MOD = 100000007;

int dp[N][M];
int coin[N], limit[N];

int main()
{
    int t, test = 0;
    cin >> t;

    while(t --){
        int n, K;
        cin >> n >> K;

        for(int i = 1; i <= n; i++){
            cin >> coin[i];
        }

        for(int i = 1; i <= n; i++){
            cin >> limit[i];
        }

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= K; j++){
                dp[i][j] = 0;
            }
        }
        // 1. define base case
        dp[0][0] = 1;

        // 2. loop over the states
        for(int i = 1; i <= n; i++){
            for(int target = 0; target <= K; target++){
                // 2.1 calculate ans from smaller sub-problem
                dp[i][target] = dp[i - 1][target];

                for(int j = 1; j <= limit[i]; j++){
                    if(target < j * coin[i]){break;}
                    int ret = dp[i - 1][target - j * coin[i]];
                    dp[i][target] = (dp[i][target] + ret) % MOD;
                }
            }
        }

        cout << "Case " << ++test <<": "<<dp[n][K]<< "\n";

    }

    return 0;
}

