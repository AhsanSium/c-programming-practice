#include<bits/stdc++.h>
using namespace std;

vector <int> quickSort( vector <int> a)
{
    //base case
    int sz = a.size();
    if(sz <= 1) return a;

    //divide
    int pivot = rand()%(sz);
    vector <int> b,c;

    for(int i = 0; i < sz; i++){
        if(i == pivot) continue;

        if(a[i] <= a[pivot]) b.push_back(a[i]);
        else c.push_back(a[i]);
    }

    vector <int> sorted_b = quickSort(b);
    vector <int> sorted_c = quickSort(c);

    //conquer
    vector <int> sorted_a;

    for(int i = 0; i < sorted_c.size(); i++) sorted_a.push_back(sorted_c[i]);
    sorted_a.push_back(a[pivot]);
    for(int i = 0; i < sorted_b.size(); i++) sorted_a.push_back(sorted_b[i]);

    return sorted_a;
}

int main()
{
    vector <int> input, output;
    int n;
    cin >> n;
    input.resize(n);

    for(int i = 0; i < n; i++) cin >> input[i];

    output = quickSort(input);

    for(int i = 0; i < n; i++) cout << output[i] << " ";

    return 0;
}
