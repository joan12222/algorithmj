#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
vector<int> edges[100005];
int ans=0;
int n;
int h[100005];

int calc(int x) {
    int res = 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x% i == 0){
                x/= i;
                //偶数个相同因子,值为0
				//奇数个，为1 
                res^=(1<<(i-1));
            }
        }
    }
    if (x != 1) {
        res^=(1<<(x-1));
    }
    return res;
}
int pre=0;//前缀异或 
ll ans=0;
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		int res=calc(a[i]);
		pre^=res;
		if(pre==0) {
			ans++;
		}
		ans+=mp[pre];
	}
	for(int i=1; i<n; i++) {
		int x, y;
		cin>>x>>y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	dfs(1, 0);
	cout<<ans; 
	return 0;
}


