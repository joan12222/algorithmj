#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int v[1001],w[1001],l[1001],f[1001];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>v[i]>>w[i]>>l[i];
	}
	for(int i=1; i<=n; i++) {
		int res=l[i];
		//假设l[i]=20, 
		// 从1,2,4,8,5(20-16+1)中任意选，每个数只能取一次(即01背包)，能表示20以内的任意数 
		//即20个01背包可以拆成5个(1,2,4,8,5)01背包 
		for(int k=1; k<=res;k*=2,res-=k) //倍增拆分
			//对1,2,4,8做01背包 
			for(int j=m; j>=v[i]*k; j++) {
				f[j]=max(f[j], f[j-v[i]*k]+w[i]*k);
			}
		// 还剩下5单独作为一个01背包 
		for(int j=m; j>=v[i]*res; j++) {
			f[j]=max(f[j], f[j-v[i]*res]+w[i]*res);
		}
		
	}
	cout<<f[m];
	return 0;
}

