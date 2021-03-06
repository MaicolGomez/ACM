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
#define N 10005
#define G 2
char s[N];
int n , x , t[N][3] ;
vi adj[N];

void build(){
    if( x == strlen(s) ) return;
    int nodo = (n==0)?n++:(n-1);
    if( s[x] == '0' ){
        x++;
        return;
    }
    if( s[x] == '1' ){
        x++;
        int u = n++;
        adj[nodo].pb(u);
        build();
    }
    else if( s[x] == '2' ){
        x++;
        int u = n++;
        build();
        int v = n++;
        build();
        adj[nodo].pb(u) , adj[nodo].pb(v);
    }
}

int f(int u,int last){
    if( adj[u].size() == 0 )
        return 0;
    int &ret = t[u][last];
    if( ret != -1 ) return ret;
    ret = 0;
    int v = adj[u][0];
    if( adj[u].size() == 1 )
        ret = max( (last==1) + f( v , (last+1)%3 ) , (last == 0) + f( v , (last +2)%3 )  );
    else{
        int r = adj[u][1];
        ret = max( (last!=2) + f( v , (last+1)%3 ) + f( r , (last+2)%3 ) , (last!=2) + f( v , (last+2)%3 ) + f( r , (last+1)%3 ) );
    }
    return ret;
}

int g(int u,int last){
    if( adj[u].size() == 0 )
        return 0;
    int &ret = t[u][last];
    if( ret != -1 ) return ret;
    ret = 0;
    int v = adj[u][0];
    if( adj[u].size() == 1 )
        ret = min( (last==1) + g( v , (last+1)%3 ) , (last == 0) + g( v , (last +2)%3 )  );
    else{
        int r = adj[u][1];
        ret = min( (last!=2) + g( v , (last+1)%3 ) + g( r , (last+2)%3 ) , (last!=2) + g( v , (last+2)%3 ) + g( r , (last+1)%3 ) );
    }
    return ret;
}

int main(){
    int tc;
    sc(tc);  gets(s);
    while( tc-- ){
        gets(s);
        for(int i = 0 ; i < strlen(s) ; i++)
            adj[i].clear();
        n = 0 , x = 0;
        build();
        me(t,-1);
        int ans1 = max( f( 0 , 0 ) , max( f( 0 , 1 ) , 1 + f( 0 , 2 ) ) );
        me(t,-1);
        int ans2 = min( g( 0 , 0 ) , max( g( 0 , 1 ) , 1 + g( 0 , 2 ) ) );
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
