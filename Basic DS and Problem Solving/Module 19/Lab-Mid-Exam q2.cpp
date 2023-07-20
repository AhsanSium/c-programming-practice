#include<bits/stdc++.h>
using namespace std;


vector <int> remove_duplicate_merge_sort(vector<int>a)
{
    if(a.size() <= 1) return a;

    vector <int> Left;
    vector <int> Right;

    int mid = a.size() / 2;

    for(int i = 0; i < mid; i++) Left.push_back(a[i]);

    for(int i = mid; i < a.size(); i++) Right.push_back(a[i]);

    vector <int> sorted_left = remove_duplicate_merge_sort(Left);
    vector <int> sorted_right = remove_duplicate_merge_sort(Right);

    vector <int> ans;

    int p1 = 0;
    int p2 = 0;

    for(int i = 0; i < a.size(); i++){
        if(p1 == sorted_left.size()){
            if(p2 < sorted_right.size()){
                ans.push_back(sorted_right[p2]);
                p2++;
            }
        }
        else if(p2 == sorted_right.size()){
            if(p1 <= sorted_left.size()){
                ans.push_back(sorted_left[p1]);
                p1++;
            }
        }
        else if(sorted_left[p1] < sorted_right[p2]){
            ans.push_back(sorted_left[p1]);
            p1++;
        }
        else if(sorted_left[p1] > sorted_right[p2]){
            ans.push_back(sorted_right[p2]);
            p2++;
        }
        else if(sorted_left[p1] == sorted_right[p2]){
            ans.push_back(sorted_right[p2]);
            p1++;
            p2++;
            i++;
        }

    }

    return ans;
}

int main()
{
    int sz;
    cin >> sz;
    vector <int> input(sz);

    for(int i = 0; i < sz; i++) cin >> input[i];

    vector <int> output = remove_duplicate_merge_sort(input);

    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";

    return 0;
}

