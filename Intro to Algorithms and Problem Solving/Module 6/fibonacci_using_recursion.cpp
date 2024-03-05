#include <bits/stdc++.h>
using namespace std;

int fibonacci(int a)
{
    if(a == 0){return 0;}
    if(a == 1){return 1;}

    return fibonacci(a - 1) + fibonacci(a - 2);
}

int main()
{
    int n = 0, ans = 0;
    cin >> n;

    ans = fibonacci(n);

    cout << "Fibonacci of " << n << " th number is " << ans << "\n";

    return 0;
}


