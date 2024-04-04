#include<bits/stdc++.h>
using namespace std;

/*
- state: fun(n, target) -> returns 1 if it is possible to create a
         subset from numbers 1 to n and the sum "target"

- recurrance: fun(n, target) ->
                 fun(n - 1, target) OR
                 fun(n - 1, target - nums[n]) if target >= nums[n]

- base case: fun(0, target) -> 1 if target == 0
                               else 0
*/

const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];
/*
test case
6 9
3 34 4 12 5 2

1
*/


int main()
{
    int n, target;
    cin >> n >> target;

    for(int i = 1; i <= n; i++){
        cin >> nums[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j<= target; j++){
            dp[i][j] = -1;
        }
    }

    // 1. define base case
    dp[0][0] = 1;
    for(int i = 1; i <= target; i++){
        dp[0][i] = 0;
    }

    // 2. loop over the states
    for(int i = 1; i <= n; i++){
        for(int sub_target = 1; sub_target <= target; sub_target++){
            // 2.1 calculate answer from smaller subproblems
            int ans1 = dp[i - 1][sub_target];
            if(sub_target < nums[i]){
                dp[i][sub_target] = ans1;
                continue;
            }
            int ans2 = dp[i - 1][sub_target - nums[i]];
            int ans = ans1 || ans2;

            dp[i][sub_target] = ans;
        }
    }

    cout << dp[n][target] << "\n";

    return 0;
}

