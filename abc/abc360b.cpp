#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
int main(){
	cin>>s;
	cin>>t;
	for(int w=1;w<s.size(); w++) {
		int cnt=0;
		vector<string> v={};
		while(cnt*w<s.size()){
			v.push_back(s.substr(cnt*w, w));
			cnt++;
		}
		for(int c=1;c<=w;c++) {
			// atcoder 1-1+w
			string res="";
			for(auto cur:v) {
//				cout<<cur<<"*"<<endl;
				if(c-1<cur.size())
					res+=string(1,cur[c-1]);
			}
//			cout<<res<<" "<<t<<endl;
			if(res==t) {
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
