#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct Node {
	int r; //过期时间 
	int e; //值 
	Node(int _r, int _e) {
		r=_r,e=_e;
	}
};
deque<Node> q;
int f[100005];
int c[100005][2];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		int v,w,t;
		cin>>v>>w>>t;
		//mod,余数，对每一类进行转移,
		//假设某种物品重量为4，有5个，  
		//j:第几类 
		//假设j为1，可以转移到5,9,13,17,下标分别对应2,3,4,5,下标为k+1 
		for(int j=0;j<v;j++) {
//			int k=0,l=1;
			//x:取几个01背包,也是单调队列的下标 
			for(int p=j,x=1;p<=m;p+=v,x++) { //结束条件：m/v 
				int e=f[p]-x*w,r=x+t; 
				//老的值又小的，直接删除
//				for(;k>=l&&c[k][0]<=e;--k); 
				while(!q.empty()&&(q.back().e<=e)) q.pop_back();
				//每一类中的p可以转移到k+1到k+t,即k+t过期 
//				c[++k][0]=e;c[k][1]=r;
				q.push_back(Node(r, e));
//				f[p]=c[l][0]+x*w;
				f[p]=q.front().e+x*w;
//				for(;k>=l&&c[l][1]==x;++l);
				while(!q.empty()&&(q.front().r==x)) q.pop_front();
			}
		}
	}
	cout<<f[m]<<endl;
	return 0;
}

