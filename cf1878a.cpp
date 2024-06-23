#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int mp[MAXN];
int a[MAXN];

/*
7
n k
5 4
1 4 3 4 1 // Y 
5 3 
3 4 1 5 5 Y
滑动窗口
双指针
找子串出现频率最高
f1 
*/

int main() {
	int c;
	cin>>c;

	while(c--) {
		int n,k;
		cin>>n>>k;
		bool flag=false;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		for(int i=1; i<=n; i++) {
			if(a[i]==k) {
				flag=true;
				break;
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
