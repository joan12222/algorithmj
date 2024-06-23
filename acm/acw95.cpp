#include<bits/stdc++.h>
using namespace std;
#define ll long long
queue<int> q;
unordered_map<int, int> vis; //unordered_map(based on hash) faster than map(based on balance tree)
int build(int x, int p) {
	x^=1<<p;
	if(p%5) x^=1<<(p-1);
	if(p>=5) x^=1<<(p-5);
	if(p%5!=4) x^=1<<(p+1);
	if(p<20) x^=1<<(p+5);
	return x;	
}
void bfs() {
	int now=(1<<25)-1;
	q.push(now);
	vis[now]=1;
	while(!q.empty()) {
		int top=q.front();
		q.pop();
		if(vis[top]>=7) {
			break;
		}
		for(int i=0;i<25;i++) {
			int now=build(top, i);
			if(!vis.count(now)) { // not vis[now]
				vis[now]=vis[top]+1;
				q.push(now);
			}
		}
	}
}
int main(){
	int t;
	cin>>t;
	bfs();
	while(t--) {
		int s=0;
		for(int i=0;i<25;i++) {
			char c;
			cin>>c;
			s+=(c-'0')<<i;
		}
		//从全1走到s的步数 
		cout<<vis[s]-1<<endl;
	}
	return 0;
}

