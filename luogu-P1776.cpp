#include<bits/stdc++.h>
using namespace std;
int n,W,v[2000],w[2000],f[40005];
int vi,wi,mi;
int num=0;
//部分背包，拆成01背包，用二进制拆分，二进制倍增优化 
int main() {
	cin>>n>>W;
	for(int i=1;i<=n;i++){ //物品数 
		cin>>vi>>wi>>mi; //价值，重量，件数 
		int curr=1;
		while(mi>=curr) {
			v[++num] = curr*vi;
			w[num] = curr*wi;
			mi-=curr;
			curr<<=1;
		}
		if(mi>0) {
			v[++num] = mi*vi;
			w[num] = mi*wi; 
		}
	}
	//01背包，倒着写 
	for(int i=1; i<=num; i++) { //i种物品 
		for(int j=W; j>=w[i]; j--) {
			f[j] = max(f[j-w[i]]+v[i], f[j]);
		}
	}

	cout<<f[W]; 
	return 0;
} 
