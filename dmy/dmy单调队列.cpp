#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
struct Node {
	int end;
	int pwr;
	Node(int _e, int _p) {
		end=_e,pwr=_p;
	}
};
deque<Node> q;
int a[100005], b[100005];
int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i];
	}
	for(int i=1; i<=n; i++) {
		while(!q.empty()&&q.front().end<i) 
			q.pop_front();
		while(!q.empty() && q.back().pwr<b[i])
			q.pop_back();
		q.push_back(Node{a[i],b[i]});
		cout<<q.front().pwr<<endl;
	}
/*
3 8 q:8
4 9 q:9
5 1 q:9 1
5 6 q:
*/
	return 0;
}

