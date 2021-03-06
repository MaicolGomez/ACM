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
#define ios ios::sync_with_stdio(0);
#define N 1000001

int n , c , a[N];

bool f(int x){
    
    int t = 1;
    int last = a[0];
    for(int i = 1 ; i < n and t < c ; i++)
        if( a[i] - last >= x ) t++ , last = a[i];
    
    return t == c;
}


int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%d%d",&n,&c);
        for(int i = 0 ; i < n ; i++)
            sc(a[i]);
        
        int lo = 0 , hi = 1000000000;
        sort( a , a + n );
        while( lo + 1 < hi ){
            int mid = M( lo , hi );
            //cout << mid << " " << f(lo) << endl;
            if( f( mid ) ) lo = mid;
            else hi = mid;
        }
        printf("%d\n",lo);
    }
    return 0;
}
