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
#define N 50

vi adj[N];
int in[N] , n , maxi;
vi G;
bool vis[N] , used[N];
map<char , int> M;
map<int , char> I;
vector<string> ans;
vector<int> P[N];

void clean(int n){
    me(in,0);
    me(vis,0);
    me(used,0);
    G.clear();
    M.clear();
    I.clear();
    ans.clear();
    for(int i = 0 ; i < n ; i++)
        adj[i].clear() , P[i].clear();
}

void back( int x , int y , string s , bool f , vi v ){
    if( s.size() == n ){
        ans.pb( s );
        return;
    }
    if( f == 0 ){
        for(int i = 0 ; i < G.size() ; i++)if( !used[i] ){
            used[i] = 1;
            back( x , y , s + I[ G[i] ] , 0 , v );
            back( x , y , s + I[ G[i] ] , 1 , v );
            used[i] = 0;
        }
    }
    else if( x <= maxi ){
        if( y + 1 < v.size() ){
            back( x , y + 1 , s + I[ P[x][y] ] , 1 , v );
            back( x , y + 1 , s + I[ P[x][y] ] , 0 , v );
        }
        else{
            do{
                back( x + 1 , 0 , s + I[ P[x][y] ] , 1 , P[x+1] );
                back( x + 1 , 0 , s + I[ P[x][y] ] , 0 , P[x+1] );
            }while( next_permutation( all(P[x+1]) ) );
        }
    }
}

int main(){
    string s;
    int test = 0;
    while( getline( cin , s ) ){
        if( test++ ) cout << "\n";
        
        n = 0;
        clean( 21 );
        char x , y;
        stringstream in1(s);
        while( in1 >> x ){
            M[x] = n;
            I[n++] = x;
        }
        getline( cin , s );
        stringstream in2(s);
        while( in2 >> x >> y ){
            int u = M[x] , v = M[y];
            adj[ u ].pb( v );
            in[ v ]++;
            vis[v] = vis[u] = 1;
        }
        
        priority_queue< int > Q;
        vi d( n , -1 );
        for(int i = 0 ; i < n ; i++){
            if( in[i] == 0 && vis[i] )
                Q.push( -i ) , P[0].pb(i) , d[i] = 0;
            if( !vis[i] )
                G.pb( i );
        }
        maxi = 0;
        while( !Q.empty() ){
            int u = Q.top(); Q.pop();
            u = -u;
            for(int i = 0 ; i < adj[u].size() ; i++){
                int v = adj[u][i];
                in[v]--;
                if( in[v] == 0 ){
                    d[v] = d[u] + 1;
                    P[ d[v] ].pb( v );
                    maxi = max( maxi , d[v] );
                    Q.push( -v );
                }
            }
        }
        
        for(int i = 0 ; i <= maxi ; i++)
            sort( all(P[i]) );
            
        do{
            back( 0 , 0 , "" , 1 , P[0] );
            back( 0 , 0 , "" , 0 , P[0] );
        }while( next_permutation( all(P[0]) ) );
        
        sort( all(ans) );
        ans.resize( unique(all(ans)) - ans.begin() );
        for(int i = 0 ; i < ans.size() ; i++)
            cout << ans[i] << endl;
    }
    return 0;
}
