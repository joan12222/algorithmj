#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int, int> a[200005];
int k[200005];
int main() {
	int n;
	int left=0, right=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i].first>>a[i].second;
		left+=a[i].first;
		right+=a[i].second;
		k[i]=a[i].second-a[i].first;
	}
	if((left<=0)&&(right>=0)) {
		cout<<"Yes"<<endl;
		//构造每个元素，贪心
		//初始每个元素都是Li,
		int val=0-left;
		for(int i=1;i<=n;i++) {
			if(val<=k[i]) {
				a[i].first+=val;
				break;
			} else {
				a[i].first+=k[i];
				val-=k[i];
			}
		}
		for(int i=1;i<=n;i++) {
			cout<<a[i].first<<" ";
		}
	}else cout<<"No"<<endl;
	return 0;
}

