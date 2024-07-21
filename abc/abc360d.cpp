#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,t;
int pos[100005];
string s;
vector<int> a;
vector<int> b;
int main() {
	cin>>n>>t;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n; i++) cin>>pos[i];
	for(int i=1;i<=n; i++) {
		if(s[i]=='0') a.push_back(pos[i]);
		if(s[i]=='1') b.push_back(pos[i]);
	}
	sort(a.begin(), a.end());
	int posl, posr;
	ll ans=0;
	for(auto y:b) {
		posl=lower_bound(a.begin(), a.end(), y)-a.begin();
		posr=upper_bound(a.begin(), a.end(), 2*t+y)-a.begin()-1;
		ans+=posr-posl+1;
	}
	cout<<ans<<endl;
	return 0;
}


