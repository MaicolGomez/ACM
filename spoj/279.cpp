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
#define inf (1<<28)
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

#define N 2005

int t[N][N] , pa[N][N];
int MOD;

int f(int s,int mod){
    if( mod == 0 && s == MOD )
        return 0;
    int &ret = t[s][mod];
    if( ret != -1 ) return ret;
    ret = inf;
    int x = 0;
    for(int i = 0 ; i < 10 ; i++)if( s + i <= MOD ){
        int r = 1 + f( s + i , ( mod * 10 + i ) % MOD );
        if( r < ret ){
            ret = r;
            x = i;
        }
    }
    pa[s][mod] = x;
    return ret;
}

int bfs( int n ){
    //cout << n << " ???" << endl;
    queue<int>Q;
    vi d( n * n * 10 + n , inf );
    for(int i = 1 ; i < 10 ; i++){
        Q.push( n * i + i );  // Suma = N - 1000 , MOD = N % 1000
        d[ n * i + i ] = 1;
    }
    while( !Q.empty() ){
        int q = Q.front();
        Q.pop();
        int s = q / n , mod = q % n;
        if( s > n ) continue;
        if( s == n && mod == 0 ) return d[q];
        for(int i = 0 ; i < 10 ; i++){
            int ns = s + i , nmod = (mod * 10 + i) % n;
            if( s <= n && d[ n * ns + nmod ] > d[q] + 1 ){
                d[ n * ns + nmod] = d[q] + 1;
                if( ns == n && nmod == 0 ) return d[q] + 1;
                Q.push( n * ns + nmod );
            }
        }
    }
    
}

void print(int s,int mod){
    if( s == MOD && mod == 0 )
        return;
    
    int g = pa[s][mod];
    printf("%d",g);
    print( s + g , ( mod*10 + g )%MOD );
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(MOD);
        if( MOD < 10 ){
            printf("%d\n",MOD);
            continue;
        }
        cout << bfs(MOD) << endl;
        
        /*for(int i = 0 ; i < MOD+2 ; i++)
            memset( t[i] , -1 , sizeof(int)*(MOD+2) );
            
        int ans = inf , x;
        for(int i = 1 ; i < 10 ; i++){
            if( f( i , i%MOD ) < ans ){
                x = i;
                ans = f( i , i%MOD );
            }
        }
        printf("%d: %d",MOD,x);
        print( x , x%MOD );
        printf("\n");*/
    }
    return 0;
}
