#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
string s;
set<char> se;
ll ans;
//bcdaaaabcdaaaa
//
int main() {
	cin>>t;
	while(t--) {
		cin>>n;
		cin>>s;
		ans=0;
		se.clear();
		for(int i=0;i<s.size();i++) {
			if(!se.count(s[i])) {
				se.insert(s[i]);
				ans+=n-i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

