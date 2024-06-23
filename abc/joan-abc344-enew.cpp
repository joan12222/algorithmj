#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
int a[MAXN];
struct Node {
	int val;
	Node *prev;
	Node *next;
};
Node head, tail;
map<int, Node*> pos;

Node *AddNode(Node *node, int val) {
	Node *newNode=new Node();		
	newNode->val=val;
	node->next->prev=newNode, newNode->next=node->next;
	newNode->prev=node, node->next=newNode;
	pos[val]=newNode;
	return newNode;
}
void DelNode(int val) {
	pos[val]->next->prev=pos[val]->prev;
	pos[val]->prev->next=pos[val]->next;
	pos.erase(val);
	delete pos[val];
}
int main() {
	int n, q;
	cin>>n;
	head.next=&tail;
	tail.prev=&head;	
	Node *pnode = &head;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pnode=AddNode(pnode,a[i]);
	}
	cin>>q;
	while(q--) {
		int ops, n1, n2;
		cin>>ops;
		//insert
		if(ops==1) {
			cin>>n1>>n2;
			AddNode(pos[n1], n2);
		}else { //delete
			cin>>n1;
			DelNode(n1);
		}
	}
	Node *curr=&head; 
	do {
		if(curr->val) cout<<curr->val<<" ";
		curr=curr->next;
	}while(curr);
	return 0;
}
