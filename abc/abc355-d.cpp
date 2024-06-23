#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Node {
	int v;
	int t;
	Node(int _v, int _t) {
		v=_v;
		t=_t;
	};
};
vector<Node> nodes;

bool mycmp(Node a, Node b) {
	if(a.v<b.v) return true;
	else if(a.v==b.v) return a.t<b.t;
	else return false; 
}
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		int l,r;
		cin>>l>>r;
		nodes.push_back({l, 0});
		nodes.push_back({r, 1});
	}
	sort(nodes.begin(), nodes.end(), mycmp);
	int cnt=0;
	ll ans=0;
	for(auto node: nodes) {
//		cout<<node.v<<" "<<node.t<<endl;
		if(node.t==0) {
			ans+=cnt;
			cnt++;
		}
		else {
			cnt--;
		}
	}
	cout<<ans;
	return 0;
}

