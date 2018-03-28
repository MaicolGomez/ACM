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
#define ios ios::sync_with_stdio(0);
#define N 105

int t[N] , t1[N];

int A[10] = { 6 , 2 , 5 , 5 , 4 , 5 , 6 , 3 , 7 , 6 };

int f(int n){
    if( n == 0 ) return 0;
    int &ret = t[n];
    if( ret != -1 ) return ret;
    ret = 100;
    for(int i = 0 ; i < 10 ; i++)if( n - A[i] >= 0 )
        ret = min( ret , 1 + f( n - A[i] ) );
    return ret;
}

int g(int n){
    if( n == 0 ) return 0;
    int &ret = t1[n];
    if( ret != -1 ) return ret;
    ret = -1000;
    for(int i = 0 ; i < 10 ; i++)if( n - A[i] >= 0 )
        ret = max( ret , 1 + g( n - A[i] ) );
    return ret;
}

string solve(int n){
    string a;
    int d = -1000 , c;
    for(int i = 9 ; i >= 1 ; i--)if( n - A[i] >= 0 ){
        int r = g( n - A[i] );
        if( r > d ){
            d = r;
            a = string( 1 , i + '0' );
            c = i;
        }
    }
    n -= A[c];
    while( n ){
        for(int i = 9 ; i >= 0 ; i--)if( n >= A[i] ){
            if( g( n - A[i] ) == d - 1 ){
                a += string( 1 , i + '0' );
                d--;
                n -= A[i];
                break;
            }
        }
    }
    return a;
}

int main(){
    int tc;
    sc(tc);
    me(t,-1);
    me(t1,-1);
    while( tc-- ){
        int n;
        sc(n);
        string a = "";
        string b = solve( n );
        int d = 100 , c;
        for(int i = 1 ; i < 10 ; i++)if( n - A[i] >= 0 ){
            int r = f( n - A[i] );
            if( r < d ){
                d = r;
                a = string( 1 , i + '0' );
                c = i;
            }
        }
        n -= A[c];
        while( n ){
            for(int i = 0 ; i < 10 ; i++)if( n >= A[i] ){
                if( f( n - A[i] ) == d - 1 ){
                    a += string( 1 , i + '0' );
                    d--;
                    n -= A[i];
                    break;
                }
            }
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}
