#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200005],k;
map<ll,bool> mp;
ll sum;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=k){
			if(!mp.count(a[i])) sum+=a[i];
			mp[a[i]]=1;
		}
	}
	cout<<(k+1)*k/2-sum;
	return 0;
}
