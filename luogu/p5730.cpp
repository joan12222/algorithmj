#include<bits/stdc++.h>
using namespace std;
int divider[10]={0,10,100,1000,10000,100000,1000000,10000000};
/*
XXX. ..X. XXX. XXX. X.X. XXX. XXX. XXX. XXX. XXX
X.X. ..X. ..X. ..X. X.X. X... X... ..X. X.X. X.X
X.X. ..X. XXX. XXX. XXX. XXX. XXX. ..X. XXX. XXX
X.X. ..X. X... ..X. ..X. ..X. X.X. ..X. X.X. ..X
XXX. ..X. XXX. XXX. ..X. XXX. XXX. ..X. XXX. XXX
*/
char a[110];
const int ROW=5;
const int COL=3;
char matrix[11][ROW+1][COL+1] = {
	{"XXX", "X.X", "X.X", "X.X", "XXX"},
	{"..X", "..X", "..X", "..X", "..X"},
	{"XXX", "..X", "XXX", "X..", "XXX"},
	{"XXX", "..X", "XXX", "..X", "XXX"},
	{"X.X", "X.X", "XXX", "..X", "..X"},
	{"XXX", "X..", "XXX", "..X", "XXX"},
	{"XXX", "X..", "XXX", "X.X", "XXX"},
	{"XXX", "..X", "..X", "..X", "..X"},
	{"XXX", "X.X", "XXX", "X.X", "XXX"},
	{"XXX", "X.X", "XXX", "..X", "XXX"}
};
int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int j=0; j<5; j++) {
		for(int i=1; i<=n; i++) {
			cout<<matrix[a[i]-'0'][j];
			if(i!=n) cout<<".";
		}
		cout<<endl;
	}
	return 0;
}
