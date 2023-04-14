#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	//sort(a.begin(),a.end());

	vector<int>d[n+1];

    for(int i=1 ; i<=n ; i++)
        for(int j=i ; j<=n ; j = j+i )
            d[j].push_back(i);

	for(int i=1 ; i<=n ; i++){
        for(int j=i ; j<=n ; j = j+i ){
            cout << d[j][i] << " ";
        }
        cout << "\n";
	}

//    int ans = 0;
//	for(int i=1 ; i<=n ; i++){
//	    //cout << "a[i]= " << a[i] << "a[i-1]" << a;
//	    if(i == n){ ans ++; continue; }
//		if(a[i]!=a[i-1])
//			ans++;
//    }
	//cout<< "\n"<<ans;
	return 0;
}


