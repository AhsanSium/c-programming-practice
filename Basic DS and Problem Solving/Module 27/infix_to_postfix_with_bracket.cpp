#include<bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if(ch == '+' || ch == '-'){
        return 0;
    }
    if(ch == '*' || ch == '/'){
        return 1;
    }
    return -1;
}

int main()
{
    string s;
    cout << "Enter infix expression: ";
    cin >> s;
    stack<char>st;
    string ans = "";

    for(int i = 0; i < s.size(); i++){

        char now = s[i];
        if(now >= 'a' && now <= 'z'){
            ans += now;
        }
        else{
            while(st.size() && now != '(' && now != ')' && prec(st.top()) >= prec(now) && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.push(now);

            if(st.top() == ')'){
                st.pop();
                ans += st.top();
                st.pop();
                st.pop();
            }
        }

    }


    while(st.size()){
        ans += st.top();
        st.pop();
    }

    cout << "\nPostfix expression: "<< ans <<"\n";

    return 0;
}

