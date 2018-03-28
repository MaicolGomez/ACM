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
#define N 505

struct nodo{
    long long w , t , id;
    nodo(){}
};

bool operator<(nodo A,nodo B){
    return A.t * B.w < A.w * B.t;
}

long long n , k[N] , T[N];
nodo A[N][101];

int main(){
    freopen( "student.in" , "r" , stdin );
    freopen( "student.out" , "w" , stdout );
    while( cin >> n ){
        for(int i = 0 ; i < n ; i++)
            cin >> k[i];
        
        int id = 1;
        for(int i = 0 ; i < n ; i++){
            int t = 0;
            for(int j = 0 ; j < k[i] ; j++)
                cin >> A[i][j].t , A[i][j].id = id++;
            T[i] = t;
        }
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < k[i] ; j++)
                cin >> A[i][j].w;
        
        nodo v[n];
        ll S = 0;
        for(int i = 0 ; i < n ; i++){
            sort( A[i] , A[i] + k[i] );
            ll w = 0 , t = 0;
            for(int j = 0 ; j < k[i] ; j++){
                t += A[i][j].t;
                w += A[i][j].w;
            }
            v[i].t = t , v[i].w = w , v[i].id = i;
        }
        sort( v , v + n);
        
        ll t = 0;
        for(int r = 0 ; r < n ; r++){
            int i = v[r].id;
            for(int j = 0 ; j < k[i] ; j++){
                t += A[i][j].t;
                S += t * A[i][j].w;
            }
        }
        
        cout << S << endl;
        
        for(int r = 0 ; r < n ; r++)
            for(int j = 0 , i = v[r].id ; j < k[i] ; j++){
                if( r == 0 && j > 0 || r ) cout << ' ';
                cout << A[i][j].id ;
            }
        cout << '\n';
    }
    return 0;
}
