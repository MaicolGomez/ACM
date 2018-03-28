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

struct nodo{
    int n , d , f , s;
    nodo(){}
    nodo(int N,int D,int F,int S){
        n = N , d = D , f = F , s = S;
    }
};

bool operator<(nodo A,nodo B){
    if( A.n * B.d != A.d * B.n ) return A.n * B.d < A.d * B.n;
    else if( A.f != B.f ) return A.f < B.f;
    else return A.s < B.s;
}

int main(){
    int a[3] , b[7];
    for(int i = 0 ; i < 3 ; i++)
        cin >> a[i];
    for(int i = 0 ; i < 7 ; i++)
        cin >> b[i];
    
    vector<nodo> v;
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 7 ; j++)
            v.pb( nodo( a[i] , b[j] , i + 1 , j + 1 ) );
    
    sort( all(v) );
    for(int i = 0 ; i < 21 ; i++)
        printf("%.2lf %d %d\n" , (1.0 * v[i].n ) / ( 1.0 * v[i].d ), v[i].f , v[i].s );
    
    return 0;
}
