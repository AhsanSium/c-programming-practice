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
// vector <char> ch;
int n, m;
string s, t;

int LCS(int i, int j)
{
    // 1. handle base case
    if(i == n || j == m){return 0;}

    // 2. check if result already calculated, return it
    if(dp[i][j] != 0){return dp[i][j];}

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;

    n = s.size();
    m = t.size();

//    for(int i = 0; i <= n; i++){
//        for(int j = 0; j <= m; j++){
//            dp[i][j] = -1;
//        }
//    }


    int lcs = LCS(0, 0);
//    cout << lcs << "\n";
//
//    for(int i = 0; i <= n; i++){
//        cout << s[i] << " ";
//
//        for(int j = 0; j <= m; j++){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }

    // Backtrack the DP table to find answer string
    string ans = "";
    int x = 0, y = 0;
    while(y != m && x != n){

        if(dp[x+1][y] == dp[x][y]){
            x++;
        }
        else if(dp[x][y+1] == dp[x][y]){
            y++;
        }
        else{
            ans = ans + t[y];
            x++;
            y++;
        }
    }

    cout << ans <<"\n";

    return 0;
}

