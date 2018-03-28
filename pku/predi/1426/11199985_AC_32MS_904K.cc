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
#define N 105

int n , t[N][2*N] , go[N][2*N] , F;

int f(int x,int res){
    if( res == 0 )
        return 1;
    if( x >= 100 )
        return 0;
    int &ret = t[x][res];
    if( ret != -1 ) return ret;
    ret = 0;
    
    if( f( x + 1 , (res*10 + 0)%n ) ){
        go[x][res] = 0;
        ret = 1;
    }
    else if( f( x + 1 , (res*10 + 1)%n ) ){
        go[x][res] = 1;
        ret = 1;
    }
        
    return ret;
}


void im(int x,int res){
    if(F) return;
    if( res == 0 ){
        F = 1;
        return;    
    }
    if( go[x][res] == 1 ){
        cout << 1 ;
        im( x + 1 , (res * 10 + 1)%n );
    }
    else if( go[x][res] == 0 ){
        cout << 0 ;
        im( x + 1 , (res * 10 + 0)%n );
    }
}

int main(){
    while( cin >> n , n ){
        me( go , -1 );
        me(t,-1);
        f( 1 , 1 );
        F = 0;
        cout << 1 ;
        im( 1 , 1 );
        cout << endl;
    }
    return 0;
}