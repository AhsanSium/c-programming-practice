#include <bits/stdc++.h>
#include <algorithm>
using namespace std;


int gcd(int a, int b)
{
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

int findGCD( vector<long long int>arr, int n)
{
  int result = arr[0];
  for (int i = 1; i < n; i++)
  {
    result = gcd(arr[i], result);

    if(result == 1)
    {
    return 1;
    }
  }
  return result;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t > 0){

        int n,gcd;
        cin >> n;
        vector<long long int> a(n);

        for(int i = 0; i < n; i++){ cin >> a[i]; }

        gcd = findGCD(a , n);

        //cout << "GCD = " << gcd << "\n";

        if(gcd > n){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }

        t--;
    }

    return 0;
}
