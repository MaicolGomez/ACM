#include<iostream>
#include<cstring>
#include<climits>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define FF(a, b) for(a=0; a<b; a++)
#define CC(a,b) memset(a, b, sizeof(a))

#define M 120
#define type int
#define inf INT_MAX

// Problem -- root = 0, need MinimunCostArborescence

struct Node{
		int u , v;
		type cost;
}E[M*M];

struct node{
		int x, y;
}q[M];

int pre[M],ID[M],vis[M];  
type In[M];               


type Directed_MST(int root,int NV,int NE) {
		type ret = 0;
		while(true) {

				int i;
				FF(i,NV) In[i] = inf;
				FF(i,NE) {
						int u = E[i].u;
						int v = E[i].v;
						if(E[i].cost < In[v] && u != v) {
								pre[v] = u;
								In[v] = E[i].cost;
						}
				}               
				FF(i,NV) {
						if(i == root) continue;
						if(In[i] == inf)	return -1;
				}

				int cntnode = 0;
				CC(ID,-1);
				CC(vis,-1);
				In[root] = 0;
				FF(i,NV) {//����ÿ����
						ret += In[i];
						int v = i;
						while(vis[v] != i && ID[v] == -1 && v != root) {
								vis[v] = i;
								v = pre[v];
						}
						if(v != root && ID[v] == -1) {
								for(int u = pre[v] ; u != v ; u = pre[u]) {
										ID[u] = cntnode;
								}
								ID[v] = cntnode ++;
						}
				}
				if(cntnode == 0)	break;
				FF(i,NV) if(ID[i] == -1) {
						ID[i] = cntnode ++;
				}

				FF(i,NE) {
						int v = E[i].v;
						E[i].u = ID[E[i].u];
						E[i].v = ID[E[i].v];
						if(E[i].u != E[i].v) {
								E[i].cost -= In[v];
						}
				}
				NV = cntnode;
				root = ID[root];
		}
		return ret;
}

int main()
{
		int n, m;
		int i, j, k;

		while(scanf("%d %d", &n, &m) == 2)
		{
				if(!n && !m)
						break;
				
				for(i=0; i<m; i++)
				{
						int a, b, c;
						scanf("%d %d %d", &a, &b, &c); // Edge a -- > b whit cost c
						a--;
						b--;
						E[i].u = a;
						E[i].v = b;
						E[i].cost = c;			
				}
				
			
				int cnt = Directed_MST(0, n, m);

				if(cnt == -1)
						printf("impossible\n");
				else
						printf("%d\n", cnt);
				
				
		}
}
