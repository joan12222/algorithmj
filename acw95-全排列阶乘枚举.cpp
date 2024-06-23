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
//k��ʾ�ŵ���k�����������6�� 
void dfs(int k) {
	if(k>=7) return;
	for(int i=0;i<25;i++) {
		if(!vis[i]) {
			int backup=now;
			now=build(now,i);
			if(step.count(now)&&k>=step[now]) {
				//��ǰ��û��Ҫ������ʡһ�ΰ��� 
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

