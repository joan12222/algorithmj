#include<bits/stdc++.h>
using namespace std;
pair<int, int> farmer[2000005];
int main(){
	int n,m;
	long long ans=0;
	cin>>n>>m;
	for(int i=0; i<m; i++) {
		cin>>farmer[i].first>>farmer[i].second;
	}
	sort(farmer, farmer+m);
	for(auto f: farmer) {
		if(n-f.second>0) {
			ans+=f.first*f.second;
			n-=f.second;
		} else {
			ans+=n*f.first;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}