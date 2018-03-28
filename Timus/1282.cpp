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

int n , A[N] , t[N][2];
vi adj[N];

int f(int u,int player){
    if( adj[u].size() == 0 ){
        //cout << u << " - " << A[u] << endl;
        if( A[u] == 0 ) return A[u];
        if( player == 0 ){
            if( A[u] == 1 ) return 1;
            return -1;
        }
        else{
            if( A[u] == -1 ) return 1;
            return -1;
        }
    }
    int &ret = t[u][player];
    if( ret != -2 ) return ret;
    bool win = 0 , draw = 0;
    for(int i = 0 ; i < adj[u].size() ; i++){
        int v = adj[u][i];
        //cout << v << " " << (player^1) << " " << f(v,player^1) << endl;
        if( f(v,player^1) == -1 ) win = 1;
        else if( f(v, player^1) == 0 ) draw = 1;
    }
    if( win ) ret = 1;
    else if( draw ) ret = 0;
    else ret = -1;
    return ret;
}

int main(){
    while( cin >> n ){
        for(int i = 0 ; i < n + 2 ; i++)
            adj[i].clear();
        char c;
        string s;
        int anc;
        for(int i = 2 ; i <= n ; i++){
            cin >> c >> anc;
            adj[anc].pb(i);
            if( c == 'L' ){
                cin >> s;
                if( s[0] == '-' ) A[i] = -1;
                else if( s[0] == '+' ) A[i] = 1;
                else A[i] = 0;
            }
        }
        for(int i = 0 ; i <= n + 2 ; i++)
            t[i][0] = t[i][1] = -2;
        int ans = f( 1 , 0 );
        if( ans == 0 ) printf("0\n");
        else if( ans > 0 ) printf("+1\n");
        else printf("-1\n");
    }
    return 0;
}
