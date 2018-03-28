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
#define N 100001

int a[N] , n , t[N] , S[N] , S1[N] , L;
int g[N];

    
int main(){
    while( sc(n) == 1 ){
        L = 0;
        for(int i = 0 ; i < n ; i++)
            sc(a[i]) , L += a[i];
            
        if( L % 3 != 0 ){
            printf("0\n");
            continue;
        }
        L /= 3;
        
        S[0] = a[0];
        for(int i = 1 ; i < n ; i++)
            S[i] = S[i-1] + a[i];
        
        S1[n-1] = a[n-1];
        for(int i = n - 2 ; i >= 0 ; i--)
            S1[i] = S1[i+1] + a[i];
        
        for(int i = 0 ; i < n ; i++)
            t[i] = S1[i] == L;
        
        for(int i = n - 2 ; i >= 0 ; i--)
            t[i] = t[i] + t[i+1];
        
        //for(int i = 0 ; i < n ; i++)
        //    cout << t[i] << " ";
        //cout << endl;
        ll ans = 0;
        for(int i = 0 ;  i < n - 2 ; i++)
            if( S[i] == L ) 
                ans += t[i+2];
                
        cout << ans << '\n';
    }
    return 0;
}
