#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int a[MAXN];
/*
1 2 3 4 5 // 0
1 3 4 5 6 12456 12356 12346 12345 
// if it's possible to a strict increasing 
1 5 8 9 //1234
2 2 5 8//1234
3 3 5// 123
1 1 3 8//1123 
1 3 3 5//1234
1 3 3 3 5//12334
1 2 2 5//1223
1122233345//
*/

int main() {
	int c;
	cin>>c;
	while(c--) {
		int len;
		long long ans=0;
		cin>>len;
		for(int i=1; i<=len; i++) {
			cin>>a[i];
		}
		sort(a+1, a+len+1);
		if(a[1]!=1) {
			ans=a[1]-1;
			a[1]=1;
		}
		for(int i=2; i<=len; i++) {
			if(a[i]<=a[i-1]+1) continue;
			else {
				ans+=a[i]-a[i-1]-1;
				a[i]=a[i-1]+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
