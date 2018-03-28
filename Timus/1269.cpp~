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
#define N 100005

int T[ N ];
int node , term[ N ];
vector< pair< int , char > > next[ N ];

int get(int ac,char x){
    for(int i = next[ac].size() - 1 ; i >= 0 ; i--)
        if( next[ac][i].se == x ) return next[ac][i].fi;
    return 0;
}

void add(char *s){
    int ac = 0;
    int l = strlen(s);
    for(int i = 0 ; i < l ; i++){
        int v = get( ac , s[i] );
        if( v == 0 ){
            next[ac].pb( mp( node , s[i] ) );
            ac = node++;
        }
        else ac = v;
    }
    term[ac] = l;
}

void aho(){
    queue<int> Q;
    for(int i = 0 ; i < next[0].size() ; i++){
        int v = next[0][i].fi;
        T[v] = 0 , Q.push( v );
    }
    while( !Q.empty() ){
        int u = Q.front(); Q.pop();
        for(int i = 0 ; i < next[u].size() ; i++){
            int v = next[u][i].fi , p = T[u];
            int x = get( T[u] , next[u][i].se );
            char c = next[u][i].se;
            while( p && get(p,c)==0){
                p = T[p];
            }
            p = get( p ,c);
            T[v] = p;
            Q.push(v);
            term[v] = max( term[v] , term[p]);
            
        }
    }
}

char s[N*10];

int main(){
    gets(s);
    int n , m;
    sscanf(s,"%d",&n);
    node = 1;
    for(int i = 0 ; i < n ; i++){
        gets(s);
        add(s);
    }
    gets(s);
    aho();
    sscanf( s , "%d" ,&m );
    //cout << next[0]['H'] << " " << term[0] << endl;
    int x = inf , y = inf;
    for(int row = 0 ; row < m ; row++){
        int  col = 0 , ac = 0;
        char c;
        while( (c = getchar())!=10 && (c!=3)){
            
            while(ac && get(ac,c) == 0){
                ac = T[ac];    
            }
            
            ac = get(ac,c);
            
            if( term[ac] != 0 ){
                int ny = col - term[ac] + 2;
                int nx = row + 1;
                if( nx < x or (nx == x and ny < y) )
                    x = nx , y = ny;
            }
            col++;
        }
    }
    if( x < inf )
        printf("%d %d\n", x , y);
    else puts("Passed");
    return 0;
}
