#include<bits/stdc++.h>
using namespace std;
int goal[8];
int src[8];
int ans[8]={0};
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=7;i++){
		cin>>goal[i];
	}
	sort(goal+1, goal+8);
	while(n--) {
		for(int i=1;i<=7;i++){
			cin>>src[i];
		}
		sort(src+1, src+8);
		int cnt=0;
		int i=1, j=1;
		while(i<8 && j<8){
				if(goal[i]==src[j]) {
					cnt++;
					i++;
					j++;
				} else if(goal[i]<src[j]) {
					i++;
				} else {
					j++;
				}
		}
		ans[cnt]++;
	}
	for(int i=1; i<=7; i++) {
		cout<<ans[7-i+1]<<" ";
	}
	return 0;
}