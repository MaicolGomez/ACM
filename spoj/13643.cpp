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
#define N 1005

int t[N] , a[N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , s;
        scanf("%d%d",&n,&s);
        n++;
        s++;
        for(int i = 1 ; i < n ; i++)
            sc(a[i]);
        a[0] = INT_MAX;
        t[0] = 0;
        for(int i = 1 ; i < n ; i++){
            t[i] = 0;
            for(int j = i - 1 ; j >= 0 ; j--){
                if( j == s ) t[i] = max( t[i] , t[j] + 1 );
                else if( a[i] < a[j] ) t[i] = max( t[i] , t[j] + 1 );
            }
        }
        int best = 0;
        for(int i = 0 ; i < n ; i++)
            best = max( best , t[i] );
        printf("%d\n",best);
    }
    return 0;
}
