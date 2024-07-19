#include<bits/stdc++.h>
using namespace std;
queue<string> q;
int main(){
	string ss="abc";
	q.push(ss);
	ss[1]='.';
	q.push(ss);
	ss[1]='b';
	q.push(ss);
	while(!q.empty()) {
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}
