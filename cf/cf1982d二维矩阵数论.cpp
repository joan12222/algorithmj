#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
int t,n,m,k;
ll a[N][N];
int b[N][N];
ll pre[N][N];
char s[N];
void solve() {
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	//计算二维前缀和
	ll sum=0;
	for(int i=1;i<=n;i++) {
		cin>>s+1;
		for(int j=1;j<=m;j++) {
			b[i][j] = s[j]=='0'? 1:-1;
			sum+=a[i][j]*b[i][j];
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+b[i][j];
		}
	}
	//计算每个k*k矩阵和 ,求他们的gcd 
	int g=-1;
	for(int i=k;i<=n;i++) {
		for(int j=k; j<=m; j++) {
			int num=abs(pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k]);
			//ax+by=c<=>d|c,d=gcd(a,b)
			if(g==-1) g=num;
			g=__gcd(g,num);
		}
	}
	if(sum==0||(g!=0&&abs(sum)%g==0)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

int main() {
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}


