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
#define MOD 100000
#define ios ios::sync_with_stdio(0);
#define N 104

int n , m , node , next[N][4], term[N] , T[N];
string dna = "ACGT";

int get(char x){
    for(int i = 0 ; i < 4 ; i++)
        if( dna[i] == x ) return i;
}

void add(char *s){
    int cur = 0 , len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        if( next[cur][get(s[i])] == 0 ) next[cur][get(s[i])] = node++;
        cur = next[cur][get(s[i])];
    }
    term[cur] = 1;
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < 4 ; i++){
        int v = next[0][i];
        if( v ) Q.push(v) , T[v] = 0;
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < 4 ; i++){
            int v = next[u][i] , x = next[T[u]][i];
            if( v == 0 ) next[u][i] = x;
            else Q.push(v) , T[v] = x , term[v] |= term[x];
        }
    }
}

ll a[N][N] , b[N][N] , r;

void mul(ll x[N][N],ll y[N][N]){
    ll c[N][N];
    me(c,0);
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < r ; j++)
            for(int k = 0 ; k < r ; k++)
                c[i][j] = (c[i][j] + x[i][k] * y[k][j])%MOD;
    
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < r ; j++)
            x[i][j] = c[i][j];
}

void fast(int e){
    r = node;
    me(b,0);
    for(int i = 0 ; i < r ; i++)
        b[i][i] = 1;
    while( e ){
        if( e&1 ) mul( b , a );
        mul( a , a );
        e >>= 1;
    }
}

int main(){
    while( scanf("%d%d",&n,&m) == 2 ){
        char s[12];
        me(next,0);
        me(term,0);
        me(T,0);
        node = 1;
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s);
            add(s);
        }
        aho();
        me(a,0);
        for(int i = 0 ; i < node ; i++){
            if( term[i] ) continue;
            for(int j = 0 ; j < 4 ; j++){
                int go = next[i][j];
                if( term[go] ) continue;
                a[i][go]++;
            }
        }
        fast( m );
        int ans = 0;
        for(int i = 0 ; i < r ; i++)
            ans = (ans + b[0][i])%MOD;
        ans %= MOD;
        printf("%d\n",ans);
    }
    return 0;
}
