#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n; 
int s[505];
int f[1005][1005];
int a[2010];
int main() {
	cin>>n;
	memset(f, 0x3f, sizeof(f));
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		a[n+i]=a[i];
	}
	for(int i=1; i<=2*n; i++) {
		s[i]=s[i-1]+a[i];
		f[i][i]=0;
	}	
	//ö�����䳤�� ,��Ȼ���������䳤����n,��ת�ƹ����У�����2n���䶼Ҫ���� 
	for(int i=1;i<2*n;i++) {
		//ö����˵� 
		for(int j=1;j<=2*n-i;j++) {
			//ö�ٷֽ��� 
			for(int k=j;k<i+j;k++) {
				f[j][i+j]=min(f[j][i+j], f[j][k]+f[k+1][i+j]);
			}
			f[j][i+j]+=s[i+j]-s[j-1];
		}
	}
	int ans=1<<30;
	for(int i=1;i<=n; i++) {
		ans=min((f[i][n+i-1]), ans);
	}
	cout<<ans;
	return 0;
}

