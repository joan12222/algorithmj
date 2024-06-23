#include<bits/stdc++.h>
using namespace std;

string s;
#define MAXN 260
int leftchild[MAXN], rightchild[MAXN];
string val[MAXN];
int tot=0;

void bfs(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now=q.front();
		cout<<val[now]<<" ";
		q.pop();
		if(leftchild[now]) q.push(leftchild[now]);
		if(rightchild[now]) q.push(rightchild[now]); 
	}
	cout<<endl;
}

bool check(int root) {
	if(val[root]=="Undefined") return false;
	if(leftchild[root]&&!check(leftchild[root])) return false;
	if(rightchild[root]&&!check(rightchild[root])) return false;
	return true;
}

int newNode() {
	tot++;
	leftchild[tot]=rightchild[tot]=0;
	val[tot]="Undefined";
	return tot;
}

int main(){
	while(cin>>s) {
		int root=newNode();
		bool valid=true;
		while(s!="()") {
			int now=root;
			for(int i=s.find(',')+1; i<s.size()-1; i++) {
				if(s[i]=='L') {
					if(!leftchild[now]) {
						int curr=newNode();
						leftchild[now]=curr;
					}
					now=leftchild[now];
				}else if(s[i]=='R') {
					if(!rightchild[now]) {
						int curr=newNode();
						rightchild[now]=curr;
					}
					now=rightchild[now];
				}
			}
			if(val[now]=="Undefined")
				val[now]=s.substr(1, s.find(',')-1);
			else {
				valid=false;
			}
			cin>>s;
		}
		if(valid&&check(root)) {
			bfs(root);
		}else cout<<"not complete";
	}
	return 0;
}
