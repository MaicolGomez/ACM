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
#define N 55

bool used[N];
int n , k , t[N][N][N];

int f(int x,int a,int b){
    if( b > a ) return 0;
    //cout << x << " " << a << " " << b << endl;
    if( x == 2 * n )
        return a == b;
    int &ret = t[x][a][b];
    if( ret != -1 ) return ret;
    ret = 0;
    if( used[x] )
        ret = f( x + 1 , a + 1 , b );
    else
        ret = f( x + 1 , a + 1 , b ) + f( x + 1 , a , b + 1 );
    
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        sc(n),sc(k);
        int x;
        me(used,0);
        for(int i = 0 ; i < k ; i++){
            sc(x); x--;
            used[x] = 1;
        }
        me(t,-1);
        printf("%d\n",f(0 , 0 , 0 ));
    }
    return 0;
}
