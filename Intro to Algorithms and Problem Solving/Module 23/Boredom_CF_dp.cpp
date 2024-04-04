#include<bits/stdc++.h>
using namespace std;

const long long N = 1e6;
long long dp[N];
long long freq[N];

long long fun(long long n)
{
    // 1. define base case
    if(n == 0){dp[0] = 0; return 0;}
    if(n == 1){return freq[1];}

    // 2. check if the value already calculated
    if(dp[n] != 0){return dp[n];}

    // 3. calculate the ans from sub-problem
    long long ans = max( ( n * freq[n] + fun(n - 2)), fun(n - 1));
    dp[n] = ans;

    return ans;
}

int main()
{
    long long n;
    cin >> n;
    long long temp;
    long long maxx = -1;
    for(long long i = 1; i <= n; i++){

        cin >> temp;
        freq[temp] ++;

        if(temp > maxx){maxx = temp;}
    }

    // cout << "Max: " << maxx <<"\n";

    long long ans = fun(maxx);

    cout << ans << "\n";

    return 0;
}
