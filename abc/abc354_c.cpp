#include<bits/stdc++.h>
using namespace std; 
#define MAXN 100005
struct Card {
	int v;
	int c;
	int idx;
}card[MAXN];
bool mycmp(struct Card x, struct Card y) {
	return ((double)x.v/x.c && (double)y.v/y.c);
}
int main() {
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		card[i].idx=i;
		cin>>card[i].v>>card[i].c;
	}
	sort(card+1, card+n+1, mycmp);
	for(int i=1; i<=n; i++) {
		cout<<card[i].idx<<" ";
	}
	return 0;
}
