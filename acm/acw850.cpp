#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXM 100
int head[MAXN]; //ÿ���ڵ�����ĵ�һ���ߵ��յ��Ȩ����ver,edge�����е�λ�� 
int nxt[MAXM]; //ģ��ָ�룬��ʾ����ͬ�ڵ��������һ������ver,edge�����е�λ�� 
int edge[MAXM]; 
int ver[MAXM]; //�ߵ����� 
int tot=0;

void addEdge(int x, int y, int z) {
	tot++;
	ver[tot]=y;
	edge[tot]=z;
	//�ڱ�ͷ������ 
	nxt[tot]=head[x]; 
	head[x]=tot;
}

//���ʴӵ�x���������б� 
void visitGraph(int x) {
	for(int i=head[x];i;i=nxt[i]) {
		int y=ver[i];
		int z=edge[i];
	}
}
int clearGraph() {
	memset(head, 0, sizeof(head));
	tot=0; 
}
