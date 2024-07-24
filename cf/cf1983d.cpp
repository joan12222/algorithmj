#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100005
int t;
int mergeCount(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
	int i=left; //左边数组 
	int j=mid+1; //右边数组 
	int k=left; //结果数组 
	int ans=0;
	
	while(i<=mid&&j<=right) {
		if(arr[i]<=arr[j]) {
			temp[k++]=arr[i++];
		}else {
			temp[k++]=arr[j++];
			ans+=mid-i+1;
		}
	}
	while(i<=mid) {
		temp[k++]=arr[i++];
	}
	while(j<=right) {
		temp[k++]=arr[j++];
	}
	for(int i=left; i<=right;i++) {
		arr[i]=temp[i];
	}
	return ans;
}
int mergeSortCount(vector<int> &arr, vector<int> &temp, int left, int right) {
	int ans=0;
	if(left<right) {
		int mid=(left+right)/2;
		ans+=mergeSortCount(arr, temp, left, mid);
		ans+=mergeSortCount(arr, temp, mid+1, right);
		ans+=mergeCount(arr, temp, left, mid, right);
	}
	return ans;
}
int calc(vector<int> &arr) {
	vector<int> temp(arr.size());
	return mergeSortCount(arr, temp, 0, arr.size()-1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++) {
    	cin>>a[i];
	}
    for(int i=0; i<n; i++) {
    	cin>>b[i];
	}
	auto va=a, vb=b;
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	if(va!=vb) {
		cout<<"NO";
		cout<<endl;
		return;
	}
//	printf("a is %d, b is %d\n",calc(a), calc(b));
	int n1=calc(a)%2;
	int n2=calc(b)%2;
	if(n1==n2) cout<<"YES";
	else cout<<"NO";
	cout<<endl;
}

int main() {
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
