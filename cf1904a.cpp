#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dx[]={1,1, -1,-1};
int dy[]={1,-1,-1, 1};
set<pair<ll, ll>> kpos;
set<pair<ll, ll>> qpos;

int main() {
	ll n;
	cin>>n;
	while(n--) {
		ll cnt=0;
		ll h1, h2;
		cin>>h1>>h2;
		ll xk, yk;
		cin>>xk>>yk;
		ll xq, yq;
		cin>>xq>>yq;
		//calculate possilbe king's killer posiion
		kpos.clear();
		qpos.clear();
		for(int i=0;i<4;i++) {
			kpos.insert(make_pair(h1*dx[i]+xk, h2*dy[i]+yk));
			kpos.insert(make_pair(h2*dx[i]+xk, h1*dy[i]+yk));
		}
		//calculate possilbe queue's killer posiion
		for(int i=0;i<4;i++) {
			qpos.insert(make_pair(h1*dx[i]+xq, h2*dy[i]+yq));
			qpos.insert(make_pair(h2*dx[i]+xq, h1*dy[i]+yq));
		}
		/*
		cout<<n<<": king"<<endl;
		for(auto it=kpos.begin(); it!=kpos.end(); it++) {
			cout<<(*it).first<<" "<<(*it).second<<endl;
		}
		
		cout<<n<<": queue"<<endl;
		for(auto it=kpos.begin(); it!=kpos.end(); it++) {
			cout<<(*it).first<<" "<<(*it).second<<endl;
		}
		*/
		//find out the same in kpos and qpos
		for(auto it=kpos.begin(); it!=kpos.end(); it++) {
			for(auto qit=qpos.begin(); qit!=qpos.end(); qit++) {
//				if((*it).first==(*qit).first && (*it).first>=0 && (*it).first<=1e8 &&
//				(*it).second==(*qit).second && (*it).second>=0 && (*it).second<=1e8) {
				if((*it).first==(*qit).first &&
				(*it).second==(*qit).second) {

					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
