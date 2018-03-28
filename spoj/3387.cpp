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
#define N 21
#define D 12

int r , c , k , d[N][N][D];
char s[N][N][D];
struct nodo{
    int x , y , l , d;
    nodo(){}
    nodo(int X,int Y,int L,int dd){
        x = X , y = Y , l = L , d = dd;
    }
};

int dx[5] = { 0 , 1 , -1 , 0 , 0 };
int dy[5] = { 0 , 0 , 0 , 1 , -1 };

int f(int x,int y,int z){
    
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++)
            for(int ii = 0 ; ii < k ; ii++)
                d[i][j][ii] = inf;
    
    d[0][0][0] = 0;
    queue<nodo> Q;
    Q.push( nodo( x , y , z , 0 ) );
    while( !Q.empty() ){
        nodo q = Q.front(); Q.pop();
        x = q.x , y = q.y;
        int l = q.l , di = q.d;
        int go = (l+1)%k;
        if( x == r - 1 && y == c - 1 ) return di;
        
        for(int i = 0 ; i < 5 ; i++){
            int u = x + dx[i] , v = y + dy[i];
            if( u >= 0 && u < r && v >= 0 && v < c )
                if( s[go][u][v] == '0' && d[u][v][go] > di + 1 ){
                    d[u][v][go] = di + 1;
                    Q.push( nodo( u , v , go , di + 1 ) );
                }
        }
    }
    return -1;
}

int main(){
    int test = 0;
    while( scanf("%d%d%d",&r,&c,&k) == 3 && (r||c) ){
        for(int i = 0 ; i < k ; i++)
            for(int j = 0 ; j < r ; j++)
                scanf("%s",s[i][j]);
            
        int ans = f( 0 , 0 , 0 );
        if( ans != -1 ) printf("Case %d: Luke and Leia can escape in %d steps.\n",++test,ans);
        else printf("Case %d: Luke and Leia cannot escape.\n",++test);
    }
    return 0;    
}
