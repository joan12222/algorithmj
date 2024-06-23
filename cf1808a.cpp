#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	while(n--) {
		int a, b;
		int lmt;
		cin>>a>>b;
		int res=a;
		lmt=(b-a>90) ? 90 : (b-a);
		int lucky=0;
		for(int i=0; i<=lmt; i++) {
			int maxx=0;
			int minn=9;
			int num = a+i;
			while(num) {
				int remainder=num%10;
				maxx = max(maxx, remainder);
				minn = min(minn, remainder);
				num/=10;
			}
//			cout<<a+i<<" "<<maxx<<" "<<minn<<endl;
			if(lucky < maxx-minn) {
				lucky=maxx-minn;
				res=a+i;
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
