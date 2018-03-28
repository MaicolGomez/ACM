#include<bits/stdc++.h>
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
#define ios ios::sync_with_stdio(0)
#define N 100000
int MOD;

vi v;
set<int> S;

void back(ll x,int n,int sz){
    S.insert( (int)x );
    if( sz < v.size() and n >= v[sz] ){
        back( x , n ,  sz + 1 );
        back( (x * v[sz])%MOD , n - v[sz] , sz);
    }
}

int main(){
    for(int i = 2 ; i <= 70 ; i++){
        bool ok = 1;
        for(int j = 2 ; j < i - 1 ; j++)
            if( i % j == 0 ) ok = 0;
        
        if( ok ) v.pb( i );
    }
    
    int tc;
    sc(tc);
    while( tc-- ){
        int n;
        scanf("%d%d",&n,&MOD);
        S.clear();
        back( 1 , n ,  0 );
        printf("%d\n",(int)S.size());
    }
    return 0;
}
