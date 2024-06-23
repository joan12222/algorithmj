#include<bits/stdc++.h>
using namespace std;
int n,a[100005],f[100005];
int vi,wi,mi;
int num=0;
/*
//LIS: f[j]
//��ʱ���� 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>a[i]; 
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			if(a[j]<a[i]) f[i]=max(f[j]+1, f[i]);
		}
		f[i] = max(1, f[i]);
	}
	int maxx=-1;
	for(int i=1; i<=n; i++) {
		maxx = max(maxx, f[i]);
	}
	cout<<n-maxx; 
	return 0;
}
*/

//LIS: f[j]
//
int b[10005]; //����Ϊi��LIS���һ��Ԫ��
int total;
// ��Ԫ�ع���ʱ�����ݶ��ֲ��ҵ����ڸ���ֵ�ĵط��� 
//lower_bound,�ڵ������������Ѱ�ҵ�һ�����ڵ��ڸ�ֵ�ĵط� 
int main() {
	cin>>n;
	for(int i=1;i<=n;i++){ 
		cin>>a[i]; 
	}
	b[1]=a[1];
	total=1;
	for(int i=2; i<=n; i++) {
		int p = lower_bound(b+1, b+total+1, a[i])-b; //p�����ȣ�û�ҵ�������length 
		b[p]=a[i];
		if(p>total) total++;
	}
	cout<<n-total; 
	return 0;
}

