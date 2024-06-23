#include<bits/stdc++.h>
using namespace std;
int a[1009][1009];
int b[1009][1009];
double avga[1009], avgb[1009];
double avgtotal[1009];
int c[1000009][2];


int main() {
	int m, n;
	cin>>m>>n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>a[i][j];
		}
	}
	double sum=0;
	for(int i=1; i<=n; i++) {
		sum=0;
		for(int j=1; j<=m; j++) {
			sum+=a[i][j];
		}
		avga[i] = sum/m;
		sum = 0;
		for(int j=1; j<=m; j++) {
			sum+=(a[i][j] - avga[i])*(a[i][j]-avga[i]);
		}
		avga[i] = sum/m;
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>b[i][j];
		}
	}

	for(int i=1; i<=n; i++) {
		sum=0;
		for(int j=1; j<=m; j++) {
			sum+=b[i][j];
		}
		avgb[i] = sum/m;
		sum = 0;
		for(int j=1; j<=m; j++) {
			sum+=(b[i][j] - avgb[i])*(b[i][j]-avgb[i]);
		}
		avgb[i] = sum/m;
	}

	for(int i=1; i<=n; i++) {
		avgtotal[i] = avga[i] + avgb[i];
//		cout<<avgtotal[i]<<endl;
	}
//	1 5 3 2
	int cnt=0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<n-i+1; j++) {
			if(avgtotal[j]>avgtotal[j+1]) {
				cnt++;
				c[cnt][0]=j;
				c[cnt][1]=j+1;
				swap(avgtotal[j], avgtotal[j+1]);
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=1; i<=cnt; i++) {
		cout<<c[i][0]<<" "<<c[i][1]<<endl;
	}
	return 0;
} 
