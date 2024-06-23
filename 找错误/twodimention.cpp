#include<iostream>
#include<vector>
using namespace std;
int a[1001][1001];//index is 0-1000, can't define such a large area in the main function.

int main(){
	int n,m;
	int i,j;
	int len=0;
	vector<int> ans=vector<int>(0);
	cin>>n>>m;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			if(a[i][j]!=0) {
				len++;
				ans.push_back(a[i][j]);
			} else {
				len=0;
				ans.clear();
			}
		}
		len=0;
	}
	cout<<"len is "<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}