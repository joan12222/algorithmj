#include<bits/stdc++.h>
using namespace std;
#define MAXN 60
int t,n,x,y;
void solve() {
	cin>>n>>x>>y;
	//����ȫ��ֵ-1������y�������x������С 
/*	for(int i=1; i<y; i++) {
		cout<<-1<<" ";
	}
*/
	for(int i=1; i<=n; i++) {
		int a;
		if(i<y) {
			a= (y-i)%2 ? -1 : 1;
		} else if(i<=x) {
			a=1;
		} else {
			a=(i-x)%2 ? -1 :1;
		}
		cout<<a<<" ";
	}
	cout<<endl;
}
int main() {
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
} 
