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
#define fi first
#define se second
#define MOD 20090717
#define N 601*25

int next[N][27] , node , T[N] , term[N] , t[302][N];
int n , m , k;
char s[302];

void add(char *ss){
    int ac = 0;
    int len = strlen(ss);
    for(int i = 0 ; i < len ; i++){
        int v = next[ac][ss[i]-'a'];
        if( v == 0 ) term[node] = 0 , next[ac][ss[i]-'a'] = node++;
        ac = next[ac][ss[i]-'a'];
    }
    term[ac] = 1;
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < 26 ; i++){
        int v = next[0][i];
        if( v ) T[v] = 0 , Q.push( v );
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < 26 ; i++){
            int v = next[u][i] , x = next[T[u]][i];
            if( v == 0 ) next[u][i] = x;
            else Q.push( v ) , T[v] = x , term[v] |= term[x];
        }
    }
}

int f(int x,int nodo){
    //cout << x << " " << node << endl;
    if( x == n ){
        if( term[nodo] || nodo == 0 ) return 0;
        return inf;
    }
    int &ret = t[x][nodo];
    if( ret != -1 ) return ret;
    ret = 1 + f( x + 1 , nodo );
    int sig = next[nodo][ s[x] - 'a' ];
    if( term[sig] )
        ret = min( ret , f( x + 1 , 0 ) );
        
    
    if( sig != 0 )
        ret = min( ret , f( x + 1 , sig ) );
    
    return ret;
}

int main(){
    char text[30];
    while( scanf("%d%d",&k,&n) == 2 ){
        scanf("%s",s);
        node = 1;
        me( next , 0 );
        me( term , 0);
        for(int i = 0 ; i < k ; i++){
            scanf("%s",text);
            add( text );
        }
        //aho();
        //for(int i = 0 ; i < n ; i++)
            //memset( t[i] , -1 , sizeof( int ) * (node + 2) );
        me(t,-1);
        int ans = f( 0 , 0 );
        printf("%d\n",ans);
    }
    return 0;
}
