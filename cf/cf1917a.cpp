#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
ll a[105];
int main() {
	cin>>t;
	while(t--) {
		int weight=0;
		cin>>n;
		bool flag=false;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=1;i<=n;i++) {
			if(a[i]==0) {
				flag=true;
				break;
			}
			if(a[i]<0) weight++;
		}
		//有0
		//无0，奇数个负数 
		if(flag || weight%2) {
			cout<<0<<endl;
			continue; 
		}
		cout<<1<<endl;
		cout<<1<<" "<<0<<endl;
	}
	return 0;
}

