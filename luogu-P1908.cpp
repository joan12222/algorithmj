#include<bits/stdc++.h>
using namespace std;
int n,a[500005],t[500005];
long long merge_sort(int l, int r)  {
	if(l>=r) return 0;
	int mid=(l+r)/2;
	long long sum=merge_sort(l, mid)+merge_sort(mid+1, r);
	int i=l,j=mid+1,k=l;
	while(i<=mid||j<=r) {
		if(i<=mid&&(j>r||a[i]<=a[j])) {
			t[k++] = a[i];
			i++;
		} else {
			sum+=mid-i+1;
			t[k++] = a[j];
			j++;
		}
	}
	for(int i=l; i<=r; i++) {
		a[i]=t[i];
	}
	return sum;
}


int main() {
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<merge_sort(1,n);
	return 0;
}

