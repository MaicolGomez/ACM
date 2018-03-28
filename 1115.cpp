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
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 1005

pair<double,double> A[N];

int main(){
    int n , test = 1;
    double d;
    while( cin >> n >> d ){
        if( n == 0 and d == 0 ) break;
        bool can = 1;
        for(int i = 0 ; i < n ; i++){
            cin >> A[i].fi >> A[i].se;
            if( A[i].se > d ) can = 0;
        }
        cout << "Case " << test++ << ": ";
        if( can ){
            sort( A , A + n );
            double center = -(1e50);
            int ans = 0;
            for(int i = 0 ; i < n ; ){
                while( i < n and sqrt( Q(A[i].se) + Q(A[i].fi - center) ) <= d + eps ) i++;
                
                if(i < n ){
                    ans++;
                    double ncenter = 1e50;
                    for(int j = i ; j < n ; j++)
                        ncenter = min( ncenter , A[j].fi + sqrt( Q(d) - Q(A[j].se) ) );
                    center = ncenter;
                }
                //cout << center << " " << i << endl;
            }
            cout << ans << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}
