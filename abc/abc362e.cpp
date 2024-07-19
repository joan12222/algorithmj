#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int a[105];
int f[105][105][105];
#define MOD 998244353
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		f[i][i][1]=1;
	}
	for(int i=2;i<=n;i++) {
		for(int j=i-1;j>0;j--) {
			f[i][j][2]=1;
		}
	}
	for(int i=3;i<=n;i++) {
		for(int j=2; j<i; j++) {
			for(int k=3;k<=n;k++) {
				//a[i]-a[j]=a[j]-a[p],p<j //最后一个元素为i，倒数第二个为j，倒数第三个为p 
				for(int p=j-1;p>0;p--) {
					if(a[p]==2*a[j]-a[i]) {
						f[i][j][k] = (f[i][j][k]+f[j][p][k-1])%MOD;
					}
				} 
			}
		}
	}
	cout<<n<<" ";
	if(n>1) cout<<(n*(n-1)/2)<<" ";
	if(n>2) {
		for(int k=3;k<=n;k++) {
			int ans=0;
			for(int i=3;i<=n;i++)
				for(int j=i-1;j>0;j--)
					ans=(ans+f[i][j][k])%MOD;
			cout<<ans<<" ";
		}
	}
	return 0;
} 
/*
int a[105];
int d[105][105];
int ans[105];
map<int, vector<pair<int, int> > > m;
vector<int> edges[105];
set<int> st;
bool vis[105];
void dfs(int x) {
	//点集st，边集edges
	vis[x]=true;
	for(auto y:edges[x]) {
		if(!vis[y]) {
			depth[y]=depth[x]+1;
			dfs(y);
		}
	} 
}
 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=i+1, j<=n; j++) {
			int d=a[i]-a[j];
			m[d].push_back(make_pair(i,j);
		}
	}
	for(auto i:m) { //公差为i.first 
		edges.clear();
		st.clear();
		memset(vis, 0, sizeof(vis));
		for(auto j:m[i.first]) { //边集 
			int u=j.first, v=j.second;
			st.insert(u),st.insert(v);
			edges[u].push_back(v);
		}
		sort(st.begin(), st.end()); 
		for(int i=0;i<=st.size();i++) {
			if(!vis[st[i]]) {
				//求连通块，及深度 
				dfs(st[i]);
			}
		}
	}
	return 0;
}
*/
