#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main() {
	int xa,xb,xc,ya,yb,yc;
	int ab, bc, ac;
	cin>>xa>>ya;
	cin>>xb>>yb;
	cin>>xc>>yc;
	int tmpx=xa-xb;
	int tmpy=ya-yb;
	ab=tmpx*tmpx+tmpy*tmpy;
	tmpx=xa-xc;
	tmpy=ya-yc;
	ac=tmpx*tmpx+tmpy*tmpy;
	tmpx=xb-xc;
	tmpy=yb-yc;
	bc=tmpx*tmpx+tmpy*tmpy;
	if((ab+ac==bc)||(ac+bc==ab)||(bc+ab==ac)) cout<<"Yes";
	else cout<<"No";
	return 0;
}

