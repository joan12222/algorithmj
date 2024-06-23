#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int a[MAXN];
map<int, int> pos;
struct Node {
	int val;
	int pre;
	int next;
}node[MAXN];
stack<int> st;
int head, curr;
int main() {
	int n, q;
	cin>>n;
	
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		node[i].val=a[i];
		pos[a[i]]=i;
		node[i].pre=i-1;;
		node[i].next=i+1;
	}
	for(int i=n+1; i<MAXN; i++) {
		st.push(i);
	}
	head=1;
	node[n].next=0;
	cin>>q;
	while(q--) {
		int ops, n1, n2;
		cin>>ops;
		//insert
		if(ops==1) {
			cin>>n1>>n2;
			curr=st.top();
			st.pop();
			node[curr].val=n2;
			node[node[pos[n1]].next].pre=curr;
			node[curr].next=node[pos[n1]].next;
			node[pos[n1]].next=curr;
			node[curr].pre=pos[n1];
			pos[n2]=curr;
		}else { //delete
			cin>>n1;
			if(pos[n1]==head) {
				head=node[pos[n1]].next;
			}else if(node[pos[n1]].next==0){
				node[node[pos[n1]].pre].next=0;
			}else{
				node[node[pos[n1]].next].pre = node[pos[n1]].pre;
				node[node[pos[n1]].pre].next=node[pos[n1]].next;
			}
			node[pos[n1]].val=0;
			node[pos[n1]].next=0;
			node[pos[n1]].pre=0;
			st.push(pos[n1]);
		}
	}
	int i=head; 
	do {
		cout<<node[i].val<<" ";
		i=node[i].next;
	}while(i!=0);
	return 0;
}
