#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 105
ll k,x,a;
int t;

void solve() {
	cin>>k>>x>>a;
	ll temp=a; //֮ǰ���� 
	ll sum=0;//֮ǰ������Ǯ��֮ǰ�������� 
	ll now;//���ִ���ŵ�Ǯ 
	for(int i=1; i<=x+1; i++) {
		if(i==x+1) now=a; // all in
		else now=sum/(k-1)+1; //sum+now<now*k now>sum/(k-1) ÿ�α�֤�����Ӯ�Ļ�����������������Է��������� 
		a-=now;
		if(a<0) {
			cout<<"No"<<endl;
			return;
		}
		sum+=now; 
	}
	a+=now*k;
	if(a<=temp) cout<<"No"<<endl;
	else cout<<"Yes"<<endl; 
}
int main() {
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
} 
