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
#define MOD 10009
#define N 105

struct nodo{
    int d;
    pii u;
    nodo(){}
    nodo(pii U,int D){
        u = U , d = D;
    }
};

bool operator<(nodo A,nodo B){
    return A.d > B.d;
}

int d[N][N] , cost[N][N];
int dx[8] = { 1 , -1 , 0 , 0 };
int dy[8] = { 0 , 0 , 1 , -1 };
bool vis[N][N];

int main(){
    int tc , tx , ty , T , C , R;
    sc(tc);
    while(tc--){
        sc(R),sc(C);
        for(int i = 0 ; i < R ; i++)
            for(int j = 0 ; j < C ; j++)
                sc(cost[i][j]) , d[i][j] = inf , vis[i][j] = 0;
        sc(tx),sc(ty),sc(T); tx--, ty--;
        priority_queue<nodo> Q;
        Q.push( nodo( mp( 0 , 0 ) , cost[0][0] ) );
        d[0][0] = cost[0][0];
        while( !Q.empty() ){
            pii q = Q.top().u; Q.pop();
            int x = q.fi , y = q.se , dd = d[x][y];
            if( x == tx && y == ty ) break;
            if( vis[x][y] ) continue;
            vis[x][y] = 1;
            for(int i = 0 ; i < 4 ; i++){
                int u = x + dx[i] , v = y + dy[i];
                if( u >= 0 && u < R && v >= 0 && v < C && d[x][y] + cost[u][v] < d[u][v] ){
                    d[u][v] = d[x][y] + cost[u][v];
                    Q.push( nodo( mp(u,v) , d[u][v] ) );
                }
            }
        }
        if( d[tx][ty] <= T )
            printf("YES\n%d\n",T-d[tx][ty]);
        else printf("NO\n");
    }
    return 0;
}
