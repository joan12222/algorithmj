#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,k,d;
ll ans=0;
int a[2005];
int b[100005];
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>k>>d;
		ll ans=0,now=0; 
		for(int i=1; i<=n; i++) cin>>a[i];
		for(int i=0; i<k; i++) cin>>b[i];
		//��0�β���1 
		for(int i=1; i<=n; i++) {
			if(a[i]==i) ans++;
		}
		ans+=(d-1)/2; 

		//b[j]=n,ÿ��ÿ��Ԫ�ض���1�����N�Σ�����Ҳ����÷��� 
		//n 1 1 1 n, ÿk�β���ÿ��Ԫ�ض���1��Ҫk*n�Σ�ֱ��������2�Ļ������2*n��Ҳ�õ���ͬ��n���ˣ��������ѭ��2*n�� 
		//����i����i�β���1���ٲ���2 
		for(int i=1; i<=min(4005, d-1); i++) {
			now=0;
			for(int j=1; j<=b[(i-1)%k]; j++) a[j]++;
			for(int j=1; j<=n; j++) {
				if(a[j]==j) now++;
			}
			now+=(d-i-1)/2;
			ans=max(ans, now);
		}
		cout<<ans<<endl;
	}
	return 0;
}

