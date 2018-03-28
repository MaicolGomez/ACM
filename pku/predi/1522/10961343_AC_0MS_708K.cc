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
#define fi first
#define se second
#define MOD 10009
#define N 100005


int n , ct , fa[N];

int FIND(int x){
    return (fa[x]==x)?x:( fa[x] = FIND(fa[x]) );
}

void UNION(int x,int y){
    fa[ FIND(x) ] = FIND(y);
}

int main(){
    int test = 0;
    while( sc(n) , n ){
        map<ll,int> m;
        vector< pii > v;
        ct = 0;
        bool first = 1;
        int v1 , v2;
        while( 1 ){
            ll x = 0 , y = 0 , C = 1;
            int a;
            for(int i = 0 ; i < n ; i++){
                sc(a);
                if( a == -1) goto gg;
                x += a * C;
                C *= (n+1);
            }
            C = 1;
            for(int i = 0 ; i < n ; i++){
                sc( a );
                y += a * C;
                C *= (n + 1);
            }
            if( m.find(x) == m.end() ) m[x] = ct++;
            if( m.find(y) == m.end() ) m[y] = ct++;
            if( first )
                v1 = m[x] , v2 = m[y];
            else{
                v.pb( mp( m[x] , m[y] ) );
            }
            first = 0;
        }
        gg:;
        
        for(int i = 0 ; i < ct ; i++) fa[i] = i;
        
        for(int i = 0 ; i < v.size() ; i++)
            if( FIND( v[i].fi ) != FIND( v[i].se ) )
                UNION( v[i].fi , v[i].se );
        
        if( FIND(v1) == FIND(v2) ) printf("Maze #%d can be travelled\n",++test);
        else printf("Maze #%d cannot be travelled\n",++test);
    }
    return 0;
}