#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string str;
    cin >> n;
    map <string, int> mp;

    for(int i = 1; i <= n; i++){

        cin >> str;

        if(mp[str] == 0){
            cout << "-1" <<"\n";
            mp[str] = i;
        }
        else{
            cout << mp[str] - 1 <<"\n";
            mp[str] = i;
        }


    }

    return 0;
}
