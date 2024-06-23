#include<bits/stdc++.h>
using namespace std;
#define NUM 200005
map<int, bool> hmp,wmp;
map<int, long long> color;
struct Operations {
	int t;
	int idx;
	int c;
}ops[NUM];
int main(){
	long long h,w,m;
	cin>>h>>w>>m;
	for(int i=1;i<=m;i++){
		cin>>ops[i].t>>ops[i].idx>>ops[i].c;
	}
	for(int i=m; i>=1; i--) {
		if(ops[i].t==1) {// row
			if(!hmp.count(ops[i].idx)) {
				hmp[ops[i].idx]=1;
				color[ops[i].c] += w - wmp.size();
			}
		}
		if(ops[i].t==2) {// col
			if(!wmp.count(ops[i].idx)) {
				wmp[ops[i].idx]=1;
				color[ops[i].c] += h - hmp.size();
			}
		}
	}
	vector<pair<int, long long>> ncolor(color.begin(), color.end());
	sort(ncolor.begin(), ncolor.end());
	long long ans0=h*w;
	vector<pair<int, long long>>::iterator it;
	for(it=ncolor.begin(); it!=ncolor.end();) {
		if((*it).first==0||(*it).second==0) {
			it=ncolor.erase(it);
		}else {
			ans0-=(*it).second;
			it++;
		}
	}
	
	if(ans0) {
		ncolor.insert(ncolor.begin(), make_pair(0, ans0));
	}
	cout<<ncolor.size()<<endl;
	for(auto it:ncolor) {
		cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}
