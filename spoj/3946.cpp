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
#define N 100005

vi T[3*N];
int A[N];

void init(int node ,int x,int y){
    if( x == y ){
        T[node].pb( A[x] );
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    init( v1 , x , mid );
    init( v2 , mid + 1 , y );
    int a = 0 , b = 0;
    while( a < T[v1].size() && b < T[v2].size() ){
        if( T[v1][a] < T[v2][b] )
            T[node].pb( T[v1][a++] );
        else T[node].pb( T[v2][b++] );
    }
    while( a < T[v1].size() )
        T[node].pb( T[v1][a++] );
    while( b < T[v2].size() )
        T[node].pb( T[v2][b++] );
}

void query(int node,int x,int y,int a,int b,vi &v){
    if( y < a || b < x ) return;
    if( a <= x && y <= b ){
        v.pb(node);
        return;
    }
    int mid = M(x,y) , v1 = L(node) , v2 = R(node);
    query( v1 , x , mid , a , b , v );
    query( v2 , mid + 1 , y , a , b , v );
}

int f(int lo , int hi, int x, vi &v){
    if( v[lo] > x ) return 0;
    if( v[hi] <= x ) return v.size();
    while( hi - lo > 1 ){
        int mid = M(lo,hi);
        if( v[mid] > x ) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main(){
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        for(int i = 0 ; i < n ; i++)
            sc(A[i]);
        
        init(0 , 0 , n - 1);
        int x , y , z;
        while(m--){
            sc(x),sc(y),sc(z); x--,y--;
            vi v;
            query( 0 , 0 , n - 1 , x , y , v );
            if( z == 1 ){   
                int ans = inf;
                for(int i = 0 ; i < v.size() ; i++)
                    ans = min( ans , T[v[i]][0] );
                printf("%d\n",ans);
            }
            else{
                /*for(int i = 0 ; i < v.size() ; i++){
                    cout << v[i] << ": \n";
                    for(int j = 0 ; j < T[v[i]].size() ; j++)
                        cout << T[v[i]][j] << " - ";
                    cout << endl;    
                }*/
                int lo = T[0][0] , hi = T[0][ T[0].size() - 1 ];
                while( hi - lo > 1 ){
                    int mid = M(lo,hi);
                    int S = 0;
                    for(int i = 0 ; i < v.size() ; i++){
                        int g = f( 0 , T[v[i]].size() - 1 , mid , T[v[i]] );
                        //cout << v[i] << ": " << mid << " --> " << g << endl;
                        S += g;
                    }
                    if( S >= z ) hi = mid;
                    else lo = mid;
                    //cout << lo << " --- " << hi << endl;
                }
                printf("%d\n",hi);
            }
        }
    }
    return 0;
}
