#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		int x1,x2,y1,y2;
		cin>>x1>>y1;
		cin>>x2>>y2;
		if((x1>y1&&x2<y2)||(x1<y1&&x2>y2)) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}


