#include<bits/stdc++.h>
using namespace std;

int main()
{
    //built in stack
    stack <int> st;

    //push O(1)
    st.push(10);
    st.push(12);
    st.push(32);
    st.push(22);
    st.push(28);

    cout << "Top: "<< st.top()<<"\n";

    //pop O(1)
    st.pop();
    st.pop();

    cout << "Top: "<< st.top()<<"\n";

    //size O(1)
    cout << "Size: "<< st.size()<<"\n";

    return 0;

}
