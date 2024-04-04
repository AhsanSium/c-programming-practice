#include<bits/stdc++.h>
using namespace std;

const long long N = 1e6;
long long dp[N];
long long freq[N];

long long max_val(long long a, long long b)
{
    if(a > b){return a;}
    return b;
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

    // 1. define base case
    dp[0] = 0;
    dp[1] = freq[1];

    // 2. loop through the states for solution
    for(long long i = 2; i <= N; i++){
        // 2.1 find the ans from smaller sub problems
        long long ans = max_val( (i * freq[i] + dp[i - 2]), dp[i - 1]);
        dp[i] = ans;
    }

    cout << dp[maxx] << "\n";

    return 0;
}

