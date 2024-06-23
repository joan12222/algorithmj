#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
bool b[5005];
int a[801][2];
double f[801][801], dist[801]; 

int main(){
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i][0]>>a[i][1];
		//邻接矩阵
		f[i][i]=0; 
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			f[i][j]=sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1]));
		}
	}
	//Prim算法： 连通图，直接n轮即可 
	for(int i=1; i<=n; i++) {
		dist[i]=1e100;
	}
	memset(b, 0, sizeof(b));
	dist[1]=0;
	int ans=0;
	for(int i=1; i<=n; i++) {
		int x=-1;
		for(int j=1; j<=n; j++) {
			if(!b[j]&&dist[j]<1e99) {
				if(x==-1||dist[j]<dist[x]) {
					x=j;
				}
			}
		}
		b[x]=true;
		ans+=dist[x];
		for(int j=1; j<=n; j++) {
			dist[j]=min(f[x][j], dist[j]);
		}
	}
	printf("%.1f\n", ans);
	return 0;
}


