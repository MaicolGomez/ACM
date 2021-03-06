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
#define MOD 10007
#define N 100002

ll SC[N] , S[N];

struct tree{
    int flag , p , q , r;
    ll s;
    tree(){}
};

tree T[4*N];

void init(int node,int x,int y){
    T[node].flag = 0;
    if( x == y ){
        T[node].s = 0;
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    T[node].s = (T[v1].s + T[v2].s)%MOD;
}


inline void push(int node,int x,int y){
    if( T[node].flag ){
        T[node].s += ( ((SC[y] - SC[x-1]+MOD)%MOD*T[node].p) + ((S[y] - S[x-1]+MOD)%MOD*T[node].q) + (y-x+1) * T[node].r );
        if( T[node].s >= MOD ) T[node].s %= MOD;
        //cout << node << ": " << x << " * " << y << " Coef: " << T[node].p << " * " << T[node].q << " * " << T[node].r << endl;
        //cout << "SUMATORIAS: " << (SC[y] - SC[x-1]) << " * " << (S[y] - S[x-1]) << " * " << (y-x+1) << endl;
        if( x != y ){
            T[L(node)].flag = T[R(node)].flag = 1;
            T[L(node)].p += T[node].p; //T[L(node)].p %= MOD;
            T[R(node)].p += T[node].p; //T[R(node)].p %= MOD;
            T[L(node)].q += T[node].q; //T[L(node)].q %= MOD;
            T[R(node)].q += T[node].q; //T[R(node)].q %= MOD;
            T[L(node)].r += T[node].r; //T[L(node)].r %= MOD;
            T[R(node)].r += T[node].r; //T[R(node)].r %= MOD;
        }
        //cout << node << ": " << x << " * " << y << " Suma: " << T[node].s <<  endl;
    }
    T[node].flag = 0;
    T[node].p = T[node].q = T[node].r = 0;
}

void update(int node,int x,int y,int a,int b,ll p,ll q,ll r){
    push( node , x , y );
    if( y < a || b < x ) return;
    if( a <= x && y <= b ){
        T[node].flag = 1;
        T[node].p = p , T[node].q = q , T[node].r = r;
        //cout << node << " " << p << " " << q << " " << r << endl;
        push( node , x , y );
        //cout << (SC(y) - SC(x-1)) * T[node].p << " " << (S(y) - S(x-1)) * T[node].q << " " << T[node].r * (y-x+1) << endl;
        //cout << T[node].s << endl;
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    update( v1 , x , mid , a , b , p , q , r );
    update( v2 , mid + 1 , y , a , b , p , q , r );
    T[node].s = (T[v1].s + T[v2].s)%MOD;
}

int query(int node,int x,int y,int a,int b){
    push( node , x , y );
    if( y < a || b < x ) return 0;
    if( a <= x && y <= b )
        return T[node].s;
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    return ( query( v1 , x , mid , a , b ) + query( v2 , mid + 1 , y , a , b ) )%MOD;
}


int main(){
    int n , m , op , x , y , a , b , c;
    S[0] = SC[0] = 0;
    while( scanf("%d%d",&n,&m) == 2 ){
        for(ll i = 1 ; i <= n ; i++){
            S[i] = (S[i-1] + i)%MOD;
            SC[i] = (SC[i-1] + i * i)%MOD;
        }
        init( 0 , 0 , n - 1);
        while( m-- ){
            sc(op);
            if( !op ){
                scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
                update( 0 , 0 , n - 1 , x , y , a , b , c );
            }
            else{
                scanf("%d%d",&x,&y);
                printf("%d\n",query(0,0,n-1,x,y));
            }
        }
        break;
    }
    return 0;
}

