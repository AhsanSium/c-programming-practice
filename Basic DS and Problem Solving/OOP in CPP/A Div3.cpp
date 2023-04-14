#include <bits/stdc++.h>
#include <string>
using namespace std;


int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t > 0){

        int n, flag;
        string str;
        cin >> n;
        cin >> str;

        flag = 1;

        if(n < 4){
            flag = 0;
            cout << (flag == 1 ? "YES\n" : "NO\n");
            t--;
            continue;
        }



        // using transform() function and ::tolower in STL
        transform(str.begin(), str.end(), str.begin(), ::tolower);

        string str2 = "meow";

        if (str.find("m") != string::npos && str.find("e") != string::npos && str.find("o") != string::npos && str.find("w") != string::npos ) {
            //cout << "found!" << '\n';
        }
        else{
            flag = 0;
            cout << (flag == 1 ? "YES\n" : "NO\n");
            t--;
            continue;
        }

        for(int i = 0; i < n - 1; i++)
        {
            if(str[0] != 'm'){
                flag = 0;
                break;
            }
            if(str[i] == 'm'){
                if(str[i + 1] == 'm' || str[i + 1] == 'e'){
                    flag = 1;
                }
                else{
                    flag = 0;
                    break;
                }
            }

            if(str[i] == 'e'){
                if(str[i + 1] == 'e' || str[i + 1] == 'o'){
                    flag = 1;
                }
                else{
                    flag = 0;
                    break;
                }
            }

            if(str[i] == 'o'){
                if(str[i + 1] == 'o' || str[i + 1] == 'w'){
                    flag = 1;
                }
                else{
                    flag = 0;
                    break;
                }
            }

            if(str[i] == 'w'){
                if(str[i + 1] == 'w'){
                    flag = 1;
                }
                else{
                    flag = 0;
                    break;
                }
            }
        }

        cout << (flag == 1 ? "YES\n" : "NO\n");

        t--;
    }

    return 0;
}

