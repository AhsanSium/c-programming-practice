#include<bits/stdc++.h>
using namespace std;

int n;

vector <int> mergeSortFindPair( vector <int> a, int k)
{
    //base case
    int sz = a.size();
    if(sz <= 1) return a;

    //divide
    int mid = sz/2;
    vector <int> b,c;

    for(int i = 0; i < mid; i++) b.push_back(a[i]);
    for(int i = mid; i < sz; i++) c.push_back(a[i]);

    vector <int> sorted_b = mergeSortFindPair(b, k);
    vector <int> sorted_c = mergeSortFindPair(c, k);

    //conquer
    vector <int> sorted_a;

    int idx1 = 0, idx2 = 0;

    for( int i = 0; i < sz; i++ ){

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

    if(sorted_a.size()== n)
    {
        int i=0,j=n-1,cnt=0;
        while(i<j)
        {
            if((sorted_a[i]+sorted_a[j])>k)  j--;

            else if((sorted_a[i]+sorted_a[j])<k)  i++;

            else { cnt++; i++; j--; }
        }
        cout<<cnt<<"\n";

    }


    return sorted_a;
}

int main()
{
    vector <int> input , output;
    int k;
    cin >> n;
    input.resize(n);

    for(int i = 0; i < n; i++) cin >> input[i];

    cin >> k;

    output = mergeSortFindPair(input, k);

    return 0;
}

