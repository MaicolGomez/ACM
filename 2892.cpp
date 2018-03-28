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
#define N 30


bool c[N][N];
int I[N];

int main(){
    int tc;
    sc(tc);
    while(tc--){
        int n  , m , a , b;
        me(c,0);
        me(I,0);
        sc(n),sc(m);
        for(int i = 0 ; i < m ; i++)
            sc(a),sc(b), c[--a][--b] = 1 , I[b]++;
        
        queue<int> Q;
        for(int i = 0 ; i < n ; i++)
            if( I[i] == 0 ) Q.push( i );
        
        bool vis[N];
        bool ok = 1;
        while( !Q.empty() and ok ){
            //if( Q.size() > 1 ) ok = 0;
            int u = Q.front(); Q.pop();
            //cout << u << "\n";
            for(int i = 0 ; i < n ; i++){
                if( c[u][i] ){
                    if( I[i] < 1 ) ok = 0;
                    I[i]--;
                    if( I[i] == 0 ) Q.push( i );
                }
            }
        }
        for(int i = 0 ; i < n ; i++)
            if( I[i] ) ok = 0;
        cout << ok << "\n";
    }
    return 0;
}
