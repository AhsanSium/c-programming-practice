#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ll = long long;

int count_digits(ll a)
{
    if(a == 0) return 1;
    int count = 0;
    while(a != 0){
        a = a / 10;
        count ++;
    }
    return count;
}

bool bfs(ll n, ll x)
{
    // level = level of node in bfs
    map <ll, ll> level;
    queue <ll> q;

    // level of initial x = 0
    level[x] = 0;
    q.push(x);
    while(!q.empty()){
        ll curr = q.front();
        q.pop();

        // if no of digits in this number == x
        // ans = this nodes level
        if(count_digits(curr) == n){
            cout << level[curr] << "\n";
            return true;
        }

        ll temp = curr;
        while(temp){
            ll dig = temp % 10;
            temp = temp / 10;

            // iterate over the digits and if node is not visited
            // push it into bfs
            if(level.find(dig * curr) == level.end()){
                q.push(dig * curr);
                level[dig * curr] = level[curr] + 1;
            }
        }

    }

    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, x;
    cin >> n >> x;
    if(x == 1){cout << -1 << "\n"; return 0;}
    bool ans = bfs(n, x);
    if(!ans){cout << -1 << "\n";}

    return 0;
}
