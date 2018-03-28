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
#define N 1005

int n , fa[N];

int FIND(int x){
    return (fa[x] == x)?x:(fa[x] = FIND(fa[x]));
}

void UNION(int x,int y){
    fa[ FIND(x) ] = FIND(y);
}

int main(){
    int x;
    while( sc(n) == 1 ){
        
        for(int i = 0 ; i < n ; i++) fa[i] = i;
        
        vector< pair< int , pii > > v;
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++){
                sc(x);
                if( x != -1 ){
                    if( x == 0 ) UNION( i , j );
                    else v.pb( mp( x , mp( i , j ) ) );
                }
            }
            
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                
        sort( all(v) );
        int ans = 0;
        for(int i = 0 ; i < v.size() ; i++){
            int a = v[i].se.fi , b = v[i].se.se;
            if( FIND(a) != FIND(b) ){
                UNION( a , b );
                ans += v[i].fi;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
