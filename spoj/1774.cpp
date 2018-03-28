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

int n , n1 , n2;
vi adj[N];

int f(int dvd , vi in ){
    queue<int> Q[2];
    for(int i = 0 ; i < n ; i++)
        if( in[i] == 0 )
            Q[(i<n1)?0:1].push( i );
    int ans = 0;
    while( !Q[0].empty() || !Q[1].empty() ){
        while( !Q[dvd].empty() ){
            int q = Q[dvd].front(); Q[dvd].pop();
            for(int i = 0 ; i < adj[q].size() ; i++){
                int v = adj[q][i];
                if( --in[v] == 0 ) Q[(v<n1)?0:1].push( v );
            }
        }
        dvd ^= 1;
        ans++;
    }
    return ans;
}

int main(){
    int d;
    while( sc(n1),sc(n2),sc(d) && (n1||n2||d) ){
        n = n1 + n2;
        vi in(n,0);
        for(int i = 0 ; i < n ; i++)
            adj[i].clear();
        int x , y;
        for(int i = 0 ; i < d ; i++){
            sc(x),sc(y); x--,y--;
            adj[y].pb(x);
            in[x]++;
        }
            
        int ans = 1 + min( f( 1 , in ) , f( 0 , in ) );

        printf("%d\n",ans);
    }
    return 0;
}
