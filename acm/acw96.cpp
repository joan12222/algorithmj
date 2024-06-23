#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define ll long long
int f[13];
int d[13];
int main(){
	int n=12;
	d[1]=1;
	for(int i=2; i<=n; i++) {
		d[i]=2*d[i-1] +1;
	}

	f[1]=1;
	for(int k=2; k<=n; k++) {
		f[k]=1e9;
		for(int j=1; j<k; j++) {
			f[k]=min(f[k], 2*f[j]+d[k-j]);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<endl; 
	return 0;
}

