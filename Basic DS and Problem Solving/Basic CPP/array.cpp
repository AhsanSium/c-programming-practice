#include <bits/stdc++.h>
#include<vector>

using namespace std;

int check_unique( vector <char> a )
{
    int uniq = 1;
    for(int i = 0; i < a.size() - 1; i++){
          if( a[i] == a[i+1] )
          {
              uniq = 0;
          }
    }

    return uniq;
}

int main()
{
    int t;
    cin >> t;

    while( t > 0 )
    {
        int n, m;
        cin >>n>>m;

        //cout << n << "  "<< m << endl;

        vector <char> a;
        vector <char> b;

        char c;

        for(int i = 0; i < n; i++){
            cin >> c;
            a.push_back(c);
        }

        for(int i = 0; i < m; i++){
            cin >> c;
            b.push_back(c);
        }

//        for(int i = 0; i < a.size(); i++){
//          cout << a[i] << " ";
//        }
//
//        //cout << "\n";
//
//        for(int i = 0; i < b.size(); i++){
//          cout << b[i] << " ";
//        }


        //cout << "\n" << check_unique( a ) << "  "<< check_unique( b ) << endl;

        //cout << a[n] << "  " << b[m] << endl;

        if( check_unique( a ) && check_unique( b ) == 1 ){
            cout << "YES\n";
        }
        else if(a[n - 1] == b[m - 1]){
            cout <<"NO\n";
        }
        else{
            int flag1 = 1, flag2 = 1;
            vector <char> c;
            vector <char> d;

            c = a;
            d = b;

            for(int i = 0; i < n; i++)
            {

                d.push_back(c.back());
                c.pop_back();

                cout << "C last = " <<c.back();
                cout << "  D Last " << d.back();
                cout << "\n";
                if(c.back() == d.back() && c.size() > 1){
                    flag1 = 0;
                    break;
                }
            }

            cout << "\n";

            for(int i = 0; i < m; i++)
            {
                cout << b.back() << " ";
                a.push_back(b.back());
                b.pop_back();
                if(b.back() == a.back() && b.size()  > 1){
                    flag2 = 0;
                    break;
                }
            }

            cout << "\n Flag 1 && Flag 2 =  " << flag1 << "  " << flag2 << "\n";

            if(flag1 && flag2 == 0)
            {
                cout <<"NO\n";
            }
            else{
                cout << "YES\n";
            }
        }


        t --;
    }
}
