#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int v[1001],w[1001],f[1001];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>v[i]>>w[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=v[i]; j<=m; j++) {
			f[j]=max(f[j], f[j-v[i]]+w[i]);
		}
	}
	int ans=0;
	//ʵ���ϲ���Ҫö��1��m����Ϊ����m��ֵ�ѱ����� 
	for(int i=1; i<=m; i++) {
		ans=max(ans, f[i]);
	}
	cout<<ans;
	return 0;
}

