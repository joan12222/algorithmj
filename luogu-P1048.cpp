#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int t[105];
int v[105];
int f[1005];
int tt,m;
/*
f[i][j]��ʾ��iʱ���ڣ���j-nҩ��ʱ�����ܻ�õ�����ֵ 

int main(){
	cin>>tt>>m;
	for(int i=1; i<=m; i++) {
		cin>>t[i]>>v[i];
	}
	for(int i=1; i<=tt; i++) {
		for(int j=m; j>=0; j--) {
			if(i>=t[j+1]) f[i][j] = max(f[i-t[j+1]][j+1]+v[j+1], f[i][j+1]);
			else f[i][j] = f[i][j+1];
		}
	}
	cout<<f[tt][0];
	return 0;
}

//f[i][j]��ʾ��iʱ���ڣ���ǰj��ҩ��ʱ�����ܻ�õ�����ֵ 
int main(){
	cin>>tt>>m;
	for(int i=1; i<=m; i++) {
		cin>>t[i]>>v[i];
	}
	
	for(int i=1; i<=tt; i++) {
		for(int j=1; j<=m; j++) {
			f[i][j] = f[i][j-1];
			if(i>=t[j]) f[i][j] = max(f[i-t[j]][j-1]+v[j], f[i][j-1]);
		}
	} 
	cout<<f[tt][m];
	return 0;
}
*/

//�۲췢��״̬ת���൱�ڰ�j-1�����ֱ�Ӹ���j,Ȼ����ת�� 
int main(){
	cin>>tt>>m;
	for(int i=1; i<=m; i++) {
		cin>>t[i]>>v[i];
	}
	
	for(int j=1; j<=m; j++) {
		for(int i=tt; i>=1; i--) {
			if(i>=t[j]) f[i] = max(f[i-t[j]]+v[j], f[i]);
		}
	}
	cout<<f[tt];
	return 0;
}
