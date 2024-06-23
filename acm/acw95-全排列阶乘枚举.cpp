#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define ll long long
queue<int> q;
int now;
bool vis[30];
unordered_map<int, int> step; //unordered_map(based on hash) faster than map(based on balance tree)
int build(int x, int p) {
	x^=1<<p;
	if(p%5) x^=1<<(p-1);
	if(p>=5) x^=1<<(p-5);
	if(p%5!=4) x^=1<<(p+1);
	if(p<20) x^=1<<(p+5);
	return x;	
}
//k表示排到第k个数，最多排6个 
void dfs(int k) {
	if(k>=7) return;
	for(int i=0;i<25;i++) {
		if(!vis[i]) {
			int backup=now;
			now=build(now,i);
			if(step.count(now)&&k>=step[now]) {
				//当前灯没必要按，节省一次按灯 
				//vis[i]=true; 
				now=backup;
				continue;
			}
			vis[i]=true;
			step[now]=k;
			dfs(k+1);
			vis[i]=false;
			now=backup;
		} 
	}
}
int main(){
	//freopen("acw95.in","r",stdin);
	//freopen("acw95.out","w",stdout);
	int t;
	cin>>t;
	now=(1<<25)-1;
	step[now]=0;
	dfs(1);
	while(t--) {
		int s=0;
		for(int i=0;i<25;i++) {
			char c;
			cin>>c;
			s+=(c-'0')<<i;
		}
		cout<<((step.count(s)) ? step[s] : -1)<<endl;
	}
	return 0;
}

