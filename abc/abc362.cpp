#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
 
int main() {
	int mr, mg, mb;
	cin>>mr>>mg>>mb;
	cin>>s;
	if(s=="Red") cout<<min(mg, mb);
	else if(s=="Green") cout<<min(mr,mb);
	else cout<<min(mr, mg);
	return 0;
}

