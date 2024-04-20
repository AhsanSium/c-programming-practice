#include<bits/stdc++.h>
using namespace std;

/*
    -state: LCS(i, j) -> Length of longest common subsequence between strings
                         s[i ... n] and t[j ... m]

    -recurrence: if(s[i] == t[j]){return(LCS(i, j) = 1 + LCS(i+1, j+1))}
                 else {return(max(LCS(i+1, j), LCS(i, j+1)))}

    -base case: LCS(i, m) = 0
                LCS(n, j) = 0
*/

const int N = 3003;
int dp[N][N];
int n, m;
string s, t;

int LCS(int i, int j)
{
    // 1. handle base case
    if(i == n || j == m){return 0;}

    // 2. check if result already calculated, return it
    if(dp[i][j] != -1){return dp[i][j];}

    // 3. calculate result from sub problems
    if(s[i] == t[j]){
        int ans = 1 + LCS(i+1, j+1);
        dp[i][j] = ans;
        return ans;
    }
    int ans = max( LCS(i+1, j), LCS(i, j+1));
    dp[i][j] = ans;
    return ans;
}

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }

    cout << LCS(0, 0) << "\n";

    return 0;
}
