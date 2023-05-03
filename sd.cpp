#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e5+5;
struct e{
	int next,from,to;
};
struct G{
	e edge[M];
	int head[N],cnt=0;
	void build(int u,int v){
		edge[++cnt]={head[u],u,v};
		head[u]=cnt;
	}
}bef,aft;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	printf("%d",n+m);
	return 0;
}

