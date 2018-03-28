#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf 100000
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 1124

int C[22] , S , T , cap[N][N] , A[N][22];

struct flow_graph{
    int f,MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    
    flow_graph(){}
    
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = f = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    
    void clear(){
        fill(last,last+MAX_V,-1);
        E = f = 0;
    }
    
    void add_edge(int u, int v, int uv, int vu = 0){
        to[E] = v, cap[E] = uv, next[E] = last[u]; last[u] = E++;
        to[E] = u, cap[E] = vu, next[E] = last[v]; last[v] = E++;
    }
        
    bool bfs(){
        fill(dist,dist+MAX_V,-1);
        head = tail = 0;
                
        q[tail] = t; ++tail;
        dist[t] = 0;
                
        while(head<tail){
            int v = q[head]; ++head;
            
            for(int e = last[v];e!=-1;e = next[e]){
                if(cap[e^1]>0 && dist[to[e]]==-1){
                    q[tail] = to[e]; ++tail;
                    dist[to[e]] = dist[v]+1;
                }
            }
        }
        
        return dist[s]!=-1;
    }
        
    int dfs(int v, int f){
        if(v==t) return f;
                
        for(int &e = now[v];e!=-1;e = next[e]){
            if(cap[e]>0 && dist[to[e]]==dist[v]-1){
                int ret = dfs(to[e],min(f,cap[e]));
                                
                if(ret>0){
                    cap[e] -= ret;
                    cap[e^1] += ret;
                    return ret;
                }
            }
        }
                
        return 0;
    }
        
    int max_flow(int source, int sink){
        s = source; t = sink;
        int x;
                
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
                        
            while(true){
                x = dfs(s,INT_MAX);
                if(x==0) break;
                f += x;
            }
        }
                
        return f;
    }
}G(1000+20+2,1000+1000*20+20);


int b , n;

void build(int lo ,int hi){
    G.clear();
    for(int i = 1 ; i <= b ; i++)
        G.add_edge( S , i , C[i] );
    
    for(int i = 1 ; i <= n ; i++){
        G.add_edge( b + i , T , 1 );
        for(int j = lo ; j <= hi ; j++)
            G.add_edge( A[i][j] , b + i , 1  );
    }
    
}

/*void build(int lo,int hi){
    for(int i = 0 ; i < T + 1 ; i++)
        adj[i].clear();
    
    me( cap , 0 );
    for(int i = 1 ; i <= b ; i++){
        adj[S].pb( i ); cap[S][i] = C[i];
        adj[i].pb( S );
    }
    for(int i = 1 ; i <= n ; i++){
        adj[b+i].pb( T ); cap[b + i][T] = 1;
        adj[T].pb( b+i );
        for(int j = lo ; j <= hi ; j++){
            adj[A[i][j]].pb( b + i ); cap[A[i][j]][b + i] = 1;
            adj[b + i].pb( A[i][j] ); cap[b + i][A[i][j]] = 0;
        }
    }
}*/

int f(int lo , int hi){
    build( lo , hi );
    return G.max_flow( S , T );
}

int main(){
    scanf("%d%d",&n,&b);
    for(int i = 1 ; i <= n ; i++){
        int x;
        for(int j = 0 ; j < b ; j++){
            sc(A[i][j]);
        }
    }
    for(int i = 1 ; i <= b ; i++)
            sc(C[i]);
        
    S = 0 , T = n + b + 1;
    int ans = 100;
    for(int i = 0 ; i < b ; i++){
        
        G.clear();
        for(int j = 1 ; j <= b ; j++)
            G.add_edge( S , j , C[j] );
        for(int j = 1 ; j <= n ; j++)
            G.add_edge( b + j , T , 1 );
                
        for(int j = i ; j < b ; j++){
            
            for(int k = 1 ; k <= n ; k++)
                G.add_edge( A[k][j] , b + k , 1 );
            
            if( G.max_flow( S , T ) == n ){
                ans = min( ans , j - i + 1 );
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
