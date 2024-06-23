#include<bits/stdc++.h>
using namespace std;
/*
int a[105];
int cnt, idx=1;
int main()
{
	int m,n;
	cin>>n>>m;
	int maxx=n;
	while(n>=1) {
		cnt=0;
		while(cnt<m) {
			if(!a[idx]) cnt++;
			if(cnt==m) {
				a[idx]=1;
				cout<<idx<<" ";
			}
			if(++idx>maxx) idx%=maxx;
		}
		n--;
	}
	return 0;
}
*/

/*
10 3
0<=3: a[1], cnt=1, idx=2 
1<=3: a[2], cnt=2  3
2<=3: a[3], cnt=3 idx=4
a[4]

*/
