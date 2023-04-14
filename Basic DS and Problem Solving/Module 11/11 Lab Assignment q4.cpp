#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector <int> arr, int a)
{
    int sz = arr.size();
    int left = 0, right = sz;
    int mid;

    while(left <= right){

        mid = left + (right - left) / 2;

        if(arr[mid] == a) { return 1; }
        else if( arr[mid] < a ){ right = mid - 1; }
        else { left = mid + 1; }
    }

    return 0;
}

int main()
{
    int n,m;
    cin >> n;
    vector <int> arr1(n);
    for(int i = 0; i < n; i++) cin >> arr1[i];

    cin >> m;
    vector <int> arr2(m);
    for(int i = 0; i < m; i++) cin >> arr2[i];


    bool ans = true;
    // Array 0f 0(n) * binary search of O(log(n)) => O(n log(n))
    for(int i = 0; i < n; i++){
        if(!binarySearch(arr2, arr1[i])) {ans = false; break;}
    }

    cout << (ans ? "YES" : "NO")<< "\n";

    return 0;

}
