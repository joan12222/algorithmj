#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
struct Node {
	int r; //����ʱ�� 
	int e; //ֵ 
	Node(int _r, int _e) {
		r=_r,e=_e;
	}
};
deque<Node> q;
int f[100005];
int c[100005][2];
int main() {
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		int v,w,t;
		cin>>v>>w>>t;
		//mod,��������ÿһ�����ת��,
		//����ĳ����Ʒ����Ϊ4����5����  
		//j:�ڼ��� 
		//����jΪ1������ת�Ƶ�5,9,13,17,�±�ֱ��Ӧ2,3,4,5,�±�Ϊk+1 
		for(int j=0;j<v;j++) {
//			int k=0,l=1;
			//x:ȡ����01����,Ҳ�ǵ������е��±� 
			for(int p=j,x=1;p<=m;p+=v,x++) { //����������m/v 
				int e=f[p]-x*w,r=x+t; 
				//�ϵ�ֵ��С�ģ�ֱ��ɾ��
//				for(;k>=l&&c[k][0]<=e;--k); 
				while(!q.empty()&&(q.back().e<=e)) q.pop_back();
				//ÿһ���е�p����ת�Ƶ�k+1��k+t,��k+t���� 
//				c[++k][0]=e;c[k][1]=r;
				q.push_back(Node(r, e));
//				f[p]=c[l][0]+x*w;
				f[p]=q.front().e+x*w;
//				for(;k>=l&&c[l][1]==x;++l);
				while(!q.empty()&&(q.front().r==x)) q.pop_front();
			}
		}
	}
	cout<<f[m]<<endl;
	return 0;
}

