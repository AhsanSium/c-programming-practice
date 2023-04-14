#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;cin>>T;
	while(T--){
		string a,b;int x,y;
		cin>>x>>y>>a>>b;
		reverse(b.begin(),b.end());
		string s=a+b;int cnt=0;
		cout << "\n S = " << s << "\n";

		for(int i=0;i+1<(int)s.size();i++){
			if(s[i]==s[i+1])cnt++;
		}
		puts(cnt>1?"NO":"YES");
	}
	return 0;
}
