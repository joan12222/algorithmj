#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
string s,t;
queue<string> q;
map<string, int> m;
int main() {
	cin>>n>>s>>t;
	s+="..";
	t+="..";
	q.push(s);
	while(!q.empty()) {
		string x=q.front();
		q.pop();
		//找到".."的位置
		int pos=x.find("..");
//		cout<<".. at "<<pos<<endl;
		for(int i=0;i<n+1;i++) {
			if(x[i]=='.'||x[i+1]=='.') continue;
			string y=x;
			swap(y[i],y[pos]),swap(y[i+1],y[pos+1]);
//			cout<<"After swap, string is "<<y<<endl;
			if(!m.count(y)) { //和!m[y]的区别？？？ 
				m[y]=m[x]+1;
				if(y==t) break;
				q.push(y);
			}
		} 
	}
	if(m.count(t)) cout<<m[t];
	else cout<<-1;
	return 0;
}

