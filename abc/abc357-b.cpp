#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
string s;
int main() {
	cin>>s;
	int lc=0, uc=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='a'&&s[i]<='z') lc++;
		else uc++; 
	}
	if(uc>lc) transform(s.begin(), s.end(), s.begin(), ::toupper);
	else transform(s.begin(), s.end(), s.begin(), ::tolower);
	cout<<s;
	return 0;
}

