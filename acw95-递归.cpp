#include<bits/stdc++.h>
using namespace std;
char g[10][10];
char b[10][10];
int dx[5]={0,0,0,-1,1};
int dy[5]={0,-1,1,0,0};
void turn(int x, int y) {
	int nx, ny;
	for(int i=0;i<5;i++) {
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0&&nx<5&&ny>=0&&ny<5) {
			g[nx][ny]^=1;
		}
	}
}
void solve() {
	int ans=1e9;
	int res=0;
	// ������һ�еĿ�����
	// i�����һ�еİ��Ʒ�ʽ�������˼���ǻ��ڵ�һ�й̶����������Ҫ�ѵ�һ�п��ܱ����ɵ�״̬������ö�� 
	for(int i=0;i<32;i++) {
		res=0;
		memcpy(b, g, sizeof(g));
		//ȷ����һ�еĲ�����00000��ʾ��������11111��ʾȫ���� 
		for(int j=0;j<5;j++) {
			if(((i>>j)&1)==1) {
				res++;
				turn(0,j);
			}
		}
		//�̶���һ�У������4�� 
		for(int j=0;j<4;j++) {
			for(int k=0;k<5;k++) {
				if(g[j][k]=='0') {
					turn(j+1,k);
					res++;
				}
			}
		}
		//�жϵ�5�� 
		bool flag=true;
		for(int k=0;k<5;k++) {
			if(g[4][k]=='0') {
				flag=false;
				cout<<i<<" ";
				cout<<"aaa"<<endl;				
				break;
			}
		}
		if(flag) ans=min(ans,res);
		memcpy(g, b, sizeof(g));
	}	
	if(ans>6) ans=-1;
	cout<<ans<<endl; 
}
int main() {
	int t;
	cin>>t;
	while(t--) {
		for(int i=0;i<5;i++) cin>>g[i];
		solve();
	}
	return 0;
}

