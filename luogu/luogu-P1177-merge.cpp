#include<bits/stdc++.h>
using namespace std;
int n,a[100005],t[100005];
void merge_sort(int l, int r)  {
	if(l>=r) return;
	int mid=(l+r)/2;
	merge_sort(l, mid);
	merge_sort(mid+1, r);
	int i=l,j=mid+1,k=l;
	while(i<=mid||j<=r) {
		if(i<=mid&&(j>r||a[i]<a[j])) {
			t[k++] = a[i];
			i++;
		} else {
			t[k++] = a[j];
			j++;
		}
	}
	for(int i=l; i<=r; i++) {
		a[i]=t[i];
	}
}


int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	merge_sort(1,n);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}

