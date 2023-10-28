#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2, a;
    cin >> n1;
    set <int> st;

    for(int i = 0; i < n1; i++){
        cin >> a;
        st.insert(a);
    }

    cin >> n2;

    for(int i = 0; i < n2; i++){
        cin >> a;
        st.insert(a);
    }

    for(auto i:st){
        cout << i << " ";
    }
    cout <<"\n";

    return 0;
}
