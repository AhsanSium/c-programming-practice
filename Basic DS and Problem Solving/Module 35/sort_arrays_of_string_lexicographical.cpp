#include<bits/stdc++.h>
using namespace std;

vector <string> merge_sort(vector<string> s)
{
    // Base case
    if(s.size() <= 1) {return s;}

    // Divide 2 part
    vector <string> s1;
    vector <string> s2;
    int mid  = s.size() / 2;

    for(int i = 0; i < mid; i++){ s1.push_back(s[i]);}

    for(int i = mid; i < s.size(); i++){ s2.push_back(s[i]);}

    // Conquer
    vector<string> sorted_s1 = merge_sort(s1);
    vector<string> sorted_s2 = merge_sort(s2);

    vector<string> sorted_s;

    int idx1 = 0; int idx2 = 0;

    for(int i = 0; i < s.size(); i++){

        if(idx1 == sorted_s1.size()){
            sorted_s.push_back(sorted_s2[idx2]);
            idx2 ++;
        }
        else if(idx2 == sorted_s2.size()){
            sorted_s.push_back(sorted_s1[idx1]);
            idx1++;
        }
        else if(sorted_s1[idx1].compare(sorted_s2[idx2]) < 0){
            sorted_s.push_back(sorted_s1[idx1]);
            idx1++;
        }
        else{
            sorted_s.push_back(sorted_s2[idx2]);
            idx2++;
        }
    }

    return sorted_s;
}

int main()
{
    int sz = 0;
    cin >> sz;
    vector <string> input(sz);

    for(int i = 0; i < sz; i++){
        cin >> input[i];
    }

    vector <string> output = merge_sort(input);

    for(int i = 0; i < sz; i++){
        cout << output[i]<< " ";
    }
    cout << "\n";

    return 0;
}
