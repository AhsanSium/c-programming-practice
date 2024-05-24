#include<bits/stdc++.h>
using namespace std;

const int N = 100;
const long long M = 1000007;
const long long MOD = 1e9 + 7;

long long dp[M];
long long coin[M];

long long fun(long long n, long long target)
{
    // 1. base case
    if(target == 0){return 1;}
    if(target < 0){return 0;}

    // 2. if result is already calculated return it
    if(dp[target] != -1){
        return dp[target];
    }



    // 3. calculate result from smaller sub problems
    long long ans = 0;
    for(long long i = 1; i <= n; i++){
        //cout << "Hi" << "\n";
        long long ret = fun(n, target - coin[i]) % MOD;
        //cout << ret << "\n";
        ans = (ans + ret) % MOD;
        // cout << ans << "\n";
    }
    dp[target] = ans;

    return ans;
}

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
    // cout << dp[K] << "\n";
    cout << fun(n, K) << "\n";

    return 0;
}
