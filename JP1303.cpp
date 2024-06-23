#include<bits/stdc++.h>
using namespace std;
int a[2005]={0};
int b[2005]={0};
int c[4020]={0};
int main(){
	string s1, s2;
	cin>>s1;
	cin>>s2;

	int len_a=max(s1.size(), s2.size());
	if(s1.size()>s2.size()) {
		for(int i=0; i<s1.size(); i++) {
			a[s1.size()-i-1] = s1[i] - '0';
		}
	} else {
		for(int i=0; i<s2.size(); i++) {
			a[s2.size()-i-1] = s2[i] - '0';
		}
		s2=s1;
	}
	// a is multiplicand
	for(int i=0; i<s2.size(); i++) {
		// s2 is multiplier
		int idx_c=i;
		for(int j=0; j<len_a; j++) {
			c[idx_c+j] += a[j]*(s2[s2.size()-1-i]-'0');
		}
	}
	for(int i=0; i<=4000; i++) {
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	int len=4001;
	while(c[--len]==0&&len>0) {
		
	}
	len++;
//	cout<<len<<endl;
	for(int i=0; i<len; i++) {
		cout<<c[len-i-1];
	}
	return 0;
}