#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	s.insert(s.begin(),'0');
	for(int i=1;i<=s.length()-2;i++) {
		char a[3]={s[i],s[i+1],s[i+2]};
		if(a[1]==a[2] && a[1]==a[0]) {
			continue;
		}else if(a[1]!=a[2] && a[1]!=a[0]) {
			cout<<i+1;
		}else if(a[2]!=a[1] && a[2]!=a[0]) {
			cout<<i+2;
		}else if(a[0]!=a[1] && a[0]!=a[2]) {
			cout<<i;
		}
		return 0;
	}
	return 0;
}
