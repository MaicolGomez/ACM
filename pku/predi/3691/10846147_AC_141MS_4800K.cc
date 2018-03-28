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
#define inf (1<<30)
#define eps 1e-8
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
#define N 1005

int next[N][4] , term[N] , node , T[N] , t[N][N];
map<char , int> g;

void add(string s){
    int u = 0;
    for(int i =0 ; i < s.size() ; i++){
        if( next[u][ g[s[i]] ] == 0 ) term[node] = 0 , next[u][ g[s[i]] ] = node++;
        u = next[u][ g[s[i]] ];
    }
    term[u] = 1;
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < 4 ; i++)
        if( next[0][i] ) T[ next[0][i] ] = 0 , Q.push( next[0][i] );
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
		for(int i = 0 ; i < 4 ; i++){
			int v = next[u][ i ], x = next[ T[u] ][ i ];
			if ( v == 0 ) next[u][ i ] = x;
			else Q.push(v) , T[v] = x, term[v] |= term[x];
		}
    }
}

string a;

int f(int x,int u){
    if( term[u] ) return inf;
    if( x == a.size() ) return 0;
    int &ret = t[x][u];
    if( ret != -1 ) return ret;
    ret = f( x + 1 , next[u][ g[ a[x] ] ] );
    for(int i = 0 ; i < 4 ; i++)if( i != g[a[x]] )
        ret = min( ret , 1 + f( x + 1 , next[u][i] ) );
    return ret;
}
int dp[N][N];
int main(){
    ios::sync_with_stdio(0);
    g['A'] = 0 , g['C'] = 1 , g['T'] = 2 , g['G'] = 3;
    int n , test = 0;
    string s;
    while( cin >> n , n ){
        me( next , 0 );
        node = 1;
        string s;
        for(int i = 0 ; i < n ; i++){
            cin >> s;
            add(s);
        }
        aho();
        cin >> a;
        me( t , -1 );
		int r = f(0,0);
        cout <<"Case " << ++test << ": ";
        if( r == inf ) cout << -1 << '\n';
        else cout << r << '\n';
    }
}