#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int a[MAXN];
map<int, int> mp;

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;
		mp.clear();
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			mp[a[i]]++;
		}
		if(mp.size()>2) cout<<"NO"<<endl;
		else if(mp.size()==1) cout<<"YES"<<endl;
		else {
			bool yes=true;
			for(auto &pair:mp) {
				if(abs(pair.second-mp[a[1]])>1) {
					yes=false;
					break;
				}
			}
			if(yes) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
} 
