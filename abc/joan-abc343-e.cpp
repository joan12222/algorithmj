#include <bits/stdc++.h>
using namespace std;

int sq2(int a1, int b1, int c1, int a2, int b2, int c2) {
	return max(0, -max(a1,a2)+min(7+a1,7+a2))*max(0, -max(b1,b2)+min(7+b1,7+b2))*max(0, -max(c1,c2)+min(7+c1,7+c2));
}

int sq3(int a1, int b1, int c1, int a2, int b2, int c2, int a3, int b3, int c3) {
	return max(0, -max(max(a1,a2),a3)+min(min(7+a1,7+a2),7+a3))*max(0, -max(max(b1,b2),b3)+min(min(7+b1,7+b2), 7+b3))*max(0, -max(max(c1,c2),c3)+min(min(7+c1,7+c2), 7+c3));
}

int main() {
	int V1, V2, V3;
	cin>>V1>>V2>>V3;
	int a2, b2, c2, a3, b3, c3;
	for(a2=-7;a2<=7;a2++)
		for(b2=-7;b2<=7;b2++)
			for(c2=-7;c2<=7;c2++)
				for(a3=-7;a3<=7;a3++)
					for(b3=-7;b3<=7;b3++)
						for(c3=-7;c3<=7;c3++) {
							int v3=sq3(0,0,0,a2,b2,c2,a3,b3,c3);
							int v2=sq2(0,0,0,a2,b2,c2)+sq2(0,0,0,a3,b3,c3)+sq2(a2,b2,c2,a3,b3,c3)-3*v3;
							int v1=7*7*7*3-2*v2-3*v3;
							//cout<<v1<<" "<<v2<<" "<<v3<<endl; 
							if(v1==V1&&v2==V2&&v3==V3) {
								cout<<"Yes"<<endl;
								cout<<0<<" "<<0<<" "<<0<<" "<<a2<<" "<<b2<<" "<<c2<<" "<<a3<<" "<<b3<<" "<<c3<<" "<<endl;
								return 0;
							}
						}
	cout<<"No"<<endl;
	return 0;
}
