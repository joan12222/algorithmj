#include<bits/stdc++.h>
using namespace std;
char a[50],b[22];
int main() {
	int c;
	cin>>c;
	while(c--) {
		int n,m;
		cin>>n>>m;
		int nstart=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=1;i<=m;i++) {
			cin>>b[i];
		}
		for(int i=n+1,j=m;j>=1;j--,i++) {
			a[i] = b[j];
		}
		for(int i=1; i<m+n; i++) {
			if(a[i]==a[i+1]&&i!=m+n-1) {
				nstart=i+1;
				break;
			}
		}
		if(!nstart) {
			cout<<"YES"<<endl;
			continue;
		}
		for(int i=nstart; i<m+n;i++) {
			if(a[i]==a[i+1]) {
				nstart=m+n;
				break; 
			}
		}
		if(nstart==m+n) {
			cout<<"NO"<<endl;	
			continue;
		}			
		cout<<"YES"<<endl;
	}
	return 0;
} 
