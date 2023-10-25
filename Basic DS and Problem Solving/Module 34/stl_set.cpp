#include <bits/stdc++.h>
using namespace std;

int main()
{
    set <int> st;
    st.insert(5);
    st.insert(3);
    st.insert(4);
    st.insert(7);
    st.insert(3);
    st.insert(4);

    // int x = 4;
    // auto y = x;
    // Print set
    for(auto i: st)
        cout << i << " ";
    cout <<"\n";

    cout <<"Set size "<<st.size();
    cout << "\n";

    st.erase(5);

    for(auto it = st.begin(); it != st.end(); it++){
        cout << *it << " ";
    }
    cout << "\n";

    if(st.find(7) != st.end()){
        cout << "7 found";
    }

    return 0;
}
