#include<bits/stdc++.h>
using namespace std;

long long int get_sum(int n, long long int inp[])
{
    long long int sum = inp[n];
    // cout << n <<"\n";
    if(n == 0){
        return inp[0];
    }
    else{
        return sum + get_sum(n-1, inp);
    }
}

int main()
{
    int n;
    cin >> n;
    long long int inp[n];

    for(int i = 0; i < n; i++){
        cin >> inp[i];
    }

    long long int sum = get_sum(n -1, inp);

    cout << sum << "\n";

    return 0;
}
