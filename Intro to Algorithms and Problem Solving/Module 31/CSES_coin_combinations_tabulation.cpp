#include<bits/stdc++.h>
using namespace std;

const int N = 100;
const long long M = 1000007;
const long long MOD = 1e9 + 7;

long long dp[M];
long long coin[M];

int main()
{

    long long n, K;
    cin >> n >> K;

    for(long long i = 1; i <= n; i++){
        cin >> coin[i];
    }

    for(long long i = 0; i <= K; i++){
        dp[i] = -1;
    }

    // 1. define base case
    dp[0] = 1;

    // 2. loop through the states

    for(int target = 1; target <= K; target++){
        // 2.1 calculate ans from sub-problem
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            if(target - coin[i] < 0){continue;}
            ans = ans + dp[target - coin[i]];

        }
        dp[target] = ans % MOD;
    }



    cout << dp[K] << "\n";

    return 0;
}

