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
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 70005
#define LMAX 300

int a[N] , b[LMAX][LMAX];

int main(){
    int n , c = 0 , y = 0;
    sc(n);
    for(int i = 0 ; i < n ; i++){
        sc(a[i]);
        b[c][y++] = a[i];
        if( y == LMAX ){
            sort( b[c] , b[c] + LMAX );
            y = 0 , c++;
        }
    }
    int q , x , t;
    sc(q);
    while( q -- ){
        scanf("%d%d%d",&x,&y,&t); x--,y--;
        int h = x;
        bool ok = 0;
        //cout << h << " " << t<< "\n";
        while( h <= y and h % LMAX != 0 and !ok )
            if( a[h++] == t ) ok = 1;
        
        for(int i = h ; i <= y and !ok ; i += LMAX){
            if( i + LMAX - 1 <= y ) ok = binary_search( b[i/LMAX] , b[i/LMAX] + LMAX , t );
        }
        
        while( !ok and y % LMAX != 0 and y >= x ){
            if( a[y--] == t ) ok = 1;
        }
        if( y >= x and !ok ) ok = (a[y] == t);
        printf("%d", (ok?1:0) );
    }
    printf("\n");
    
    
    return 0;
}
