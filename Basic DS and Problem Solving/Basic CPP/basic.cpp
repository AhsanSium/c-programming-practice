#include<iostream>
using namespace std;

int main()
{
    cout<<"Hello World"<<endl;

//    int x, y;
//
//    cin >> x;
//
//    cout << x<< endl;
//
//    cin >> x >> y;
//
//    cout << "X = "<< x << " Y = "<< y << endl;

    string s, s1, s2;

    //cin >> s1 >> s2;

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "a", stdout);

    getline(cin, s1);

    getline(cin, s2);

    s = s1 +" "+ s2;

    cout << "\n" << s << endl;

    return 0;
}
