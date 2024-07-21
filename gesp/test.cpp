#include<bits/stdc++.h>
using namespace std;
#define ll long long
int f[505][505];
int main() {
	int n; cin >> n;
	string s;
	cin >> s;
	memset(f, 0, sizeof(f));
	//ÓÒ¶Ëµã-×ó¶Ëµã
	for(int l=1; l<=n; l++) {
		//i+len=n
		for(int i=0; i<=n-l; i++) {
			int j=i+l;
			if((s[i]=='('&&s[i+l]==')')||(s[i]=='['&&s[i+l]==']'))
				f[i][i+l]=f[i+1][i+l-1]+2;
			for(int k=i; k<i+l; k++)
				f[i][i+l]=max(f[i][i+l], f[i][k]+f[k+1][i+l]);
			}
		}	
	}
	cout<<endl;
	return 0;
}


