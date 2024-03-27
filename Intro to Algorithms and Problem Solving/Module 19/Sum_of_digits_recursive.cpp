#include<bits/stdc++.h>
using namespace std;

int get_sum(int n)
{
    if(n < 10){return n;}

    return (n%10) + get_sum(n/10);
}

int main()
{
    int n;
    cin >> n;

    if(n < 0){n = n * -1;}
    int sum = get_sum(n);
    cout << sum << "\n";

    return 0;
}
