#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
vector<int> edges[200005];
int c[200005];
int a[200005];
int f[200005][2];
queue<int> q;
int bfs() {
	//有点像双指针 
	c[1]=1;
	for(int k=1,l=1;l<=k;l++) {
		int now=c[l];
		for(auto y: edges[now]) {
			c[++k]=y;
		}
	}
}
int main() {
	cin>>n;
	for(int i=2; i<=n; i++) {
		int x;
		cin>>x;
		edges[x].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	bfs();
	//数组里存放着bfs序，也就是确定了状态转移的顺序：从后往前计算快乐值 
	for(int i=n; i; i--) {
		int now=c[i];
		f[now][1]=a[c[i]];
		for(auto y: edges[now]) {
			f[now][0]+=max(f[y][1],f[y][0]);
			f[now][1]+=f[y][0];
		}		
	}
	for(int i=1; i<=n;i++) {
		cout<<f[i][0]<<" "<<f[i][1]<<endl;
	}
	cout<<max(f[1][0],f[1][1]);
	return 0;
}

