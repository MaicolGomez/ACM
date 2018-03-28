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
#define MOD 20090717
#define N 101*15
#define M 82
#define ALF 128

int next[N][ALF] , node , T[N] , term[N] , t[M][N];

int n , m;
char text[M];

void add(int x,char *s){
    int ac = 0;
    int len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        int v = next[ac][s[i]];
        if( v == 0 ) term[node] = 0 , next[ac][s[i]] = node++;
        ac = next[ac][s[i]];
    }
    term[ac] = 1;
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < ALF ; i++){
        int v = next[0][i];
        if( v ) T[v] = 0 , Q.push( v );
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < ALF ; i++){
            int v = next[u][i] , x = next[T[u]][i];
            if( v == 0 ) next[u][i] = x;
            else Q.push( v ) , T[v] = x , term[v] |= term[x];
        }
    }
}

int f(int x,int node){
    if( term[node] ) return inf;
    if( x == strlen(text) )
        return 0;
    int &ret = t[x][node];
    if( ret != -1 ) return ret;
    ret = inf;
    ret = f( x + 1 , next[node][text[x]] );
    for(int i = 0 ; i < 1 ; i++){
        int v = next[node][i];
        ret =  min( ret ,  (i!=text[x]) + f( x + 1 , v ) );
    }
    return ret;
}

int main(){
    char s[18];
    while( scanf("%d%d",&n,&m) == 2 ){
        if( n == 0 && m == 0 ) break;
        gets(s);
        node = 1;
        me( next , 0 );
        for(int i = 0 ; i < n ; i++){
            gets(s);
            add( i , s );
        }
        aho();
        int ans = 0;
        for(int i = 0 ; i < m ; i++){
            gets(text);
            for(int j = 0 ; j < strlen(text) ; j++)
                memset( t[j] , -1 , sizeof(int)*(node+2) );
            ans += f( 0 , 0 );
        }
        printf("%d\n",ans);
    }
    return 0;
}
