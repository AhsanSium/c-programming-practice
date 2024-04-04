#include<bits/stdc++.h>
using namespace std;

int const N = 1e6;
int dp[N];

int min_step(int n)
{
    // 1. define base case
    if(n == 0){return 0;}
    if(n <= 3){return 1;}

    // 2. check if the ans is already calculated
    if(dp[n] != 0){return dp[n];}

    // 3. calculate the ans from smaller sub-problems
    int first = (n % 3 == 0) ? ( min_step(n / 3)):1000000;
    int second = (n % 2 == 0) ? (min_step(n / 2)):1000000;
    int third = min_step(n - 1);

    int ans = 1 + min({first, second, third});
    dp[n] = ans;

    return ans;

}

int main()
{
    int n;
    cin >> n;

    if(n == 0){cout << 0 << "\n"; return 0;}

    cout << min_step(n) <<"\n";


    return 0;
}
