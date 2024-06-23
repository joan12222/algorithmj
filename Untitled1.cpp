#include<bits/stdc++.h>
using namespace std;
struct Node{
	int l,r;
	string val;
}node[260];
string s;
void clearr(){
	for(int i=1;i<260;i++) node[i].l=node[i].r=0,node[i].val="undefined";
}
bool check(int k) {
	if(node[k].val=="undefined") return false;
	if(node[k].l&&!check(node[k].l)) return false;
	if(node[k].r&&!check(node[k].r)) return false;
	return true;
}
bool bfs(int k){
	queue<int> q;
	q.push(k);
	while(!q.empty()){
		Node now=node[q.front()];
		q.pop();
		cout<<now.val<<" ";
		if(now.l) q.push(now.l);
		if(now.r) q.push(now.r);
	}
	cout<<endl;
}
int main(){
	while(cin>>s) {
		clearr();
		int tot=1;
		node[tot]=Node{0, 0, "undefined"};
		bool valid=true;
		while(s!="()") {
			int curr=1;
			for(int i=s.find(',')+1; i<s.size()-1; i++) {
				tot++;
				if(s[i]=='L') {
					if(!node[curr].l) {
						node[tot]=Node{0, 0, "undefined"};
						node[curr].l=tot;
					}
					curr=node[curr].l; 
				}else if(s[i]=='R') {
					if(!node[curr].r) {
						node[tot]=Node{0, 0, "undefined"};
						node[curr].r=tot;
					}
					curr=node[curr].r;
				}
			}
			string val=s.substr(1, s.find(',')-1);
			if(node[curr].val!="undefined") valid=false;
			else node[curr].val=val;
			cin>>s;
		}
		if(valid&&check(1)) bfs(1);
		else cout<<"not completed"<<endl;
	}/*
	for(int i=1;cin>>s[i];i++,tot++) {};
	for(int i=1;i<=tot;i++){
		if(s[i]=="()") continue;
		int j=1;
		while(j!=",") j++;
		tree[i].val=stoi(s[i].substr(0,j-1));
		tree[i].p=s[i].substr(j+1,s[i].size()-1);
		tree[i].lev=s[i].size();
		if(path.count(tree[i].p)){
			cout<<"not complete";
			flag=true;
		}
		path[tree[i].p]=1;
	}
	if(flag) return 0;
	for(int i=1;i<=tot;i++){
		if(s[i]!="()") check
	}*/
	return 0;
}
