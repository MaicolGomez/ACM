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
#define N 1005

set< pii > S;
map< pii , int > m;
int dx[8] = { 1 , -1 , 0 , 0 , 1 , -1 , -1 , 1 };
int dy[8] = { 0 , 0 , 1 , -1 , -1 , 1 , -1 , 1 };

int main(){
    int x0 , y0 , x1 , y1;
    while( scanf("%d%d%d%d",&x0,&y0,&x1,&y1) == 4 ){
        int n , r , a , b;
        S.clear();
        m.clear();
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d%d",&r,&a,&b);
            for(int j = a ; j <= b ; j++)
                S.insert( mp(r,j) );
        }
        queue< pii > Q;
        m[ mp(x0,y0) ] = 0;
        Q.push( mp(x0 , y0) );
        int ans = -1;
        while( !Q.empty() ){
            pii q = Q.front(); Q.pop();
            int x = q.fi , y = q.se;
            int d = m[ mp(x,y) ];
            if( x == x1 && y == y1 ){
                ans = d;
                break;
            }
            for(int i = 0 ; i < 8 ; i++){
                int u = x + dx[i] , v = y + dy[i];
                if( S.find( mp(u,v) ) != S.end() && m.find( mp(u,v) ) == m.end() ){
                    m[ mp(u,v) ] = d + 1;
                    Q.push( mp(u,v) );
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
