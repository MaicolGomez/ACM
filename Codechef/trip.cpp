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
#define N 5005

int fa[N] , so[N];
int cost[N];
string P[N];
char s[3][55];

int g(char *c){
    int len = strlen(c);
    len--;
    int ans = 0;
    for(int i = 0 ; i < len ; i++)
        ans = ans * 10 + (c[i] - '0');
    return ans;
}

void solve(){
    int n , ct = 0;
    me(fa,-1);
    me(so,-1);
    sc(n);
    map<string,int> m;
    int ans = 0;
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < 3 ; j++) scanf("%s",s[j]);
        if( m.find( s[0] ) == m.end() ) m[ s[0] ] = ct++;
        if( m.find( s[1] ) == m.end() ) m[ s[1] ] = ct++;
        P[ m[ s[0] ] ] = s[0];
        P[ m[ s[1] ] ] = s[1];
        int x = g( s[2] );
        ans += x;
        cost[ m[ s[0] ] ] = x;
        so[ m[ s[0] ] ] = m[ s[1] ];
        fa[ m[ s[1] ] ] = m[ s[0] ];
    }
    int ac = 0;
    for(int i = 0 ; i < ct ; i++) if( fa[i] == -1 ) ac = i;
    while( so[ ac ] != -1 ){
        printf("%s %s %d$\n", P[ac].c_str() , P[ so[ac] ].c_str() , cost[ac] );
        ac = so[ac];
    }
    printf("%d$\n",ans);
}

int main(){
    int tc;
    sc(tc);
    for(int i = 0 ; i < tc ; i++) solve();
    return 0;
}
