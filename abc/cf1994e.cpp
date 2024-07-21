#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 998244353
#define MAXN 1000005
int a[MAXN];
int nums[MAXN];
int t;
int k,n;
int cnt;
int ans=0;

//对于一棵size为n的树，总是删叶子节点，可以得到1-n之间所有的size 
int dfs(int j) {	//对nums[cnt]里的数进行递推
	if(j<0) {
		return ans;
	}
	int ones=0;
	for(int i=1; i<=cnt; i++) {
	 	if(nums[i]>>j) ones++;
	}
	//生成新的nums进行递推：第j位清零 
	for(int i=1; i<=cnt; i++) {
		nums[i]=nums[i]&((1<<j)-1);
//		printf("next round: nums[%d]=%d\n", i, nums[i]);
	}
	if(ones>=2) {
		ans|=(1<<(j+1))-1;
		return ans; 
	}else if(ones==1) {
		ans|=(1<<j);
	}
	ans|=dfs(j-1);
	return ans;
}
void solve() {
	cin>>k;
	cnt=0;
	int maxx=0;
	while(k--) {
		cin>>n;
		nums[++cnt]=n; //nums存放每个树的size
		int tmp;
		for(int i=2;i<=n;i++) cin>>tmp; //可以忽略 
		maxx=max(maxx,n);
	}
	if(cnt==1) {
		cout<<nums[cnt]<<endl;
		return;
	}
	//算出最高位，bits位2 
	int bits=-1;
	while(maxx) {
		bits++;
		maxx>>=1;
	}
	ans=0;
//	cout<<"bits is "<<bits<<endl;
	cout<<dfs(bits)<<endl;
}
int main() {
	cin>>t;
	while(t--) {
		solve(); 
	}
	return 0;
}
