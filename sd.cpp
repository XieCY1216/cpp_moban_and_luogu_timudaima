#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;
struct e{
	int next,from,to;
};
struct G{
	e edge[M];
	int head[N],cnt=0;
	void init(){
		memset(head,-1,sizeof(head));
	}
	void build(int u,int v){
		edge[++cnt]={head[u],u,v};
		head[u]=cnt;
	}
}bef,aft;
int n,m;
void tarjan(){
	
}
int main(){
	bef.init();
	aft.init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		bef.build(u,v);
	}
	return 0;
}

