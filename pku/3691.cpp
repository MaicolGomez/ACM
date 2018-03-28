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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 1005

int next[N][4] , T[N] , term[N] , node;
string adn = "ACGT";

int get(char x){
    for(int i = 0 ; i < adn.size() ; i++)
        if( adn[i] == x ) return i;
}

void add(char *s){
    int ac = 0 , len = strlen(s);
    for(int i = 0 ; i < len ; i++){
        if( next[ac][get(s[i])] == 0 ) me(next[node],0), next[ac][get(s[i])] = node++;
        ac = next[ac][get(s[i])];
    }
    term[ac] = 1;
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < 4 ; i++){
        int v = next[0][i];
        if( v ) Q.push( v ) , T[v] = 0;
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

char s[N];
int t[N][N] , len;

int f(int x,int cur){
    if( term[cur] ) return inf;
    if( x == len ) return 0;
    int &ret = t[x][cur];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = 0 ; i < 4 ; i++)
        ret = min( ret ,  (s[x] != adn[i]) + f( x + 1 , next[cur][i] ) );
    return ret;
}

int main(){
    int n , test = 0;
    while( sc(n) == 1 and n ){
        
        node = 1;
        me(next[0],0);
        me(term,0);
        me(T,0);
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s);
            add(s);
        }
        aho();
        me(t,-1);
        scanf("%s",s);
        len = strlen(s);
        printf("Case %d: %d\n",++test,(f(0,0) == inf)?-1:f(0,0));
    }
    return 0;
}
