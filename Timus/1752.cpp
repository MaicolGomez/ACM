#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<climits>
#include<set>
#include<deque>
#include<queue>
#include<map>
#include<climits>
#include<string>
#include<stack>
#include<sstream>
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
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 20005

vi adj[N];
int n , tam;
bool vis[N];
int F[N];

int bfs(int u){
    me(vis,0);
    vector<int> d( n + 2 , -1 );
    queue<int> Q;
    Q.push( u );
    d[u] = 0;
    F[u] = -1;
    int di = 0 , choose = u;
    while( !Q.empty() ){
        int q = Q.front(); Q.pop();
        if( vis[q] ) continue;
        vis[q] = 1;
        for(int i = adj[q].size() - 1 ; i >= 0 ; i--){
            int v = adj[q][i];
            if( d[v] == -1 ){
                d[v] = d[q] + 1;
                F[v] = q;
                if( d[v] > di ) di = d[v] , choose = v;
                Q.push( v );
            }
        }
    }
    return choose;
}

int lugar[N] , esta[N];

void proc(int p,int q){
    int x = q , r = 1;
    while( x != p ){
        //cout << x  + 1 << " --> " << F[x] + 1 << endl;
        esta[r] = x;
        lugar[x] = r++;
        x = F[x];
    }
    lugar[x] = r , esta[r] = x;
    tam = r;
}

int C[N] , L[N] , R[N];

void dfs(int u,int lvl,int fa,int c){
    vis[u] = 1;
    L[u] = lvl;
    F[u] = fa;
    C[u] = c;
    for(int i = adj[u].size() - 1 ; i >= 0 ; i--){
        int v = adj[u][i];
        if( vis[v] or lugar[v] >= 0 ) continue;
        dfs( v , lvl + 1 , u , c );
    }
}

int M[N][18];

void init(){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; (1<<j) < n ; j++)
            M[i][j] = -1;
    
    for(int i = 0 ; i < n ; i++)
        M[i][0] = F[i];
    
    for(int j = 1 ; (1<<j) < n ; j++)
        for(int i = 0 ; i < n ; i++)
            if( M[i][j-1] != -1 )
                M[i][j] = M[ M[i][j-1] ][j-1];
}

int get(int u,int d){
    for(int i = 15  ; i >= 0 ; i--)
        if( M[u][i] != -1 and (1<<i) <= d )
            u = M[u][i] , d -= (1<<i);
    return u;
}

int main(){
    int m;
    while( scanf("%d%d",&n,&m) == 2 ){
        me(lugar,-1);
        int a , b;
        for(int i = 0 ; i < n - 1 ; i++){
            scanf("%d%d",&a,&b); a--,b--;
            adj[a].pb(b), adj[b].pb(a);
        }
        int x = bfs( 0 );
        int y = bfs( x );
        proc( x , y );
        
        //cout << x + 1 << " " << y + 1 << endl;
        //cout << tam << endl;
        //for(int i = 1 ; i < 7 ; i++)
            //cout << esta[i] + 1 << endl;
        me(vis,0);
        me(F,-1);
        int c = 0;
        for(int i = 0 ; i < n ; i++)if( lugar[i] >= 0 ){
            R[c] = i;
            //cout << i + 1 << " -- >  aca lanza " << endl; 
            dfs( i , 0 , -1 , c++ );
        }
        init();
        //for(int i = 1 ; i <= tam ; i++)
           // cout << ": " << esta[i] + 1 << endl;
        int d;
        while( m-- ){
            scanf("%d%d",&a,&d); a--;
            //cout << a + 1 << " " << d << endl;
            if( L[a] >= d ) printf("%d\n",get( a , d ) + 1);
            else{
                int raiz = R[ C[a] ];
                //cout << a + 1 << " d: " << d << " raiz: " << raiz + 1 << " L: " << L[a] << endl;
                d -= L[a];
                int estoy = lugar[raiz];
                //cout << "nuevo d: " << d << " lugar: " << lugar[raiz]  << " dif: " << tam - estoy  << endl;
                if( max( estoy - 1 , tam - estoy ) < d ) printf("%d\n",0);
                else if( tam - estoy >= d ) printf("%d\n", esta[ estoy + d ] + 1 );
                else printf("%d\n", esta[ estoy - d ] + 1);
            }
        }
    }
    
    return 0;
}
