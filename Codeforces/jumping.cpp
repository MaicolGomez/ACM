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
#define ios ios::sync_with_stdio(0);
#define N 101001

struct nodo{
    int u , w , d;
    nodo(){}
    nodo(int U,int W,int D){
        u = U , w = W , d = D;
    }
};

bool operator<(nodo A,nodo B){
        return A.d > B.d;
}

char s[2][N];
bool vis[2][N];
int d[2][N];

int main(){
    int n , k;
    while( scanf("%d%d",&n,&k) == 2 ){
        scanf("%s%s",s[0],s[1]);
        
        for(int i = 0 ; i < 2 ; i++)
            fill( d[i] , d[i] + n , inf ) , me(vis[i],0);
        
        d[0][0] = 0;
        priority_queue<nodo> Q;
        Q.push( nodo(0,0,0) );
        bool solve = 0;
        while( !Q.empty() ){
            nodo q = Q.top(); Q.pop();
            int u = q.u , w = q.w , di = q.d;
            if( vis[w][u] ) continue;
            vis[w][u] = 1;
            if( u > 0 and s[w][u-1] == '-' and d[w][u-1] > di + 1 and di < u - 1 ){
                d[w][u-1] = di + 1;
                Q.push( nodo( u - 1 , w , di + 1 ) );
            }
            if( u + 1 == n or u + k >= n ){
                solve = 1; break;
            }
            if( u + 1 < n and s[w][u+1] == '-' and d[w][u+1] > di + 1 ){
                d[w][u+1] = di + 1;
                Q.push( nodo( u + 1 , w , di + 1 ) );
            }
            
            if( s[w^1][u+k] == '-' and d[w^1][u+k] > di + 1 ){
                d[w^1][u+k] = di + 1;
                Q.push( nodo(u+k , w^1 , di + 1 ) );
            }
        }
        if( solve ) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
