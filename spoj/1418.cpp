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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 102

int n , m , t[N][N] , a , b , c , d;
int dx[4] = { 1 , -1 , 0 , 0 };
int dy[4] = { 0 , 0 , -1 , 1 };

int get(int x,int y){
    return min( abs(a-x) + abs(b-y) , abs(c-x) + abs(d-y) );
}

bool bfs(int x,int y){
    t[x][y] = 0;
    queue< pii > Q;
    Q.push( mp(x,y) );
    while( !Q.empty() ){
        pii q = Q.front(); Q.pop();
        x = q.fi , y = q.se;
        //cout << x << " -- " << y << endl;
        for(int i = 0 ; i < 4 ; i++){
            int u = x + dx[i] , v = y + dy[i];
            int g = get( u , v );
            //cout << u << " " << v << " " << g << endl;
            if( u >= 1 && u <= n && v >= 1 && v <= m && t[u][v] == -1 && g > t[x][y] + 1 ){
                t[u][v] = t[x][y] + 1;
                if( u == 1 || u == n || v == 1 || v == m ) return 1;
                Q.push( mp(u,v) );
            }
        }
    }
    return 0;
}

int main(){
    while( scanf("%d%d",&n,&m) == 2 ){
        int k , x , y;
        sc(k);
        for(int i = 0 ; i < k ; i++){
            scanf("%d%d",&x,&y);
            scanf("%d%d",&a,&b);
            scanf("%d%d",&c,&d);
            me(t,-1);
            bool can = bfs(x , y);
            if( can ) printf("YES");
            else printf("NO");
            printf("\n");
        }
    }
    return 0;
}
