#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=5e3+5;
int n,m,s=1,u,v,w,t;
struct e {
	int next,to,w;
} edge[M];
int head[N],cnt=0;
void build(int u,int v,int w) {
	edge[++cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int dis[N],cou[N];
bool vis[N];
queue<int> q;
bool spfa(int s) {
	memset(dis,0x7f,sizeof(dis));
	memset(cou,0,sizeof(cou));
	memset(vis,false,sizeof(vis));
	dis[s]=0;
	vis[s]=1;
	q.push(s);
	while(!q.empty()) {
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=head[x]; i!=-1; i=edge[i].next) {
			if(dis[edge[i].to]>dis[x]+edge[i].w) {
				dis[edge[i].to]=dis[x]+edge[i].w;
				cou[edge[i].to]=cou[x]+1;
				if(cou[edge[i].to]>=n+1) {
					return false;
				}
				if(!vis[edge[i].to]) {
					q.push(edge[i].to);
					vis[edge[i].to]=1;
				}
			}
		}

	}
	return true;
}
int main() {
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	
	for(int i=1;i<=n;i++){
		build(0,i,0);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&u,&v,&w);
		build(v,u,w);
	}
	if(!spfa(0)) {
		printf("NO\n");
	} else {
		for(int i=1;i<=n;i++){
			printf("%d ",dis[i]);
		}
	}

	return 0;
}

