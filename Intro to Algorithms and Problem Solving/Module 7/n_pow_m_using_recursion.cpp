#include<bits/stdc++.h>
using namespace std;

int n_pow_m(int n, int m)
{
    // Base Case
    if(n == 1){return 1;}
    if(m == 1){return n;}

    return n * n_pow_m(n, m - 1);
}

int main()
{
    int n,m, ans;
    cin >> n >> m;

    ans = n_pow_m(n, m);

    cout << n <<"^"<< m << " is "<< ans <<"\n";

    return 0;
}
