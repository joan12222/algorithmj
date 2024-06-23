#include <bits/stdc++.h>
using namespace std;
vector<pair<string, int>> a;
int n,m;
int calcBit(int bit, int now) {
	for(auto &it:a) {
		int x=(it.second>>bit)&1;
		if(it.first=="AND") now&=x;
		else if(it.first=="XOR") now^=x;
		else now|=x;
	}
	return now;
}
int main() {
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		string s;
		int t;
		cin>>s>>t;
		a.push_back(make_pair(s,t));
	}
	int val=0;
	int ans=0;
	for(int bit=29; bit>=0; bit--) {
		int res0=calcBit(bit,0);
		int res1=calcBit(bit,1);
		if(res0==1) ans+=1<<bit; //(1,0) ||(1,1) fill 0 
		else{ //res0=0
			if(res1==0) ;//(0,0) fill 0
			else {
				if((val+(1<<bit))<=m) val=val+(1<<bit), ans+=1<<bit;//(0,1) &&<=m fill 1
			}
		}
		/*
		if((val+1<<bit)<=m && res0<res1)
			val=val+1<<bit, ans+=res1<<bit;
		else
			ans+=res0<<bit;
		*/
	}
	cout<<ans;
	return 0;
}
