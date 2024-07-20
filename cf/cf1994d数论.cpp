#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 500005
int q;
int n;
pair<int, int> a[2005];
int w[2005];
vector<pair<int, int> > ans;
int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i].first;
			a[i].second=i;
		}
		vector<pair<int, int> >().swap(ans);
		for(int i=0; i<n; i++) w[i]=-1;
		//mod|a-b<=>mod|a,mod|b; 
		//一定要倒着来 
		for(int i=n-1; i>=1; i--) {//n-1种余数，n个数，一定有2个余数相同 
			for(int k=0; k<n; k++) w[k]=-1;
			for(int j=1; j<=i+1; j++) {
/*				for(int k=1; k<=n; k++) {
					cout<<a[k].first<<" "<<a[k].second<<"/";
				}
				cout<<endl;
				cout<<a[j].first<<"/"<<i<<endl;
*/				int mod=a[j].first%i; 
				if(w[mod]==-1) w[mod]=j; 
				else {
//					cout<<"mod is "<<mod<<" "<<w[mod]<<" "<<j<<"swap "<<a[j].second<<"and "<<a[i+1].second<<endl;
					ans.push_back(make_pair(a[j].second, a[w[mod]].second));					
					swap(a[j],a[i+1]);
//					cout<<a[j].second<<"and "<<a[i+1].second<<endl;
					break;
				}
			}
		}	
		cout<<"YES"<<endl;
		for(int i=ans.size()-1; i>=0; i--) {
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
	return 0;
}
