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
#define MOD 10009
#define N 50002

string S[N];
int n;
long long pot[41];
long long t[N][41];

int get(int r,int x){
    int ans = 0;
    int p = min( S[r].size() , S[x].size() );
    for(int i = 0 ; i < p ; i++){
        if( S[r][i] == S[x][i] ) ans ++;
        else return ans;
    }
    return ans;
}

int H[N] , C[N][41];

ll f(int x,int l){
    if(x == n)
        return pot[40 - l];
    ll ret = t[x][l];
    if( ret != -1 ) return ret;
    ret = (1LL<<60);
    ret = pot[40-l] + f( x + 1 , S[x].size() ); C[x][l] = 100;
    if( H[x] ){
        if( f( x + 1 , min( l , H[x]) ) < ret )
            ret = f(x+1,min(l,H[x])) , C[x][l] = min(l,H[x]);
    }
    
    return t[x][l] = ret;
}

pii A[N];
int tam;

void rec(int x,int l){
    if( x == n ){
        A[tam++] = mp( x - 1 , l );
        return;
    }
    if( C[x][l] == 100 ){
        A[tam++] = mp( x - 1 , l );
        rec( x + 1 , S[x].size() );
    }
    else rec( x + 1 , C[x][l] );
}


int main(){
    freopen( "compression.in" , "r" , stdin );
    freopen( "compression.out" , "w" , stdout );
    char s[42];
    pot[0] = 1;
    for(int i = 1 ; i <= 40 ; i++)
        pot[i] = pot[i-1] * 2LL; 
    while( sc(n) == 1 ){
        gets(s);
        for(int i = 0 ; i < n ; i++){
            gets(s);
            S[i] = s;
        }
        if( n == 1 ){
            printf("%lld\n1\n", pot[40 - S[0].size()]);
            printf("%s\n",S[0].c_str());
        }
        else{
            sort( S , S + n );
            for(int i = 0 ; i < n-1 ; i++)
                H[i+1] = get( i , i + 1 );
            
            for(int i = 0 ; i < n ; i++)
                me(t[i],-1) , me(C[i],0);
            tam = 0;
            ll ans = f( 1 , S[0].size() );
            printf("%lld\n",ans);
            rec( 1 , S[0].size() );
            printf("%d\n",tam);
            for(int i = 0 ; i < tam ; i++)
                printf("%s\n", S[ A[i].fi ].substr( 0 , A[i].se ).c_str() );
            
        }
    }
    
    return 0;
}
