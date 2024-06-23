//P1825 - Not AC
#include<bits/stdc++.h>
using namespace std;
char a[310][310];
int vis[310][310]={0};
struct node{
	int x,y,step;
};
node magic[30][2];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	int sx,sy,ex,ey;
	memset(magic, 0, sizeof magic);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf(" %c", &a[i][j]);
			if(a[i][j]=='@') sx=i,sy=j;
			if(a[i][j]=='=') ex=i,ey=j;
			if(a[i][j]>='A'&&a[i][j]<='Z') {
				if(magic[a[i][j]-'A'][0].x!=0) {
					magic[a[i][j]-'A'][1].x=i;
					magic[a[i][j]-'A'][1].y=j;
				}else {
					magic[a[i][j]-'A'][0].x=i;
					magic[a[i][j]-'A'][0].y=j;					
				}
			}
		}
	}
	queue<node> q;
	q.push(node{sx,sy,0});
	vis[sx][sy]=1;
	while(q.size()) {
		node now=q.front();
		q.pop();
		if(now.x==ex&&now.y==ey) {
			cout<<now.step;
			return 0;
		}
		/*
		if(a[now.x][now.y]>='A'&&a[now.x][now.y]<='Z') {	
			int nx,ny;
			if(magic[idx][0].x==now.x&&magic[idx][0].y==now.y) {
				nx=magic[idx][1].x;
				ny=magic[idx][1].y;
			} else if (magic[idx][1].x==now.x&&magic[idx][1].y==now.y) {
				nx=magic[idx][0].x;
				ny=magic[idx][0].y;
			} else {
				cout<<"ERROR"<<endl;
				return 0;
			} 
			if(vis[nx][ny]==0) {
				vis[nx][ny]=1;
//				while(!q.empty()) q.pop();
				q.push(node{nx,ny,now.step});
				continue;
			}
		}
		*/
		for(int i=0; i<4; i++) {
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&vis[nx][ny]==0&&a[nx][ny]!='#') {
				vis[nx][ny]=1;
				if(a[nx][ny]>='A'&&a[nx][ny]<='Z') {
					int idx=a[nx][ny]-'A';
					if(magic[idx][0].x==nx&&magic[idx][0].y==ny) {
						nx=magic[idx][1].x;
						ny=magic[idx][1].y;
					} else if (magic[idx][1].x==nx&&magic[idx][1].y==ny) {
						nx=magic[idx][0].x;
						ny=magic[idx][0].y;
					} else {
						cout<<"ERROR"<<endl;
						return 0;
					}
					if(vis[nx][ny]) continue;
				}
				vis[nx][ny]=1;
				q.push(node{nx,ny,now.step+1});
			}
		}
	}
	return 0;
}
/*
//P1746
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int vis[1010][1010]={0};
struct node{
	int x,y,step;
};
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s", a[i]);
	}
	int sx,sy,ex,ey;
	scanf("%d%d%d%d", &sx,&sy,&ex,&ey);
	queue<node> q;
	q.push(node{sx-1,sy-1,0});
	vis[sx-1][sy-1]=1;
	while(q.size()) {
		node now=q.front();
		q.pop();
		if(now.x==(ex-1)&&now.y==(ey-1)) {
			printf("%d\n", now.step);
			return 0;
		}
		for(int i=0; i<4; i++) {
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<n&&a[nx][ny]!='1'&&vis[nx][ny]==0) {
				q.push(node{nx,ny,now.step+1});
				vis[nx][ny]=1;
			}
		}
	}
	return 0;
}

//P1747
#include<bits/stdc++.h>
using namespace std;
//int dx[8]={2,2,-2,-2,1,1,-1,-1};
//int dy[8]={-1,1,-1,1,2,-2,2,-2};
int dx[]={-2,-2,-1,-1,1,1,2,2,2,2,-2,-2};
int dy[]={-1,1,-2,2,-2,2,-1,1,2,-2,2,-2};
const int MAX=100;
int vis[MAX][MAX]={0};
struct node{
	int x,y,step;
};
void bfs(int ex, int ey) {
	int sx=1,sy=1;
	queue<node> q;
	q.push(node{1,1,0});
	memset(vis, 0, sizeof vis);
	vis[1][1]=1;	
	while(q.size()) {
		node now=q.front();
		q.pop();
		if(now.x==ex&&now.y==ey) {
			cout<<now.step<<endl;
			return;
		}
		for(int i=0; i<12; i++) {
			int nx=now.x+dx[i];
			int ny=now.y+dy[i];
			if(nx>=1&&nx<MAX&&ny>=1&&ny<MAX&&vis[nx][ny]==0) {
				q.push(node{nx,ny,now.step+1});
				vis[nx][ny]=1;
			}
		}
	}
}
int main() {
	int x1, y1;
	int x2, y2;
	cin>>x1>>y1;
	cin>>x2>>y2;
	bfs(x1,y1);
	bfs(x2,y2);
	return 0;
}

//P1443
#include<bits/stdc++.h>
using namespace std;
int ans[410][410];
//int dx[8]={2,2,-2,-2,1,1,-1,-1};
//int dy[8]={-1,1,-1,1,2,-2,2,-2};
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};
struct node{
	int x,y;
};
int main() {
	int n,m,sx,sy;
	scanf("%d%d%d%d", &n,&m,&sx,&sy);
	memset(ans, -1, sizeof ans);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(ans[i][j]!=-1) {
				continue;
			}
			queue<node> q;
			q.push({sx, sy});
			ans[sx][sy]=0;
			while(q.size()) {
				node now=q.front();
				q.pop();
				for(int k=0; k<8; k++) {
					int nx=now.x+dx[k];
					int ny=now.y+dy[k];
					if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&ans[nx][ny]==-1) {
						q.push(node{nx, ny});
						ans[nx][ny]=ans[now.x][now.y]+1;
					}
				}			
			}
		}
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}

//P1141
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
struct node {
	int x,y;
};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int vis[1010][1010]={0};
//int cnt[1010][1010]={0};

int main() {
	int n, m;
//	cin>>n>>m;
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; i++) {
		scanf("%s", a[i]);
	}
	memset(vis, 0, sizeof vis);
	for(int i=1; i<=m; i++) {
		int sx,sy;
		scanf("%d%d", &sx, &sy)
		if(vis[sx-1][sy-1]!=0) {
			printf("%d\n", vis[sx-1][sy-1]);
			return 0;
		}
		queue<node> q;
		queue<node> newq;
		q.push(node{sx-1,sy-1});
		newq.push(node{sx-1,sy-1});
		vis[sx-1][sy-1]=1;
		int ans=1;
		while(q.size()) {
			node now=q.front();
			q.pop();
//			newq.push(now);
			for(int j=0;j<4;j++) {
				int nx=now.x+dx[j];
				int ny=now.y+dy[j];
				if(nx>=0&&nx<n&&ny>=0&&ny<n&&a[nx][ny]!=a[now.x][now.y]&&vis[nx][ny]==0) {
					q.push(node{nx,ny});
					newq.push(node{nx,ny});				
					vis[nx][ny]=1;
					ans++;
				}
			}
		}

		while(newq.size()) {
			node now=newq.front();
			newq.pop();
			vis[now.x][now.y]=ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}

//P1023
#include<bits/stdc++.h>
using namespace std;
int N, A, B;
struct node{
	int x,step;
};
int dx[2]={-1,1};
int vis[210]={0};
int a[210];
int main() {
	cin>>N>>A>>B;
	for(int i=1; i<=N; i++) {
		cin>>a[i];
	}
	queue<node> q;
	vis[A]=1;
	q.push(node{A, 0});
	while(q.size()) {
		node now=q.front();
		q.pop();
		if(now.x==B) {
			cout<<now.step;
			return 0;
		}
		for(int i=0; i<2; i++) {
			int nx=now.x+dx[i]*a[now.x];
			if(nx>=1&&nx<=B&&vis[nx]==0) {
				q.push(node{nx, now.step+1});
				vis[nx]=1;
			}
		}
	}
	cout<<-1;
	return 0;
}

//P1023
#include<bits/stdc++.h>
using namespace std;
int a[10010]={0};
int main() {
	int price;
	cin>>price;
	int cnt, v;
	cin>>v>>cnt;
	a[v]=cnt;
	int last=v;
	int d;
	int x,y;
	while(cin>>x>>y && (x!=-1&&y!=-1)) {
		if(x!=last+1) {
			d=(a[last]-y)/(x-last);
			for(int i=last+1; i<x; i++) {
				a[i]=a[i-1]-d;		
			}	
		}
		//a[4001]=80000?
		a[x]=y;		
		last=x;		 
	}
	int interval;
	cin>>interval;
	while(a[last]>=0) {
		a[last+1]=a[last]-interval;
		last++;
	}
	
	double maxV=1e8;
	double minV=-1e8;
	double ans;
	for(int i=v; i<last; i++) {//start from v
		// (i-v+x)*a[i] <= (price-v+x)*(a[price])
		//i-v+x<=price-v+x when a[i]==a[price]
		//	x*(a[price]-a[i])>=i*a[i]-v*a[i]-price*a[price]+v*a[price];
		// x*(a[price]-a[i])>=(v-price)*a[price]+(i-v)*a[i]
		double right=i*a[i]-v*a[i]-price*a[price]+v*a[price];
		double left=a[price]-a[i];
		if(left==0) continue;
		ans=right/left;
		if(left<0) { //x*(-1)>=6 =>x<-6
			maxV=min(maxV,ans);
		}else{
			minV=max(minV, ans);
		}
	}
//	printf("minV is %lf, maxV is %lf\n", minV, maxV);
	if(minV>0) { //maxV>minV>0 2.5<x<3.5
		cout<<ceil(minV);
	} else if(maxV<0){ //minV<maxV<0 -3.5<x<-2.5
		cout<<floor(maxV);
	} else { //minv<0<maxv
		cout<<0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[55][55];
double distance(int x1, int x2, int y1, int y2) {
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main() {
	int n,m,k,t;
	cin>>n>>m>>k>>t;
	int maxx=INT_MIN;
	// x y: min(t, x-1)+min(t, m-x)+min(t, y-1)+min(t, n-y) 
	// only one bomb
	for(int q=1; q<=k; q++) {
//		cin>>a[i][0]>>a[i][1];
		int x, y;
		cin>>x>>y;
		int ans=0;
		for(int i=max(x-t, 1); i<=min(x+t, n); i++) {
			for(int j=max(y-t, 1); j<=min(y+t, m); j++) {
				if(distance(i, x, j, y)<=t) {
					ans++;
				}
			}
		}
		maxx=max(ans, maxx);
	}
	cout<<maxx;
	return 0;
}
*/