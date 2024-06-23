#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
int mp[MAXN];
int a[MAXN];

/*
7
1 

*/

int main() {
	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;
		int c;
		if(n%3==0) {
			c=n-1-4;
			if(c>0&&c!=1&&c!=4){
				cout<<"YES"<<endl;
				cout<<1<<" "<<4<<" "<<c<<endl;
			}else cout<<"NO"<<endl;
		}else if(n%3==1) {
			c=n-1-4;
			if(c>0&&c!=1){
				cout<<"YES"<<endl;
				cout<<1<<" "<<4<<" "<<c<<endl;
			}else cout<<"NO"<<endl;
		}else if(n%3==2) {
			c=n-1-2;
			if(c>0&&c!=2){
				cout<<"YES"<<endl;
				cout<<1<<" "<<2<<" "<<c<<endl;
			}else cout<<"NO"<<endl;
		}
	}
	return 0;
} 
