#include<bits/stdc++.h>
using namespace std;

vector<int> even_generator(vector<int>a)
{
    vector<int>b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]%2==0)
        {
            b.push_back(a[i]);
        }
    }
    return b;
}

int main()
{

    vector<int>arr{1,3,3,5,8,6,10,14};

    vector<int> result=even_generator(arr);

    for(int i=0;i<result.size();i++)
    {
        cout<<result[i]<<" ";
    }

    return 0;
}

