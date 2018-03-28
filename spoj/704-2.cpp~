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
#define N 1005
#define M 10002
#define ALF 128

int next[N][ALF] , node , T[N] , term[N] , t[M][N];
char text[M] , s[N];

void add(){
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
int n;

int f(int x,int nodo){
    if( term[node] ) return inf;
    if( x == n )
        return 0;
    int &ret = t[x][nodo];
    if( ret != -1 ) return ret;
    ret = 1 + f( x + 1 , nodo );
    ret = min( ret , f( x + 1 , next[nodo][text[x]] ) );
    return ret;
}

int main(){
    while( scanf("%s %s",text,s) == 2 ){
        n = strlen(text);
        int l = strlen(s);
        node = 1;
        me( next , 0 );
        add();
        aho();
        for(int i = 0 ; i <= node ; i++){
            t[n][i] = 0;
            if( term[i] ) t[n][i] = inf;
        }
        
        for(int x = n - 1 ; x >= 0 ; x--){
            for(int nodo = 0 ; nodo <= node ; nodo++){
                if( term[nodo] ){
                    t[x][nodo] = inf;
                    continue;
                }
                t[x][nodo] = 1 + t[x+1][nodo];
                t[x][nodo] = min( t[x][nodo] , t[x+1][next[nodo][text[x]]] );
            }
        }
        int ans = t[0][0];
        printf("%d\n",ans);
    }
    return 0;
}

