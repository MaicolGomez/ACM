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
#define ios ios::sync_with_stdio(0);
#define N 1001

vi adj[N];
int I[N];

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 and (n||m) ){
        for(int i = 0 ; i < n ; i++)
            adj[i].clear() , I[i] = 0;
        
        int a , b;
        for(int i = 0 ; i < m ; i++){
            scanf("%d%d",&a,&b); a--,b--;
            adj[a].pb(b); I[b]++;
        }
        
        queue<int> Q;
        for(int i = 0 ; i < n ; i++)
            if( I[i] == 0 ) Q.push( i );
        
        bool mul = 0 , cycle = 0;
        while( !Q.empty()  ){
            if( Q.size() > 1 ) mul = 1;
            int u = Q.front(); Q.pop();
            for(int i = 0 ; i < adj[u].size() ; i++){
                int v = adj[u][i];
                I[v]--;
                if( I[v] == 0 ) Q.push( v ); 
            }
        }
        for(int i = 0 ; i < n ; i++)
            if( I[i] ) cycle = 1;
        
        //cout << mul << " " << cycle << endl; 
        int ans = 1;
        if(cycle) ans = 0;
        else if( mul ) ans = 2;
        printf("%d\n",ans);
    }
    return 0;
}
