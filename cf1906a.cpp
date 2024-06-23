#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

char a[5][5];
string b[600];
int dx[8]={0, 0,1,-1,  1, 1, -1,-1};
int dy[8]={1,-1,0, 0, -1, 1,  1,-1};

int main(){
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			cin>>a[i][j];
		}
	}
	int total=0;
	for(int i=1; i<=3; i++) {
		for(int j=1; j<=3; j++) {
			for(int k=0;k<8;k++) {
				int nx=i+dx[k];
				int ny=j+dy[k];
				if(nx>0&&nx<4&&ny>0&&ny<4) {
					for(int p=0;p<8;p++) {
						int nnx=nx+dx[p];
						int nny=ny+dy[p];
						if(nnx>0&&nnx<4&&nny>0&&nny<4&&!(nnx==i&&nny==j)) {
							b[total]+=a[i][j];
							b[total]+=a[nx][ny];	
							b[total]+=a[nnx][nny];
							total++;
						}
					}
				}
			}
		}
	}
	sort(b, b+total);
//	for(int i=0;i<total;i++) {
//		cout<<b[i]<<endl;
//	}
	cout<<b[0]<<endl; 
	return 0;
}
