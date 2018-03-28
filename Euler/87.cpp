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
#define N 50000000

bool prime[N + 5];

int main(){
    
    me(prime,1);
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i * i <= N ; i++)
        if( prime[i] )
            for(int j = i * i ; j <= N ; j += i )
                prime[j] = 0;
    
    vi v;
    for(int i = 1 ; i < 1000000 ; i++)
        if( prime[i] ) v.pb( i );
    
    vector<ll> a , b , c;
    for(int i = 0 ; v[i] * v[i] <= N ; i++){
        a.pb( v[i] * v[i] );
    }
    for(int i = 0 ; v[i] * v[i] * v[i] <= N ; i++)
        b.pb( v[i] * v[i] * v[i] );
        
    for(int i = 0 ; v[i] * v[i] * v[i] * v[i] <= N ; i++)
        c.pb( v[i] * v[i] * v[i] * v[i] );
    
    set<int> S;
    for(int i = 0 ; i < a.size() ; i++)
        for(int j = 0 ; j < b.size() ; j++)
            for(int k = 0 ; k < c.size() ; k++)if( a[i] + b[j] + c[k] <= N ){
                //if( a[i] + b[j] + c[k] == 24 ) cout << a[i] << " " << b[j] << " " << c[k] << endl;
                S.insert( a[i] + b[j] + c[k] );
            }
    cout << S.size() << " " << *S.begin() << " " << *S.begin() + 1 << "\n";
    
    return 0;
}
