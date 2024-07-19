#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n;
string s1, s2;
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		cin>>s1>>s2;
		int cnt01=0,cnt10=0;
		for(int i=0;i<n;i++) {
			if(s1[i]!=s2[i]) {
				if(s1[i]=='0') cnt01++;
				else cnt10++;
			}
		}
		if(cnt01==cnt10) cout<<cnt01<<endl;
		else {
			if(cnt01>cnt10) {
				swap(cnt01, cnt10);
			}
			cout<<(cnt01+cnt10-cnt01)<<endl;
		}
	}
	return 0;
}
