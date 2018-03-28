#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8

struct nodo{
    int id , mask;
        nodo(int N , int Mask){
            id = N, mask = Mask;
        }
        nodo(){}
};

int n , e , s;
bool sw[11][11] ;
vector<int> adj[11];
int D[10][(1<<10)+1];
nodo parent[11][(1<<10)+1];
int tipo[11][(1<<10)+1];
int lugar[11][(1<<10)+1];

void change( nodo w , nodo q , int tip , int pos ){
    D[w.id][w.mask] = D[q.id][q.mask]+1;
    parent[w.id][w.mask]=q;
    tipo[w.id][w.mask]  = tip;
    lugar[w.id][w.mask] = pos;
}

int bfs(nodo S){
    if(n==1) return 0;
    memset(D,-1,sizeof(D));
    D[S.id][S.mask] = 0;
    deque<nodo> Q(1,S);
    while(!Q.empty()){
        nodo q=Q.front();
        Q.pop_front();
        vector<int> &v=adj[q.id];
        for(int i=0;i<v.size();i++){
            if(D[v[i]][q.mask]==-1){
                if( (q.mask&(1<<v[i])) ){
                    nodo w=nodo(v[i],q.mask);
                    change( w , q , 1 , w.id );
                    if( w.id == n-1 && w.mask==(1<<(n-1) ) ) return D[w.id][w.mask];
                    Q.push_back(w);
                }
            }
        }
        int vec = q.id;
        for(int i = 0 ; i < n; i++)if(vec!=i){
            if( sw[vec][i]){
                if( q.mask & (1<<i) ){
                    int mask = q.mask;
                    mask = mask^(1<<i);
                    if( D[vec][mask] == -1 ){
                        nodo w=nodo(vec,mask);
                        change( w , q , 2 , i );
                        if( w.id == n-1 && w.mask==(1<<(n-1) ) ) return D[w.id][w.mask];
                        Q.push_back( w );
                    }
                }
                else{
                    int mask = q.mask;
                    mask = mask^(1<<i);
                    if( D[vec][mask] == -1 ){
                        nodo w=nodo(vec,mask);
                        change( w , q , 3 , i );
                        if( w.id == n-1 && w.mask==(1<<(n-1) ) ) return D[w.id][w.mask];
                        Q.push_back( w );
                    }
                }
            }
        }
    }
    return -1;
}
int test = 0;
void doit(){
    for(int i = 0 ; i < 11 ; i++) adj[i].clear();
    memset(sw,0,sizeof(sw));
    int x,y;
    for(int i = 0 ; i < e ; i++){
        scanf("%d%d",&x,&y);x--,y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 0 ; i < s ; i++){
        scanf("%d%d",&x,&y);x--,y--;
        sw[x][y] = 1;
    }
    printf("Villa #%d\n",++test);
    int res = bfs(nodo(0,1));
    if( res == -1) puts("The problem cannot be solved.");
    else{
        printf("The problem can be solved in %d steps:\n",res);
        nodo x = nodo(n-1,1<<(n-1));
        vector<nodo> v;
        while(1){
            if( x.id == 0 && x.mask == 1 ) break;
            v.push_back( x ); x = parent[x.id][x.mask];
        }
        reverse( v.begin() , v.end() );
        for(int i = 0 ; i < v.size() ; i++){
            nodo x = v[i];
            int r = tipo[x.id][x.mask];
            if( r == 1 ) printf("- Move to room %d.\n",lugar[x.id][x.mask]+1);
            if( r == 2 ) printf("- Switch off light in room %d.\n",lugar[x.id][x.mask]+1);
            if( r == 3 ) printf("- Switch on light in room %d.\n",lugar[x.id][x.mask]+1);
        }
    }
    printf("\n");
}

int main(){
    while( scanf("%d%d%d",&n,&e,&s) == 3 ){
        if( !n ) break;
        doit();    
    }    
}