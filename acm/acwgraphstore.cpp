#include <bits/stdc++.h>
using namespace std;
#define MAXN 100
#define MAXM 100
int head[MAXN]; //每个节点出发的第一条边的终点和权重在ver,edge数组中的位置 
int nxt[MAXM]; //模拟指针，表示从相同节点出发的下一条边在ver,edge数组中的位置 
int edge[MAXM]; 
int ver[MAXM]; //边的数量 
int tot=0;

void addEdge(int x, int y, int z) {
	tot++;
	ver[tot]=y;
	edge[tot]=z;
	//在表头处插入 
	nxt[tot]=head[x]; 
	head[x]=tot;
}

//访问从点x出发的所有边 
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
