#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[5005];
int b[5005];
set<pair<int, int>> st;
int main(){
	int n,p,h,m;
	cin>>n>>p>>h>>m;
	for(int i=1;i<=m;i++) {
		int x,y;
		cin>>x>>y;
		if(x>y) swap(x,y);
		if(y-x<2) continue;
		st.insert(make_pair(x,y));
	}
	for(auto it:st) {
//		cout<<it.first<<" "<<it.second<<endl;
		b[it.first+1]--;
		b[it.second]++;
	}
	for(int i=1;i<=n;i++) {
		a[i]=a[i-1]+b[i]; //a1=b1;a2=b1+b2=a1-a0+a2-a1.
		cout<<a[i]+h<<endl;
	}
	return 0;
}

