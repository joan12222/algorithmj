#include<bits/stdc++.h>
using namespace std;
#define MAXN 55
char s[MAXN];
char t[MAXN];
map<int, int> mp;

int main() {
	int c;
	cin>>c;

	while(c--) {
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			cin>>s[i];
		}
		for(int i=1; i<=m; i++) {
			cin>>t[i];
		}
		bool flag=true;
		bool label[3];
		memset(label, false, sizeof(label));
		for(int i=2; i<=n; i++) {
			if(s[i]==s[i-1]) {
				flag=false;
				label[s[i]-'0'] = true;
			}
		}
		if(flag) {
			cout<<"YES"<<endl;
			continue;
		}
		if(!(m%2)||(label[0]&&label[1])) {
			cout<<"NO"<<endl;
			continue;
		}
		flag=true;
		for(int i=2; i<=m; i++) {
			if(t[i]==t[i-1]) {
				flag=false;
				break;
			}
		}
		if(flag&&((label[0]&&t[1]=='1')||(label[1]&&t[1]=='0'))) {
			cout<<"YES"<<endl;
			continue;
		} else {
			cout<<"NO"<<endl; 
		}
	}
	return 0;
} 
