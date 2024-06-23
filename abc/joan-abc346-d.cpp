#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c[200005];
ll minn=1e18;
ll f[200005][2];
ll g[200005][2];
int main(){
	int n;
	string s;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	s.insert(s.begin(),'2');
	s.insert(s.end(), '2');
	for(int i=1;i<=n;i++){
		//注意三目操作符的优先级 
		f[i][0] = f[i-1][1] + ((s[i]=='1') ? c[i] : 0);
		f[i][1] = f[i-1][0] + ((s[i]=='0') ? c[i] : 0);
	}	
	for(int i=n;i>=1;i--){
		g[i][0] += g[i+1][1] + ((s[i]=='1') ? c[i] : 0);
		g[i][1] += g[i+1][0] + ((s[i]=='0') ? c[i] : 0);
	}
	/*以2个为单位做，会有3个样例错 
	for(int i=1;i<=n-1;i++){
		if(s[i]==s[i+1]) {
			//注意f和g的下标 
			minn=min(minn, (s[i]=='0') ? (f[i-1][1]+g[i+2][1]) : (f[i-1][0]+g[i+2][0]));
		}
	}*/
	for(int i=2;i<=n;i++){
		minn=min(minn, min(f[i-1][1]+g[i][1], f[i-1][0]+g[i][0])); 
	}	cout<<minn;
	return 0;
}
