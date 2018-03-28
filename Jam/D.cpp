#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 105

int mat[5*N][5*N] , r , c , S , T;

struct flow_graph{
    int MAX_V,E,s,t,head,tail;
    int *cap,*to,*next,*last,*dist,*q,*now;
    flow_graph(){}
    flow_graph(int V, int MAX_E){
        MAX_V = V; E = 0;
        cap = new int[2*MAX_E], to = new int[2*MAX_E], next = new int[2*MAX_E];
        last = new int[MAX_V], q = new int[MAX_V];
        dist = new int[MAX_V], now = new int[MAX_V];
        fill(last,last+MAX_V,-1);
    }
    void clear(){
        fill(last,last+MAX_V,-1);
        E = 0;
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
        int f = 0;
        int x;
        while(bfs()){
            for(int i = 0;i<MAX_V;++i) now[i] = last[i];
			
            while(true){
                x = dfs(s,inf);
                if(x==0) break;
                f += x;
            }
        }
        return f;
    }
};

flow_graph F;
int dx[4] = { -1 ,  0 , 0 , 1 };
int dy[4] = { 0 , -1 , 1 , 0 };

int main(){
    int tc , x;
    x = sc(tc);
    for(int tt = 1 ; tt <= tc ; tt++){
        printf("Case #%d: ",tt);
        int B;
        x = scanf("%d%d%d",&c,&r,&B);
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                mat[i][j] = 1;
        for(int i = 0 ; i < B ; i++){
            int x1 , x2 , y1 , y2;
            x = scanf("%d%d%d%d",&y1,&x1,&y2,&x2);
            if( x2 < x1 ) swap( x1 , x2 ) , swap( y1 , y2 );
            for(int j = x1 ; j <= x2 ; j++)
                for(int  k = y1 ; k <= y2 ; k++)
                    mat[j][k] = 0;
        }
        S = 2 * r * c; T = S + 1;
        int A = r * c;
        F = flow_graph( T + 1 , 1000 + 5 * T + 1 );
        for(int i = 0 ; i < c ; i++)
            if( mat[0][i] ) F.add_edge( S , i , 1 );
                    
        for(int i = 0 ; i < c ; i++)
            if( mat[r-1][i] ) F.add_edge( (r-1) * c + i + A , T , 1 );
        
        for(int i = 0 ; i < r ; i++)
            for(int j = 0 ; j < c ; j++)
                if( mat[i][j] ) F.add_edge( i * c + j , i * c + j + A , 1 );
        
        for(int i = 0 ; i + 1 < r ; i++){
            for(int j = 0 ; j < c ; j++){
                for(int k = 0 ; k < 4 ; k++){
                    int u = i + dx[k] , v = j + dy[k];
                    if( u >= 0 and u < r and v >= 0 and v < c and mat[u][v] ){
                        F.add_edge( i * c + j + A , u * c + v , 1 );
                    }
                }   
            }
        }
        printf("%d\n",F.max_flow(S,T));
    }
    return 0;
}
