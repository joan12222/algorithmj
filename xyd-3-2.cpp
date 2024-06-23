#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int a[100005];
vector<pair<int, int>> limit;
/*
5
180 186 189 191 18
180 380 580
186 386
找出小于200的数
for(相加小于200的组合Num)
	找出以下数的组合，使得余数与Num相等 
for(N)
	剩下N个数 

1,2,3,4,5
1
1 2 模200的余数相等个数大于2 必须有一个小于200 
N=200
strictly increasing

*/
struct Interval {
	int l;
	int r;
};
Interval b[100005];
bool cmp(Interval i1, Interval i2) {
	if(i1.l==i2.l) return i1.r<i2.r;
	return i1.l<i2.l;
}
	
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=m; i++) {
		cin>>b[i].l>>b[i].r;
	}
	for(int i=1; i<=m; i++) {
		if(b[i].l!=b[i].r) {
			b[i].l--;
			b[i].r++;
		}
	}
	sort(b+1, b+m+1, cmp);
	int left=b[1].l;
	int right=b[1].r;
	
	for(int i=2; i<=m; i++) {
		//non-continuous
		if(b[i].l>right) {
			limit.push_back(make_pair(left, right));
			left=b[i].l;
			right=b[i].r;
			continue;
		};
		// merge
		if(b[i].r>right) right=b[i].r;
	}
	limit.push_back(make_pair(left, right));
	
	for(int i=0; i<limit.size(); i++) {
		for(int j=limit[i].first; j<=limit[i].second; j++) {
			a[j]=1;
		}
	}
	for(int i=1; i<n; i++) {
		if(!a[i]) cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}
