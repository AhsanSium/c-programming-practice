#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const long long N = 1010;
long long grid[N][N];
long long dp[N][N];

long long paths(long long x, long long y)
{
    // 1. base case
    // if((x == 0 && y != 0) || (y == 0 && x != 0)){return 0;}
    if(grid[x][y] == 0){return 0;}
    if(x == 1 && y == 1){return 1;}

    // 2. check if the result is already calculated
    if(dp[x][y] != -1){return dp[x][y];}

    // 3. calculate the ans from smaller sub problems.
    long long ans1 = 0, ans2 = 0;
    if(x >= 0){
        ans1 = paths(x - 1, y);
    }
    if(y >= 0){
        ans2 = paths(x, y - 1);
    }
    long long ans = (ans1 + ans2) % MOD;
    // cout << ans << "\n";
    dp[x][y] = ans;

    return ans;
}

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

//    for(int i = 0; i <= n + 1; i++){
//        for(int j = 0; j <= n + 1; j++){
//            cout << grid[i][j] << " ";
//        }
//        cout << "\n";
//    }

    // long long ways = paths(n, n);

    cout << paths(n, n) << "\n";

    return 0;
}
