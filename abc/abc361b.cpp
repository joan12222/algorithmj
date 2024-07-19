#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct Point {
	int x,y,z;
};
struct Cube {
	Point p1;
	Point p2;
}; 
bool inCube(Point p, Cube c) {
	if((p.x>c.p1.x&&p.x<c.p2.x)&&(p.y>c.p1.y&&p.y<c.p2.y)&&(p.z>c.p1.z&&p.z<c.p2.z)) return true;
	return false;
}
bool theSame(Point p1, Point p2) {
	if((p1.x==p2.x)&&(p1.y==p2.y)&&(p1.z==p2.z)) return true;
	return false;
}
ll calc(Point p1, Point p2) {
	return abs(p1.x-p2.x)*abs(p1.y-p2.y)*abs(p1.z-p2.z);
}
int main() {
	Cube c1,c2;
	cin>>c1.p1.x>>c1.p1.y>>c1.p1.z>>c1.p2.x>>c1.p2.y>>c1.p2.z;
	cin>>c2.p1.x>>c2.p1.y>>c2.p1.z>>c2.p2.x>>c2.p2.y>>c2.p2.z;
/*	if(theSame(c1.p1, c2.p1)&&theSame(c1.p2, c2.p2)) ans=calc(c1.p1, c1.p2);
	else if(theSame(c1.p1, c2.p1)&&inCube(c2.p2, c1)) ans=calc(c1.p1, c2.p2);
	else if(theSame(c1.p2, c2.p2)&&inCube(c1.p1, c2)) ans=calc(c1.p2, c1.p1);
	else if(theSame(c1.p2, c2.p2)&&inCube(c1.p1, c2)) ans=calc(c1.p2, c1.p1);
	else if(theSame(c1.p2, c2.p2)&&inCube(c2.p1, c2)) ans=calc(c1.p2, c2.p1);
	else if(inCube(c1.p1,c2)&&inCube(c1.p2,c2)) ans=calc(c1.p1, c1.p2);
	else if(inCube(c2.p1,c1)&&inCube(c2.p2,c1)) ans=calc(c2.p1, c2.p2);
	else if(inCube(c2.p1,c1)&&inCube(c1.p2,c2)) ans=calc(c2.p1, c1.p2);
	else if(inCube(c1.p1,c2)&&inCube(c2.p2,c1)) ans=calc(c1.p1, c2.p2);
	else ans=0;
	if(ans==0) cout<<"No";
	else cout<<"Yes";
	*/
	if((theSame(c1.p1, c2.p1)&&theSame(c1.p2, c2.p2)) ||
		(theSame(c1.p1, c2.p1)&&inCube(c2.p2, c1)) ||
		(theSame(c1.p2, c2.p2)&&inCube(c1.p1, c2)) ||
		(theSame(c1.p2, c2.p2)&&inCube(c1.p1, c2)) || 
		(theSame(c1.p2, c2.p2)&&inCube(c2.p1, c2)) ||
		(inCube(c1.p1,c2)&&inCube(c1.p2,c2)) ||
		(inCube(c2.p1,c1)&&inCube(c2.p2,c1)) ||
		(inCube(c2.p1,c1)&&inCube(c1.p2,c2)) ||
		(inCube(c1.p1,c2)&&inCube(c2.p2,c1)) )
		cout<<"Yes";
	else cout<<"No";

	return 0;
}
