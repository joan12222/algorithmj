#include<bits/stdc++.h>
using namespace std;
int t,n,m,a[105][105],f[10005];
//��ȫ����������д��һά���� 
int main() {
	cin>>t>>n>>m;
	for(int i=1;i<=t;i++){ //���� 
		for(int j=1;j<=n;j++){ //����Ʒ 
			cin>>a[j][i];
		}
	}

	for(int i=1; i<t; i++) { //i��
		//��i�����ÿ�ּ���Ʒ�ܻ�ȡ���������
		int maxx=-1;
		memset(f, 0, sizeof(f)); 
		for(int j=1; j<=n; j++) {  //j����Ʒ 
			for(int k=a[j][i]; k<=m; k++) { 
				// f[k],��ǰ��kǮ���Ե�j����Ʒ�������ܻ�ȡ���������
				f[k] = max(f[k], f[k-a[j][i]]+a[j][i+1]-a[j][i]);
				maxx = max(maxx, f[k]);
			}
		}
		m+=maxx;
	}
	cout<<m; 
	return 0;
} 
