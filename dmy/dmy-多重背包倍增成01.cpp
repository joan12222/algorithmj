#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int v[1001],w[1001],l[1001],f[1001];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>v[i]>>w[i]>>l[i];
	}
	for(int i=1; i<=n; i++) {
		int res=l[i];
		//����l[i]=20, 
		// ��1,2,4,8,5(20-16+1)������ѡ��ÿ����ֻ��ȡһ��(��01����)���ܱ�ʾ20���ڵ������� 
		//��20��01�������Բ��5��(1,2,4,8,5)01���� 
		for(int k=1; k<=res;k*=2,res-=k) //�������
			//��1,2,4,8��01���� 
			for(int j=m; j>=v[i]*k; j++) {
				f[j]=max(f[j], f[j-v[i]*k]+w[i]*k);
			}
		// ��ʣ��5������Ϊһ��01���� 
		for(int j=m; j>=v[i]*res; j++) {
			f[j]=max(f[j], f[j-v[i]*res]+w[i]*res);
		}
		
	}
	cout<<f[m];
	return 0;
}

