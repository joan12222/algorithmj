#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, f[305][305],a[305], c[305];
bool b[305];
int main(){
	cin>>n;
	memset(f, 127, sizeof(f));
	for(int i=1; i<=n; i++) 
		for(int j=1; j<=n; j++)
			cin>>f[i][j];
	//ɾ�����˳�� 
	for(int i=1; i<=n; i++)
		cin>>c[i];
	//�����������Ǽӵ��˳�򣬷���floyd���߼� 
	for(int l=n; l; l--) {
		int k=c[l];
		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++)
				//�������룬����֮�������б� 
				f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
		b[k]=true;
		for(int i=1; i<=n; i++) 
			for(int j=1; j<=n; j++)
				if(b[i]&&b[j]) a[l]+=f[i][j]; //a[n]��ʾɾ����n-1�����ĵ��� 
	}
	for(int i=1; i<=n; i++) cout<<a[i]<<" "; //a[1]����ɾ����0����ĵ��� 
	return 0;
}


