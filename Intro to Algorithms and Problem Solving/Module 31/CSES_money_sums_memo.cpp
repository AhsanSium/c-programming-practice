#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int dp[N];
int sum_array[N];
int n;
vector <int> input;

int money_sum(int item)
{
    // 1. define base case
    if(item == 0){return 1;}

    // 2. check if the solution already exists
    if(dp[item] != -1){return dp[item];}

    // 3. calculate the solution from smaller sub problems
    int ans = 0;
    for(int i = 1; i <= item; i++){
        ans = ans + money_sum(i - 1);
    }
//    int ans = money_sum(item - 1) + 1;
//    sum_array[item] = input[item - 1] + input[item];
    dp[item] = ans;
    return ans;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
        dp[i] = -1;
    }
    dp[n] = -1;

    int ans = money_sum(n);

    cout << ans << "\n";

    for(int i = 1; i <= ans; i++){
        cout << sum_array[i] << " ";
    }
    cout << "\n";

    return 0;
}
