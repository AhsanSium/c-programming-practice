#include<bits/stdc++.h>
using namespace std;


vector <int> quick_sort_desc(vector<int>a)
{
    if(a.size() <= 1) return a;

    vector <int> Left;
    vector <int> Right;

    int pivot = rand() % (a.size());

    for(int i = 0; i < a.size(); i++){
        if(i == pivot) continue;

        a[i] >= a[pivot] ? Left.push_back(a[i]) : Right.push_back(a[i]);
    }

    vector <int> sorted_left = quick_sort_desc(Left);
    vector <int> sorted_right = quick_sort_desc(Right);

    vector <int> ans;

    for(int i = 0; i < sorted_left.size(); i++) ans.push_back(sorted_left[i]);

    ans.push_back(a[pivot]);

    for(int i = 0; i < sorted_right.size(); i++) ans.push_back(sorted_right[i]);

    return ans;
}

int main()
{
    int sz;
    cin >> sz;
    vector <int> input(sz);

    for(int i = 0; i < sz; i++) cin >> input[i];

    vector <int> output = quick_sort_desc(input);

    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";

    return 0;
}


