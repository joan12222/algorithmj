#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[5];
int main(){
	int m, r;
	for(int i=1;i<=3;i++) {
		cin>>s[i];
		if(s[i]=='M') m=i;
		if(s[i]=='R') r=i;
	}
	if(r<m) cout<<"Yes";
	else cout<<"No";
	return 0;
}
