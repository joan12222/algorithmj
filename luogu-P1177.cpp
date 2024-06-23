#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
void quick_sort(int l, int r)  {
	if(l>=r) return;
	int mid=a[(l+r)/2];
	int i=l-1,j=r+1;
	while(i<j) {
		do j--;
		while(a[j]>mid);
		do i++;
		while(a[i]<mid);
		if(i<j) swap(a[i],a[j]);
	}
//	cout<<j<<endl;
	quick_sort(l, (l+r)/2);
	quick_sort((l+r)/2+1, r);
}


int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	quick_sort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

