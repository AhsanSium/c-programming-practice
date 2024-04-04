#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];
int h[N];

int coins(int n, bool choosen)
{
    // 1. Handle base case
    if(n == 0){
        return 0;
    }

    // 2. check if ans already exists
    if(dp[n] != 0){return dp[n];}

    // 3. calculate the ans from sub-problem
    int ans;
    if(choosen == true){
        ans = coins(n - 1, false) + h[n];
    }
    else{
        ans = coins(n - 1, true);
    }

    dp[n] = ans;
    return ans;
}

int main()
{
    int t, n;
    cin >> t;

    for(int i = 1; i <= t; i++){
        cin >> n;
        if(n == 0){
             cout << "Case " << i << ": " << 0 <<"\n";
             continue;
        }
        for(int j = 1; j <= n; j++){
            cin >> h[j];
        }
        int without_choosing = coins(n, false);
        for(int j = 1; j <= n; j++){
            dp[j] = 0;
        }
        int with_choosing = coins(n, true);
        cout << "Case " << i << ": " << max(without_choosing, with_choosing);
        for(int j = 1; j <= n; j++){
            h[j] = 0;
            dp[j] = 0;
        }
        cout << "\n";
    }

    return 0;
}
