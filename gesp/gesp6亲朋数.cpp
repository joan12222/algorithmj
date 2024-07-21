#include<bits/stdc++.h>
using namespace std;
#define ll long long
int f[505][505];
int main() {
	int n; cin >> n;
	string s;
	cin >> s;
	memset(f, 0, sizeof(f));
	for(int i=0; i<s.size(); i++) {
		for(int j=i+1; j<s.size(); j++) {
			if((s[i]=='('&&s[j]==')')||(s[i]=='['&&s[j]==']'))
				f[i][j]=f[i+1][j-1]+2;
			for(int k=i; k<=j; k++) {
				f[i][j]=max(f[i][j], f[i][k]+f[k+1][j]);
			}
		}
	}
	cout <<f[0][s.size()-1]<<endl;
	return 0;
}


