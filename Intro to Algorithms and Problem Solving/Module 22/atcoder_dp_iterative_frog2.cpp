#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int INF = 2e9;
/*
- state: stone(n) -> cost of reaching n-th stone from 1st stone
- recurrance: stone(n) = for i = 1 to k:
                            min(
                             stone(n - i) + abs( h[n] - h[n - i])
                            )
- base case: stone(1) = 0

- corner case: cant jump from stones with number <= 0

3 5
10 30 40 50 20
30

*/
int h[N];
int dp[N];
int n, k;


int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }

    // 1. base case
    dp[1] = 0;

    // 2. Loop over the states
    for(int i = 2; i <= n; i++){
        // 2.1 calculate from smaller sub problems
        dp[i] = INF;
        for(int j = 1; k <= k; j++){
            int from_stone = i - j;
            if(from_stone <= 0){break;}
            int candidate_ans = dp[from_stone] + abs(h[i] - h[from_stone]);
            dp[i] = min(dp[i], candidate_ans);
        }
    }

    cout << dp[n] << "\n";
}


