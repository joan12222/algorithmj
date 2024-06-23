#include<bits/stdc++.h>
using namespace std;
int n,a[100005],f[100005];
int vi,wi,mi;
int num=0;
/*
//LIS: f[j]
//超时动规 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>a[i]; 
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			if(a[j]<a[i]) f[i]=max(f[j]+1, f[i]);
		}
		f[i] = max(1, f[i]);
	}
	int maxx=-1;
	for(int i=1; i<=n; i++) {
		maxx = max(maxx, f[i]);
	}
	cout<<n-maxx; 
	return 0;
}
*/

//LIS: f[j]
//
int b[10005]; //长度为i的LIS最后一个元素
int total;
// 新元素过来时，根据二分查找到大于该数值的地方， 
//lower_bound,在单调递增数列里，寻找第一个大于等于该值的地方 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>a[i]; 
	}
	b[1]=a[1];
	total=1;
	for(int i=2; i<=n; i++) {
		int p = lower_bound(b+1, b+total+1, a[i])-b; //p代表长度，没找到，返回length 
		b[p]=a[i];
		if(p>total) total++;
	}
	cout<<n-total; 
	return 0;
}

