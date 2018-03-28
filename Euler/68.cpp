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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)
#define N 100000

struct nodo{
    int a;
    ll s;
    nodo(){};
    nodo(int A,ll S){
        a = A , s = S;
    }
};

bool operator<(nodo A,nodo B){ return A.a < B.a; }

int pot[10] = { 1 , 10 , 100 , 10000 , 100000 , 1000000 , 10000000 , 100000000 };

int C(ll x){
    if( !x ) return 0;
    return 1 + C( x / 10 );
}

ll get(vector<nodo> A){
    sort( all(A) );
    ll ans = 0;
    for(int i = 0 ; i < A.size() ; i++){
        ans = ans * pot[ C( A[i].s ) ] + A[i].s;
    }
    return ans;
}

int main(){
    vi v;
    for(int i = 1 ; i < 11 ; i++)
        v.pb( i );
    
    ll ans = 0;
    do{
        vector<bool> vis( 11 , 0 );
        for(int i = 0 ; i < 5 ; i++)
            vis[ v[i] ] = 1;
        
        vector<nodo> A;
        for(int i = 0 ; i < 5 ; i++){
            int x = v[i] + v[(i+1)%5];
            int k = 16 - x;
            ll t = 0;
            if( 1 <= k and k <= 10 and !vis[k] ){
                vis[k] = 1;
                if( k >= 10 ) t = t * 100 + k;
                else t = t * 10 + k;
                if( v[i] >= 10 ) t = t * 100 + v[i];
                else t = t * 10 + v[i];
                if( v[(i+1)%5] >= 10 ) t = t * 100 + v[(i+1)%5];
                else t = t * 10 + v[(i+1)%5];
                A.pb( nodo( k , t ) );
            }
            else break; 
            
        }
        ans = max( ans , get(A) );
    }while( next_permutation( all(v) ) );
    cout << ans << endl;
    return 0;
}
