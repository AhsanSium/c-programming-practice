#include<bits/stdc++.h>
using namespace std;

int main()
{
    //built in stack
    stack <char> st;
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        char now = s[i];
        if(now == '(' || now == '{' || now =='['){
            st.push(now);
        }
        else{
            if(st.empty()){
                cout << "Invalid Sequence\n";
                return 0;
            }
            if(now == ')' && st.top() == '('){
                st.pop();
            }
            else if(now == '}' && st.top() == '{'){
                st.pop();
            }
            else if(now == '}' && st.top() == '['){
                st.pop();
            }
            else{
                cout << "Invalid \n";
                return 0;
            }
        }
    }

    if(st.empty()){
        cout << "Valid Sequence !!!\n";
        return 0;
    }
    else{
        cout << "Invalid Sequence\n";
        return 0;
    }

    return 0;

}

