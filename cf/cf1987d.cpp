#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
int a[5005];
int f[5005];
int nums[5005];
int main() {
	cin>>t;
	while(t--) {
		vector<int> v;
		cin>>n;
		for(int i=1;i<=n;i++) {
			f[i]=0;
			nums[i]=0;
		}
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			nums[a[i]]++;
		}
		for(int i=1;i<=n;i++) {
			if(nums[i]) v.push_back(nums[i]);
		}
		int m=v.size();
		for(int i=1; i<m; i++) {
			for(int j=i; j>=0; j--) {
				if(j-v[i]>=0) {
					f[j+1]=max(f[j+1], f[j-v[i]]+1);
				}
			}
		}
		int maxx=0;
		for(int i=1; i<=m; i++) {
			maxx=max(maxx, f[i]);
		}
		cout<<(m-maxx)<<endl;
	}
	return 0;
}

