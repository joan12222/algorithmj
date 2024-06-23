#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, f[305][305],a[305], c[305];
bool b[305];
int main(){
	cin>>n;
	memset(f, 127, sizeof(f));
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++)
			cin>>f[i][j];
	//删除点的顺序 
	for(int i=1; i<=n; i++)
		cin>>c[i];
	//反着来，考虑加点的顺序，符合floyd的逻辑 
	for(int l=n; l; l--) {
		int k=c[l];
		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++)
				//根据输入，两点之间总是有边 
				f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
		b[k]=true;
		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++)
				if(b[i]&&b[j]) a[l]+=f[i][j]; //a[n]表示删除了n-1个点后的点距和 
	}
	for(int i=1; i<=n; i++) cout<<a[i]<<" "; //a[1]便是删除了0个点的点距和 
	return 0;
}


