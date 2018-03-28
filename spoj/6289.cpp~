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
#define fi first
#define se second
#define MOD 10009
#define N 102

int t[N][N];

int f(int n,int m){
    if( n == 0 || m == 0 )
        return 0;
    int &ret = t[n][m];
    if( ret != -1 ) return ret;
    vector<bool> S(130 , 0);
    S[f( n - 1 , m - 1 )] = 1;
    
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            S[ f( i - 1 , j - 1 ) ^ f( i - 1 , m - j ) ^ f( n - i , j - 1 ) ^ f( n - i , m - j ) ] = 1;
        
    
    int x = 0;
    while( S[x] ) x++;
    return ret = x;
}

int x[7] = { 2 , 4 , 4 , 6 , 8 , 10 , 12 };
int y[7] = { 2 , 4 , 6 , 4 , 12 , 10 , 8 };
bool S[130];

int main(){
    t[0][0] = 0;
    for(int n = 1 ; n <= 100 ; n++)
        for(int m = 1 ; m <= 100 ; m++){
            me(S,0);
            S[ t[n-1][m-1] ] = 1;
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= m ; j++)
                    S[ t[i-1][j-1] ^ t[i-1][m-j] ^ t[n-i][j-1] ^ t[n-i][m-j] ] = 1;

            int x = 0;
            while( S[x] ) x++;
            t[n][m] = x;
        }
    
    int tc , n , m;
    sc(tc);
    //me(t,-1);
    while( tc-- ){
        sc(n),sc(m);
        /*bool ok = 0;
        for(int i = 0 ; i < 7 ; i++)
            if( n == x[i] && m == y[i] ) ok = 1;*/
        if( t[n][m] == 0 ) printf("2\n");
        else printf("1\n");
    }
    return 0;
}
