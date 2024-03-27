#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int sz = str.size();

    if(sz == 1){
        cout << "YES\n";
        return 0;
    }
    char temp1 = ' ';
    // amadm
    for(int i = 0; i < sz; i++){
        int cnt = 0;

        for(int j = 0; j < sz; j++){
            if(str[i] == str[j]){
                cnt ++;
            }
        }
        if(cnt == 1 && temp1 == ' '){
            temp1 = str[i];
            // cout << temp1 <<"\n";
        }
        else if(cnt == 1 && temp1 != ' '){
            // cout << temp1 << " > " << str[i] <<"\n";
            cout << "NO\n";
            return 0;
        }
        else{
            if(cnt % 2 != 0){
                //cout << str[i] << "\n";
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}
