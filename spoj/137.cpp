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
#define N 222

int t[N][N][12];

int f(int last,int n,int p){
    if( p == 1 )
        return last <= n;
    int &ret = t[last][n][p];
    if( ret != -1 ) return ret;
    ret = 0;
    for(int i = last ; i <= n ; i++)
        ret += f( i , n - i , p - 1 );
    return ret;
}

int main(){
    me(t,-1);
    int tc;
    sc(tc);
    while( tc-- ){
        int n , p , k ;
        sc(n),sc(p),sc(k);
        int last = 1;
        while( p > 1 ){
            for(int i = last ; i <= n-p+1 ; i++){
                int r = f( i , n - i , p - 1 );
                if( r >= k ){
                    printf("%d ",i);
                    n -= i;
                    p--;
                    last = i;
                    break;
                }
                k -= r;
            }
        }
        
        //k += ok&&k!=n;
        printf("%d\n", n);
        //cout << "k: " << k << endl;
        
    }
    return 0;
}
