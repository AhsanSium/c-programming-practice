#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector <int> arr, int a)
{
    int sz = arr.size();
    int left = 0, right = sz;
    int mid;
    int cnt = 0;
    while(left <= right){

        mid = left + (right - left) / 2;

        if(arr[mid] == a) {
            cnt++;
            if(cnt >= 2){
                return 1;
            }
        }
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

    // Here time complexity O(1) * O(log n) => O(log n)
    bool ans = binarySearch(arr1, m);

    cout << (ans ? "YES" : "NO")<< "\n";

    return 0;

}

