#include<bits/stdc++.h>
using namespace std;

void check_bracket_sequence(string s)
{
    stack <char> st;

    for(int i = 0; i < s.size(); i++){
        char now = s[i];
        if(now == '(' || now == '{' || now =='['){
            st.push(now);
        }
        else{
            if(st.empty()){
                cout << "No\n";
                return;
            }
            if(now == ')' && st.top() == '('){
                st.pop();
            }
            else if(now == '}' && st.top() == '{'){
                st.pop();
            }
            else if(now == ']' && st.top() == '['){
                st.pop();
            }
            else{
                cout << "No\n";
                return;
            }
        }
    }

    if(st.empty()){
        cout << "Yes\n";
        return;
    }
    else{
        cout << "No\n";
        return;
    }
}

int main()
{
    string s;
    cin >> s;

    check_bracket_sequence(s);

    return 0;

}


