#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int mp[MAXN];
char a[MAXN];

/*
7
##....#

*/

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;
		int e1=0, e2=0, e3=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		a[0]='#';
		a[n+1]='#';
		int prev=0; 
		for(int i=1; i<=n+1; i++) {
			if(a[i]=='#') {
				if((i-prev)==2)	{
					e1++;
				}else if((i-prev)==3) {
					e2++;
				}else if((i-prev)>=4) {
					e3++;
				}
				prev=i;
			}
		}
		if(e3) cout<<2<<endl;
		else cout<<2*e2+e1<<endl;
	}
	return 0;
} 
