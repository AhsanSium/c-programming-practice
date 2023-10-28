#include<bits/stdc++.h>
using namespace std;

deque <int> sort_using_deque(deque<int>a, int sz)
{
    deque <int> dq;

    for(int i = 0; i < sz && a.size()>0; i++){

        if(a.front() < a.back()){
            dq.push_back(a.front());
            a.pop_front();
        }
        else{
            dq.push_back(a.back());
            a.pop_back();
        }
    }

    return dq;
}

int main()
{
    int n, x;
    deque<int>input;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        input.push_back(x);
    }

    deque <int> output = sort_using_deque(input, n);

    for(int i = 0; i < n; i++){
        cout << output[i] << " ";
    }
    cout <<"\n";

    return 0;
}
