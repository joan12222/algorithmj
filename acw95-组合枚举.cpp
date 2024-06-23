#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define ll long long
queue<int> q;
int now;
bool vis[30];
#define MAXN 25
int cnt;
unordered_map<int, int> step; //unordered_map(based on hash) faster than map(based on balance tree)
int build(int x, int p) {
	x^=1<<p;
	if(p%5) x^=1<<(p-1);
	if(p>=5) x^=1<<(p-5);
	if(p%5!=4) x^=1<<(p+1);
	if(p<20) x^=1<<(p+5);
	return x;	
}
//k��ʾö�ٵ��ڼ���������ൽ25 
void dfs(int k, int now) {
	if(cnt>6||(cnt+MAXN-k+1<6)) return; 
	if(k==MAXN+1) return;
	//���� 
	int next=build(now,k-1);
	//������ǰ�� 
	dfs(k+1, now);  

	if(!step.count(next)||cnt+1<step[next]) {
		cnt++;
		step[next]=cnt;
//		int backup=now;
//		now=next;
		dfs(k+1, next);
		cnt--;
//		now=backup;
	} else {
		dfs(k+1, now);
	}
}
int main(){
	freopen("acw95.in","r",stdin);
	freopen("acw95.out","w",stdout);
	int t;
	cin>>t;
	now=(1<<25)-1;
	step[now]=0;
	dfs(1,now);
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

