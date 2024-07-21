#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 200005
int n,k;
string s;
string s1="";
vector<string> ans;
map<string, int> m;
bool vis[25];
void dfs(int k) {
	if(k==n) {
		if(!m.count(s1)) m[s1]=1;
		return;
	}
	for(int i=0;i<s.size();i++) {
		if(vis[i]) continue;
		s1+=s[i];
		vis[i]=1;
		dfs(k+1);
		vis[i]=0;
		s1.erase(k);
	}
}
int main() {
	cin>>n>>k;
	cin>>s;
	dfs(0);
	int cnt=0; 
//	cout<<m.size()<<endl;
	for(auto v:m) {
		s1=v.first;
		//xyyzz
		for(int i=0; i<=s1.size()-k; i++) {
			int j=0;	
			for(j=0;j<k;j++) {
				if(s1[i+j]!=s1[i+k-j-1]) break;  
			}
			if(j==k) {
				cnt++;
				break;
			}
		}
	}
	cout<<(m.size()-cnt);
	return 0;
} 
