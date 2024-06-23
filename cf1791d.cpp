#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
char s[MAXN];
bool bkt[30];
int f1[MAXN];
int f2[MAXN];
int main() {
	int c;
	cin>>c;
	while(c--) {
		int len;
		cin>>len;
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		memset(bkt,0,sizeof(bkt));
		int curlen=0;
		//f1(1) -- f1(len-1)
		for(int i=1; i<=len; i++) {
			cin>>s[i];
			if(!bkt[s[i]-'a']) {
				bkt[s[i]-'a'] = 1;
				f1[i]=++curlen;
			} else f1[i]=curlen;
		}
		memset(bkt,0,sizeof(bkt));
		curlen=0; 
		//f2(1) -- f2(len-1):
		for(int i=len; i>1; i--) {
			if(!bkt[s[i]-'a']) {
				bkt[s[i]-'a'] = 1;
				f2[len-i+1]=++curlen;
			} else f2[len-i+1]=curlen;
		}
		for(int i=1; i<len; i++) {
			cout<<f1[i]<<" "<<f2[len-i]<<endl;
		}

		int res=0;
		//f1(1)+f2(len-1)
		for(int i=1; i<len; i++) {
			res=max(res, f1[i]+f2[len-i]);
		}
		cout<<"res is ";
		cout<<res<<endl;
	}
		
	return 0;
} 
