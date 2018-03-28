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
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pi (2.0*acos(0.0))
#define inf 2000000000
#define eps 1e-6
#define ll long long
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
#define N 1505

vi adj[N];
int pa[N] , t[N][2];
int n;

int f(int u,int need){
    if( adj[u].size() == 0 ) return need;
    int &ret = t[u][need];
    if( ret != -1 ) return ret;
    int a = 1 , b = 0;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int vec = adj[u][i];
        a += f( vec , 0 );
        b += f( vec , 1 );
    }
    if( need ) ret = a;
    else ret = min( a , b );
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    while( cin >> n ){
        for(int i = 0 ; i < n ; i++) adj[i].clear();
        me( pa , -1 );
        for(int i = 0 ; i < n ; i++){
            int actual , r , vec;
            char x , y , z;
            cin >> actual >> x >> y >> r >> z;
            for(int j = 0 ; j < r ; j++){
                cin >> vec;
                adj[actual].pb(vec);
                pa[vec] = actual;
            }
        }
        int raiz = 0;
        while( pa[raiz] != -1 ) raiz = pa[raiz];
        me( t , -1 );
        int a = 1 , b = 0;
        for(int i = 0 ; i < adj[raiz].size() ; i++){
            a += f( adj[raiz][i] , 0 );
            b += f( adj[raiz][i] , 1 );
        }
        cout << min( a , b ) << '\n';
    }
}