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

int n , t[N][2];
vi adj[N] , A[N];
bool vis[N];

void g(int u){
    vis[u] = 1;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        if( !vis[v] ){
            A[u].pb(v);
            g( v );
        }
    }
    return;
}

int f(int u,int need){
    if( A[u].size() == 0 ) return need;
    int &ret = t[u][need];
    if( ret != -1 ) return ret;
    ret = 0;
    int a = 0 , b = 0;
    for(int i = 0 ; i < A[u].size() ; i++){
        int v = A[u][i];
        a += f(v , 1);
        b += f(v , 0);
    }
    ret = 1 + b;
    if( need == 0 ) ret = min( ret , a );
    return ret;
}

int main(){
    sc(n);
    int u , v;
    for(int i = 0 ; i < n - 1 ; i++){
        sc(u) , sc(v); u--,v--;
        adj[u].pb(v) , adj[v].pb(u);
    }
    g( u );
    me( t , -1 );
    cout << min( f( u , 0 ) , f( u , 1 ) ) << endl;
    return 0;
}
