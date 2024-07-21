#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005;
int ans[maxn];
int main()
{
	int n;
	cin >> n;
	memset(ans,0,sizeof(ans));
	int f = 1,a,b;
	for(int i=2;i<=n;i++) {
		cout<<"? "<<f<<' '<<i<<'\n';
		
		cin >> a;
		
		cout<<"? "<<i<<' '<<f<<'\n';
		cin >> b;
		
		if(a > b) {
			ans[f] = a;
			f = i;
		} else {
			ans[i] = b;
		}
	}
	cout<<"! ";
	for(int i=1;i<=n;i++)
	{
		if(ans[i] == 0)printf("%d ",n);
		else printf("%d ",ans[i]);
	}
 } 

