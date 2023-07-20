#include<bits/stdc++.h>
#include <string>

using namespace std;

int maxElement(vector <int> input, int idx, int maxx)
{
    if(idx == input.size()){
        return maxx;
    }
    else{
        if(maxx < input[idx]) maxx = input[idx];
        return maxElement(input, idx + 1, maxx);
    }
}

int main()
{

    int sz;
    cin >> sz;
    vector <int> input(sz);

    for(int i = 0; i < sz; i++) cin >> input[i];

    int res = maxElement(input, 0, input[0]);

    cout << res;

    return 0;
}
