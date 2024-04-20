// leetcode unique paths
#include<bits/stdc++.h>
using namespace std;
/*
    - state: f(n, m) -> no of unique paths from (0, 0) to (n, m)
    - recurrance: f(n, m) -> f(n - 1, m) + f(n, m - 1)
    - base case: f(0, 0) = 1
*/

const int N = 101;
int dp[N][N];

int unique_paths(int n, int m)
{
    // 1. handle base case
    if(n == 0 && m == 0){
        return 1;
    }

    // 2. if result is calculated return it
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    // 3. calculate ans from smaller sub problems
    int ans = 0;
    if(n > 0) ans += unique_paths(n - 1, m);
    if(m > 0) ans += unique_paths(n, m - 1);

    dp[n][m] = ans;

    return ans;
}

/*
3 2
3
*/

int main()
{
    int row, col;
    cin >> row >> col;

    for(int i = 0; i < row; i++){
        for(int j = 0; j< col; j++){
            dp[i][j] = -1;
        }
    }

    cout << unique_paths(row - 1, col - 1) << "\n";

    return 0;
}
