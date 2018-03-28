#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<vector>
using namespace std;
#define N 22
#define MOD 100000000
#define pb(x) push_back(x)
#define fi first
#define se second
#define mp( x , y ) make_pair( x , y )
#define inf (1<<28)

int n , d[N][N] , t[2][1<<21][21];

int h( vector<int> &v){
    int mask = 0;
    for(int i = 1 ; i < v.size() - 1  ; i++)
        if( v[i] )
            mask |= (1<<i);
    return mask;
}

int f(int mask , int last){
    if( mask == 0 )
        return d[last][0];
    int &ret = t[0][mask][last];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = 1 ; i < n-1 ; i++)if( mask&(1<<i) )
        ret = min( ret , d[last][i] + f( mask^(1<<i) , i ) );
    
    return ret;
}

int g(int mask ,int last){
    if( mask == 0 )
        return d[last][n-1];
    int &ret = t[1][mask][last];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = 1 ; i < n-1 ; i++)if( mask&(1<<i) )
        ret = min( ret , d[last][i] + g( mask^(1<<i) , i ) );
    
    return ret;
}

int main(){
    int c , x , y , cost , test = 0;
    while( cin >> n >> c ){
        
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                d[i][j] = inf;
                
        for(int i = 0 ; i < n ; i++)
            d[i][i] = 0;
            
        for(int i = 0 ; i < c ; i++){
            cin >> x >> y >> cost;
            d[x][y] = d[y][x] = min( d[x][y] , cost );
        }
        
        if( n <= 3  ){
            cout << "Case " << ++test << ": " << 2 * ( d[0][1] + d[1][2] ) << endl;
            continue;
        }
        
        
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        
        vector<int> v( (n-2)/2 , 1 );
        for(int i = 0 ; i < n - (n-2)/2 ; i++)
            v.pb( 0 );
        
        sort( v.begin() , v.end() );
        memset( t , -1 , sizeof t );
        int ans = inf;
        do{
            if( v[0] == 1 || v[n-1] == 1 ) continue;
            int mask = h( v );
            int mask2 = (mask ^( (1<<(n-1)) - 2 ) );
            
            int a = inf , b = inf;
            for(int i = 1 ; i < n-1 ; i++)if( mask&(1<<i) ){
                for(int j = 1 ; j < n-1 ; j++)if( mask2&(1<<j) ){
                    a = min( a , f( mask^(1<<i) , i ) + d[i][j] + g( mask2^(1<<j) , j ) );
                    b = min( b , f( mask2^(1<<j) , j ) + d[i][j] + g( mask^(1<<i) , i ) );
                }
            }
            ans = min( ans , a + b );
        }while( next_permutation( v.begin() , v.end() ) );
        
        cout << "Case "<< ++test <<": " << ans << endl;
    }
}
