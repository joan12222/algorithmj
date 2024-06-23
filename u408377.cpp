#include<bits/stdc++.h>
using namespace std;
int divider[10]={0,10,100,1000,10000,100000,1000000,10000000};
int book[10000009];
int main(){
	int n, q;
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		cin>>book[i];
	}
	for(int i=1; i<=q; i++) {
		int d, ending;
		cin>>d>>ending;
		int count=0;
		for(int j=1;j<=n;j++)
		if(book[j]%divider[d]==ending) {
			count++;
		} 
		cout<<count<<endl;
	}
	return 0;
}
