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
#define ios ios::sync_with_stdio(0)
#define N 15

int a[N] , t[10][11][101] , T , dig;

int f(int x,int s,int have){
    if( x == 9 ){
        if( abs( s - (T - s) ) % 11 == 0 ){
            int nothave = dig - have;
            if( have <= nothave ) while( nothave - have > 1 ) have++;
            else while( have - nothave > 1 ) nothave++;
            return have + nothave;
        }
        return inf;
    }
    int &ret = t[x][s][have];
    if( ret != -1 ) return ret;
    ret = inf;
    for(int i = 0 ; i <= a[x] ; i++)
        ret = min( ret , f( x + 1 , (s + (x+1) * i )%11 , have + i ) );
    return ret;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        T = 0;
        dig = 0;
        for(int i = 0 ; i < 9 ; i++){
            sc(a[i]);
            dig += a[i];
            T += (i + 1) * a[i];
        }
        me(t,-1);
        if( f( 0 , 0 , 0 ) < inf ){
            printf("%d\n", f( 0 , 0 , 0 ) );
        }
        else printf("-1\n");
    }
    return 0;
}
