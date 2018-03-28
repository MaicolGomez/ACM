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
#define MOD 10009
#define N 100005

pii A[N];

int main(){
    freopen( "lan.in" , "r" , stdin );
    freopen( "lan.out" , "w" , stdout );
    
    int n , m;
    while( scanf("%d%d",&n,&m) == 2 ){
        int x , S = 0 , maxi = 0 , pos;
        for(int i = 1 ; i <= m ; i++){
            scanf("%d",&x);
            A[i-1] = mp( x , i );
            S += x;
            if( x > maxi ){
                maxi = x , pos = i;
            }
        }
        if( S < n )
            printf("Epic fail\n");
        else if( maxi >= n ){
            printf("%d\n%d\n",1,pos);
        }
        else{
            sort( A , A + m );
            int have = 0 , k = 0;
            vi v;
            for(int i = m - 1 ; i >= 0 ; i--){
                have += A[i].fi - 1; v.pb( A[i].se );
                k++;
                if( have >= n ) break;
                if( i != m - 1 ) have--;
            }
            if( have >= n ){
                printf("%d\n",k);
                for(int i = 0 ; i < v.size() ; i++){
                    if( i ) printf(" ");
                    printf("%d",v[i]);
                }
                printf("\n");
            }
            else printf("Epic fail\n");
        }
        
    }
    return 0;
}
