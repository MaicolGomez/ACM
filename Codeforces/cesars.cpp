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
#define MOD 100000000
#define ios ios::sync_with_stdio(0);
#define N 101

int k1 , k2;
int t[N][N][2];

int f(int a,int b,int last){
    if( a == 0 and b == 0 )
        return 1;
    
    int &ret = t[a][b][last];
    if( ret != -1 ) return ret;
    ret = 0;
    if( last == 0 ){
        for(int i = 1 ; i <= min( b , k2 ) ; i++){
            ret += f( a , b - i , 1 );
            ret %= MOD;
        }
    }
    else{
        for(int i = 1 ; i <= min( a , k1 ) ; i++){
            ret += f( a - i , b , 0 );
            ret %= MOD;
        }
    }
    return ret;
}

int main(){
    int a , b;
    while( cin >> a >> b >> k1 >> k2 ){
        me(t,-1);
        cout << ( f( a , b , 0 ) + f( a , b , 1 ) ) % MOD << '\n';
    }
    
    return 0;
}
