#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n,k;
string s;
string t;
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		cin>>s;
		t="";
		t+=s[0];
		for(int i=0;i<n-1;i++) {
			if((s[i]=='0')&&s[i+1]==s[i]) continue;
			t+=s[i+1];
		}
		int c0=0,c1=0;
		for(auto c:t) {
			if(c=='0') c0++;
			else c1++;
		}
		cout<<((c0<c1)?"YES":"No")<<endl;		
	}
	return 0;
}

