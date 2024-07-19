#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 500005
int q;
int n; 
string s1, s2;
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		cin>>s1>>s2;
		bool h1=false;
		if(s1==s2) {
			cout<<"YES"<<endl;
			continue;
		}
		for(int i=0; i<n; i++) {
			if(s1[i]=='1') h1=true;
			if(s1[i]!=s2[i]) {
				if(h1) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
				break;
			}
		}
	}
	return 0;
}
