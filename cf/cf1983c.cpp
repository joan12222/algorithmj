#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
ll a[3][N];
ll tot;
void solve() {
    int n;
    cin >> n;
    ll tot=0;
    for(int i=0; i<3; i++) {
    	for(int j=0; j<n; j++) {
    		cin>>a[i][j];
    		if(i==0) {
    			tot+=a[i][j];
			}
		}
	}
    tot=(tot+2)/3; //向上取整 
    int l[3], r[3];
	array<int, 3> perm={0,1,2};
    do {
   	    bool ok=true;
    	int curr=0;
    	for(int i=0; i<3; i++) { //第几个区间 
	    	l[perm[i]]=curr+1;
	    	ll sum=0;
	    	while(sum<tot&&curr<n) {
				sum+=a[perm[i]][curr++];
			}//curr>=n或者sum>=tot 
			if(sum<tot) { //curr>=n
				ok=false;
				break;
			} 
			r[perm[i]]=curr;
		}
		if(ok) {
			for(int i=0;i<3;i++) {
				cout<<l[i]<<" "<<r[i]<<" ";
			}
			cout<<endl;
			return;
		}
	}while(next_permutation(perm.begin(), perm.end()));
    cout<<-1<<endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
