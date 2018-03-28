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
#define N 101

string s;
int a[N];

int main(){
    int tc;
    sc(tc);
    getline(cin , s);
    while( tc-- ){
        getline( cin , s );
        int n = 0;
        stringstream in(s);
        int x;
        while( in >> x ){
            a[n++] = x;
        }
        sort( a , a + n );
        int ans = (1<<30);
        do{
            int x = 0 , y = 0;
            if( a[0] == 0 or a[n/2] == 0 ) continue;
            for(int i = 0 ; i < n/2 ; i++)
                x = x * 10 + a[i];
            
            for(int i = n/2 ; i < n ; i++)
                y = y * 10 + a[i];
            
            ans = min( ans , abs( x - y ) );
            
        }while( next_permutation( a , a + n ) );
        
        if( n == 2 ) ans = a[1] - a[0];
        
        printf("%d\n",ans);
    }
    return 0;
}
