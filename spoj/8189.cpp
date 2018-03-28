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
#define eps 1e-3
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
#define N 105

int x[N] , y[N] , r[N];

int main(){
    int tc , n , w , h;
    sc(tc);
    while( tc-- ){
        scanf("%d%d%d",&w,&h,&n);
        for(int i = 0 ; i < n ; i++)
            sc(x[i]),sc(y[i]),sc(r[i]);
        
        int res = 0;
        for(int i = 0 ; i < w ; i++){  // ( xc - x )^2 + ( yc - y )^2 <= r^2
            pii A[105];
            int m = 0;
            map<int,int> M;
            for(int j = 0 ; j < n ; j++){
                int dy = Q(r[j]) - Q(i - x[j]);
                if( dy >= 0 ){
                    dy = sqrt(dy);
                    int b = dy + y[j];
                    int a = -dy + y[j];
                    //cout << (int)ceil(a) << " - " << (int)floor(b) << " --> " << i << endl;
                    A[m++] = mp( max( a , 0 ) , min( b , h - 1 ) );
                }
            }
            if( m == 0 ) continue;
            sort( A , A + m );
            int ans = 0 , end = A[0].se , begin = A[0].fi;
            ans += ( end - begin + 1 );
            for(int j = 1 ; j < m ; j++){   
                if( end < A[j].fi ){
                    ans += A[j].se - A[j].fi + 1;
                    begin = A[j].fi , end = A[j].se;
                }
                else if( end < A[j].se )
                    ans += A[j].se - end;
                
                end = max( end , A[j].se );
            }
            res += ans;
        }
        printf("%d\n",w*h -res);
    }
    return 0;
}
