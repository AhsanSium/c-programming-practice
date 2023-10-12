#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);

    deque <char> dq;
    for(int i = 0; i < s.size(); i++){
        dq.push_back(s[i]);
    }

    for(int i = 0; i < s.size()/2; i++){
        if(dq.front() == dq.back()){
            cout<<"Front "<< dq.front() << " , Back "<< dq.back() <<" \n";
            dq.pop_front();
            dq.pop_back();
        }
        else{
            cout<<"No\n";
            return 0;
        }
    }

    cout <<"Yes\n";


    return 0;
}

