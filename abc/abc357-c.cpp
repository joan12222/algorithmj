#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
char a[20000][20000];
int pwr[10];
int dx[8]={-1,-1,-1, 0, 0, 1,1,1};
int dy[8]={-1, 0, 1,-1, 1,-1,0,1};
void dfs(int k, int r, int c) {
	if(k==0) {
		return;
	}
	int len=pwr[k-1];
	int x=r+len;
	int y=c+len;
	for(int i=x; i<x+len; i++) {
		for(int j=y; j<y+len; j++) {
			a[i][j]='.';
		}
	}
	for(int i=0;i<8;i++) {
		int nx=x+dx[i]*len;
		int ny=y+dy[i]*len;
		dfs(k-1, nx, ny);
	}
}
int main() {
	cin>>n;
	pwr[0]=1;
	memset(a, '#', sizeof(a));
	for(int i=1; i<=6; i++) pwr[i]=pwr[i-1]*3;
	dfs(n,0,0);
	int size=pwr[n];
	for(int i=0;i<size; i++) {
		for(int j=0;j<size;j++)
			cout<<a[i][j];
		cout<<endl;
	}
	return 0;
}

