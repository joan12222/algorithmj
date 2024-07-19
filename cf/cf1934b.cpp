#include<bits/stdc++.h>
using namespace std;
#define ll long long
int q;
int n;

int main() {
	cin>>q;
	while(q--) {
		cin>>n;
		int ans=1e9;
		for(int i=0;i<=2;i++) {
			for(int j=0;j<=1;j++) {
				for(int k=0;k<=4;k++) {
					for(int p=0;p<=2;p++) {
						int remain=n-i*1-j*3-k*6-p*10;
						if(remain<0||remain%15) continue;
						ans=min(ans, i+j+k+p+remain/15);
					} 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

