#include<bits/stdc++.h>
using namespace std;

vector <int> quick_sort(vector <int> a)
{
    // Base Case
    int arr_size = a.size();
    if(arr_size <= 1) return a;

    // Divide

    int pivot = arr_size - 1;

    vector <int> b;
    vector <int> c;

    for(int i = 0; i < arr_size; i++){
        if(i == pivot) continue;

        if( a[i] <= a[pivot]){ b.push_back(a[i]); }
        else { c.push_back(a[i]); }
    }


    vector <int> sorted_b = quick_sort(b);
    vector <int> sorted_c = quick_sort(c);

    // Conquer
    vector <int> sorted_a;

    for(int i = 0; i < sorted_b.size(); i++) sorted_a.push_back(sorted_b[i]);

    sorted_a.push_back(a[pivot]);

    for(int i = 0; i < sorted_c.size(); i++) sorted_a.push_back(sorted_c[i]);


    return sorted_a;
}

int main()
{
    vector <int> arr;

    int n;
    cin >> n;

    arr.resize(n);

    for(int i = 0; i < n; i++){ cin >> arr[i]; }

    vector <int> result = quick_sort(arr);

    for(int i = 0; i < n; i++){ cout << result[i] << " "; }

    return 0;
}
