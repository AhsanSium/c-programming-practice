#include<bits/stdc++.h>
using namespace std;

int missingNumber(int n, vector <int> a)
{
    vector <int> cnt;
    cnt.resize(n+1);
    int temp;

    for(int i = 1; i < n; i++){
        temp = a[i];
        cnt[temp] = cnt[temp] + 1;
    }

    for(int i = 1; i < n + 1; i++){
        if(cnt[i] == 0){ return i;}
    }

    // Time Complexity O(n) + O(n) => O(n)

    return n;
}

int main()
{
    vector <int> input;
    int n, output;
    cin >> n;
    input.resize(n);

    for(int i = 1; i < n; i++) cin >> input[i];

    output = missingNumber(n, input);

    cout << output<< " ";

    return 0;
}

