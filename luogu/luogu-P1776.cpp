#include<bits/stdc++.h>
using namespace std;
int n,W,v[2000],w[2000],f[40005];
int vi,wi,mi;
int num=0;
//���ֱ��������01�������ö����Ʋ�֣������Ʊ����Ż� 
int main() {
	cin>>n>>W;
	for(int i=1;i<=n;i++){ //��Ʒ�� 
		cin>>vi>>wi>>mi; //��ֵ������������ 
		int curr=1;
		while(mi>=curr) {
			v[++num] = curr*vi;
			w[num] = curr*wi;
			mi-=curr;
			curr<<=1;
		}
		if(mi>0) {
			v[++num] = mi*vi;
			w[num] = mi*wi; 
		}
	}
	//01����������д 
	for(int i=1; i<=num; i++) { //i����Ʒ 
		for(int j=W; j>=w[i]; j--) {
			f[j] = max(f[j-w[i]]+v[i], f[j]);
		}
	}

	cout<<f[W]; 
	return 0;
} 
