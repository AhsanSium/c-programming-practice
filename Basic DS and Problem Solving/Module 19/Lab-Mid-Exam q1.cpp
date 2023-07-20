#include<bits/stdc++.h>
using namespace std;

vector <int> reverse_array(vector<int>a, int sz)
{
    vector <int> ans;

    for(int i = sz; i > 0; i--){
        ans.push_back(a[i - 1]);
    }

    return ans;
}

int main()
{
    int sz;
    cin >> sz;
    vector <int> input(sz);

    for(int i = 0; i < sz; i++) cin >> input[i];

    vector <int> output = reverse_array(input, sz);

    for(int i = 0; i < sz; i++) cout << output[i] << " ";

    return 0;
}
