//3586
#include<bits/stdc++.h>
using namespace std;
int a[210][210];
struct node {
	int x, y, step;
}
int main() {
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=M; j++) {
			cin>>a[i][j];
			if(a[i][j]=='@') {
				x1=i;
				y1=j;
			} else if(a[i][j]=='&') {
				x2=i;
				y2=j;
			}
		}
	}
	queue<node> q;
	q.push(node{x1,y1,1});
	while(q.size()) {
		
	}
	return 0;
}
//9430
#include<bits/stdc++.h>
using namespace std;
int N, A, B;
struct node{
	int x,y,step;
}
int dx[2]={-1,1};
int vis[210]={0};
int a[210];
int main() {
	cin>>N>>A>>B;
	for(int i=1; i<=N; i++) {
		cin<<a[i];
	}
	queue<node> q;
	
	q.push(node{A, 1});
	while(q.size()) {
		node now=q.front();
		q.pop();
		if(now.x==B) {
			cout<<now.step;
			return 0;
		}
		for(int i=0; i<2; i++) {
			int nx=x+dx[i]*a[x];
			if(nx>=1&&nx<B&&vis[nx]==0) {
				q.push(node{nx, now.step+1});
				vis[nx]=1;
			}
		}
	}
	cout<<-1;
	return 0;
}