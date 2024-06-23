#include<bits/stdc++.h>
using namespace std;
#define MAXN 55
int a[MAXN];
int power2[10]={1,2,4,8,16,25,36};
bool check(int l, int r) {
	if(l==r) return true;
	for(int i=l; i<r; i++) {
		if(a[i]>a[i+1]) return false;
	}
	return true;
}
int main() {
	int c;
	cin>>c;
	while(c--) {
		int n;
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		int m=sqrt(n);
		bool flag=true;
		int prev=1;
		for(int i=0; i<=m; i++) {
			if(!check(prev,power2[i])) {
				flag=false;
				break;
			}
			prev=power2[i]+1;
		}
		
		if(flag&&check(prev, n)) {
			cout<<"YES"<<endl; 
			continue;
		}
		cout<<"NO"<<endl; 
	}
	
	return 0;
} 
