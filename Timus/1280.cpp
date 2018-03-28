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

vi adj[N];
bool vis[N];
int in[N];

int main(){
    int n , m;
    sc(n) , sc(m);
    int x , y;
    for(int i = 0 ; i < m ; i++){
        sc(x),sc(y);
        adj[x].pb(y);
        in[ y ]++;
        vis[x] = vis[y] = 1;
    }
        
    int a[N];
    for(int i = 0 ; i < n ; i++)
        sc(a[i]);
    
    bool ans = 1;
    for(int i = 0 ; i < n ; i ++){
        if( in[ a[i] ] > 0 ){
            printf("NO\n");
            ans = 0;
            break;
        }
        for(int j = 0 ; j < adj[ a[i] ].size() ; j++)
            in[ adj[a[i]][j] ]--;
    }
    if( ans ) printf("YES\n");
    
    return 0;
}


