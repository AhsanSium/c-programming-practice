#include<bits/stdc++.h>
using namespace std;

vector <int> merge_sort(vector <int> a)
{
    // Base Case
    int arr_size = a.size();
    if(arr_size <= 1) return a;

    // Divide 2 Part
    int mid = arr_size / 2;
    vector <int> b;
    vector <int> c;

    for(int i = 0; i < mid; i++) b.push_back(a[i]);

    for(int i = mid; i < arr_size; i++) c.push_back(a[i]);


    // Sorted Array Handle

    vector <int> sorted_b = merge_sort(b);
    vector <int> sorted_c = merge_sort(c);

    // Conquer
    vector <int> sorted_a;

    int idx1 = 0, idx2 = 0;

    for( int i = 0; i < arr_size; i++ ){

        if(idx1 == sorted_b.size()){
            sorted_a.push_back(sorted_c[idx2]);
            idx2 ++;
        }
        else if(idx2 == sorted_c.size()){
            sorted_a.push_back(sorted_b[idx1]);
            idx1 ++;
        }
        else if(sorted_b[idx1] < sorted_c[idx2]){
            sorted_a.push_back(sorted_b[idx1]);
            idx1 ++;
        }
        else{
            sorted_a.push_back(sorted_c[idx2]);
            idx2 ++;
        }
    }

    return sorted_a;

}

int main()
{
    vector <int> arr;
    int n;
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    //cout << arr[1];

    vector <int> ans = merge_sort(arr);

    for(int i = 0; i < n; i++) cout << ans[i] << " ";

    return 0;
}
