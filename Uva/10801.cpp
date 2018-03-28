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
#define inf (1<<30)
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
#define fi first
#define se second
#define MOD 10009
#define N 105
#define M 10
int n , k , T[M];
vi adj[M] , A[N];
char s[N*N];
int d[N][M];
bool vis[N][M];

struct nodo{
    int x , d , e;
    nodo(){}
    nodo(int X,int D,int E){
        x = X , d = D , e = E;
    }
};

bool operator<(nodo A,nodo B){
    return A.d > B.d;
}

int dijkstra(int floor){
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < M ; j++)
            d[i][j] = inf;
    
    d[floor][7] = 0;
    me(vis,0);
    priority_queue<nodo> Q;
    Q.push( nodo( floor , 0 , 7 ) );
    while( !Q.empty() ){
        nodo q = Q.top(); Q.pop();
        int x = q.x , di = q.d , e = q.e;
        //cout << x << " " << e << " " << di << endl;
        if( vis[x][e] ) continue;
        vis[x][e] = 1;
        if( x == k ) return di;
        for(int i = 0 ; i < A[x].size() ; i++){
            int g = A[x][i];
            if(g == e) continue;
            
            for(int j = adj[g].size() - 1 ; j >= 0 ; j--)if( adj[g][j] != x ){
                int nd = di + abs( x - adj[g][j] ) * T[g] + 60 - 60*(e==7);
                int y = adj[g][j] , ne = g;
                if( d[y][ne] > nd ){
                    d[y][ne] = nd;
                    Q.push( nodo( y , nd , ne ) );
                }
            }
        }
        
    }
    return -1;
}

int main(){
    while( scanf("%d%d",&n,&k) == 2 ){
        for(int i = 0 ; i < n ; i++)
            sc(T[i]) , adj[i].clear();
        
        for(int i = 0 ; i < 100 ; i++)
            A[i].clear();
            
        gets(s);
        for(int i = 0 ; i < n ; i++){
            gets(s);
            stringstream in(s);
            int x;
            while( in >> x ){
                adj[i].pb(x);
                A[x].pb(i);
            }
        }
        int ans = dijkstra( 0 );
        if( ans != -1 ) printf("%d\n",ans);
        else printf("IMPOSSIBLE\n");
    }
    return 0;
}
