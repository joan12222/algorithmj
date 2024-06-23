#include<bits/stdc++.h>
using namespace std;
#define ll long long
double a[100005];
double b[100005];
double sum[100005];
int n,f; 
bool check(double target) {
	for(int i=1;i<=n;i++) {
		b[i]=a[i]-target;
	}
	for(int i=1;i<=n;i++) {
		sum[i]=sum[i-1]+b[i];
	}
	double minsum=1e10;
	double ans=-1e10;
	for(int i=f;i<=n;i++) {
		minsum=min(sum[i-f],minsum);
		ans=max(sum[i]-minsum,ans);
	}
	if(ans>=0) return true;
	else return false;
}
int main(){
	cin>>n>>f;
	double left=2005, right=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		left=min(a[i],left);
		right=max(a[i],right);
	}
	while(left+1e-5<right) {
		double mid=(left+right)/2;
		if(check(mid)) {
			left=mid;
		}else {
			right=mid;
		}
	}
	cout<<int(right*1000);
	return 0;
}

