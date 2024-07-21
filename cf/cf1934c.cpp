#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
void solve() {
	int n,m;
	int a, b, c;
	cin>>n>>m;
	cout<<"? 1 1"<<endl;
	cin>>a;
	cout<<"? "<<n<<" "<<1<<endl;
	cin>>b;
	cout<<"? "<<1<<" "<<m<<endl;
	cin>>c;
	int x1, y1, x2, y2;
	x1=(a-b+1+n)/2;
	y1=(a+b+1-n)/2;
	x2=(a-c+m+1)/2;
	y2=(a+c+3-m)/2;
	if(x1>n||x1<1||y1>m||y1<1) {
		cout<<"! "<<x2<<" "<<y2<<endl;
	}else {
		cout<<"? "<<x1<<" "<<y1<<endl;
		int d;
		cin>>d;
		if(d) cout<<"! "<<x2<<" "<<y2<<endl;
		else cout<<"! "<<x1<<" "<<y1<<endl;
	}
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		solve();
	}
	return 0;
} 
