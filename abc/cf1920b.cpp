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

//����һ��sizeΪn����������ɾҶ�ӽڵ㣬���Եõ�1-n֮�����е�size 
int dfs(int j) {	//��nums[cnt]��������е���
	if(j<0) {
		return ans;
	}
	int ones=0;
	for(int i=1; i<=cnt; i++) {
	 	if(nums[i]>>j) ones++;
	}
	//�����µ�nums���е��ƣ���jλ���� 
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
		nums[++cnt]=n; //nums���ÿ������size
		int tmp;
		for(int i=2;i<=n;i++) cin>>tmp; //���Ժ��� 
		maxx=max(maxx,n);
	}
	if(cnt==1) {
		cout<<nums[cnt]<<endl;
		return;
	}
	//������λ��bitsλ2 
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
