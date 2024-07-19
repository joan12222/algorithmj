#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n,k;

int main() {
	cin>>q;
	while(q--) {
		cin>>n>>k;
		cout<<ceil((double)(n-1)/(k-1))<<endl;
	}
	return 0;
}

