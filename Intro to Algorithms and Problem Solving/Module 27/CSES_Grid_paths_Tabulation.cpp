#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const long long N = 1010;
long long grid[N][N];
long long dp[N][N];

int main()
{
    long long n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        for(int j = 0; j < n; j++){
            dp[i + 1][j + 1] = -1;
            if(input[j] == '.'){
                grid[i + 1][j + 1] = 1;
            }
            if(input[j] == '*'){
                grid[i + 1][j + 1] = 0;
            }
        }
    }

    // 1. define base case
    if(grid[1][1] == 0){dp[1][1] = 0;} else {dp[1][1] = 1;}

    // 2. loop through the states
    for(int i = 1; i <= n; i++){
        // 2.1 find the ans from smaller problems
        for(int j = 1; j <= n; j++){
            if(grid[i][j] == 0){dp[i][j] = 0; continue;}

            long long ans1 = 0;
            if(i - 1 >= 0 && grid[i - 1][j] == 1){ans1 = dp[i - 1][j];}

            long long ans2 = 0;
            if(j - 1 >= 0 && grid[i][j - 1] == 1){ans2 = dp[i][j - 1];}
            if(dp[i][j] == -1){
                dp[i][j] = (ans1 + ans2) % MOD;
            }
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    cout << dp[n][n] << "\n";

    return 0;
}

