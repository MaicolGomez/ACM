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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 10009
#define N 10002

char s[N][12];
int node , next[N*10][128] , term[N*10];

void add(char *t){
    int ac = 0 , l = strlen(t);
    for(int i = 0 ; i < l ; i++){
        if( next[ac][ t[i] ] == 0 ) next[ac][t[i]] = ++node;
        ac = next[ac][t[i]];
    }
    term[ac] = 1;
}

bool find(int x){
    int l = strlen( s[x] ) , ac = 0;    
    for(int i = 0 ; i < l ; i++){
        if( term[ac] ) return 0;
        ac = next[ac][s[x][i]];
    }
    return 1;
}

int main(){
    int tc;
    sc(tc);
    while(tc--){
        int n;
        sc(n);
        node = 0;
        me(term,0);
        for(int i = 0 ; i < n*10 ; i++)
            me( next[i] , 0 );

        for(int i = 0 ; i < n ; i++){
            scanf("%s",s[i]);
            add( s[i] );
        }
        bool ok = 1;
        for(int i = 0 ; i < n && ok ; i++)
            ok = find( i );
        
        printf("%s\n",(ok?"YES":"NO"));
    }
    return 0;
}
