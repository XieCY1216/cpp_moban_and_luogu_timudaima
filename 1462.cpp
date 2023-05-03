#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=5e4+5;
int n,m,b,f[N];
struct ed{
	int to,next,w;
}edge[M]; 
int head[N],cnt=0;
void build(int u,int v,int w){
	edge[++cnt].w=w;
	edge[cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int dis[N];
bool vis[N];
struct nd{
	int dis,pos;
	bool operator<(const nd a) const{
		return a.dis<dis;
	}
};
priority_queue<nd> q;
void dijkstra(int s){
	memset(dis,0x7f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[1]=0;
	q.push({0,1});
	while(!q.empty()){
		nd x=q.top();
		q.pop();
		if(vis[x.pos]||f[x.pos]>s) continue;
		vis[x.pos]=1;
		for(int i=head[x.pos];i!=-1;i=edge[i].next){
			if(f[edge[i].to]<=s&&dis[edge[i].to]>dis[x.pos]+edge[i].w){
				dis[edge[i].to]=dis[x.pos]+edge[i].w;
				q.push({dis[edge[i].to],edge[i].to});
			}
		}
	}
}

int main(){
	int r=-99;
	memset(head,-1,sizeof(head));
	scanf("%d%d%d",&n,&m,&b);
	for(int i=1;i<=n;i++){
		scanf("%d",&f[i]);
		r=max(r,f[i]);
	}
	int maxn=r;
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		build(u,v,w);
	}
	int l=min(f[1],f[n]);
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		dijkstra(mid);
		printf("%d",mid);
		if(dis[n]>b){
			if(maxn==mid){
				printf("AFK");
				return 0;
			}
			l=mid+1;
		}
		else{
			if(r==mid) break;
			r=mid;
		}
	}
	printf("%d",mid);
	return 0;
}

