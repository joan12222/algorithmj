#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q,n;
int a[50005]; 
//���������ֵ����Сֵ 
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		int ans=1e9;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}		
		for(int i=1; i<n; i++) {
			ans=min(ans,max(a[i], a[i+1]));
		}		
		cout<<(ans-1) <<endl;
	}
	return 0;
}

