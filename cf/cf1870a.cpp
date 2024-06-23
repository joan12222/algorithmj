#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
int sum[MAXN];
/*
9
n MEX x
5 3 3 // 0 1 2 2 2
4 7 5// MEX=7 means 0-6 is in, but 6>x, -1
4 2 28// 0-1 is in, 0,1,28,28/ 57
12 10 6//0-9 is in, -1
57 51 122//0-50 is in, 51 nums
200 1 200
2 2 1
3 2 1
4 7 10//means 0-6 is in, 
1 2 1//means 0-1 is in, 0,1, k-1=

*/

int main() {
	int c;
	cin>>c;
	for(int i=1; i<=200; i++) {
		sum[i]=sum[i-1]+i;
	}
	while(c--) {
		int n,k,x;
		cin>>n>>k>>x;
		if(k-1>x||n<k) cout<<-1<<endl;
		else if(x==k){
			cout<<(k-1)*(n-k)+sum[k-1]<<endl;
		} else {
			cout<<(x)*(n-k)+sum[k-1]<<endl;
		}
	}
	return 0;
} 
