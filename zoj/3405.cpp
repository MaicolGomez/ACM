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
#define ll unsigned long long
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
#define N 100001

ll C[64];
int F[100] , num[100];
int p , e[100] , prime[500];


ll f(int n){
    me(e,0);
    e[n]++;
    for(int i = 0 ; i < p ; i++)
        e[ F[i] ]--;
    
    for(int i = n - 1 ; i >= 2 ; i--)
        e[i] += e[i+1];
    
    for(int i = n ; i >= 2 ; i--)if( prime[i] ){
        //cout << prime[i] << " " << endl;
        e[ i/prime[i] ] += e[i];
        e[ prime[i] ] += e[i];
        e[i] = 0;
    }
    
    ll ans = 1;
    for(int i = 2 ; i <= n ; i++)if( !prime[i] )
        for(int j = 0 ; j < e[i] ; j++) ans *= i;
    
    return ans;
}

int main(){
    
    for(int i = 2 ; i * i <= 400 ; i++)
        if( !prime[i] )
            for(int j = i * i ; j <= 400 ; j += i)
                prime[j] = i;
    
    /*for(int i = 2 ; i <= 20 ; i++)
        cout << i << " " << prime[i] << endl;
*/
    
    C[1] = 1;
    for(int i = 2 ; i <= 64 ; i++){
        C[i] = 0;
        for(int j = 1 ; j < i ; j++)
            C[i] += C[j] * C[i - j];
    }
        
    
    /*for(int i = 0 ; i <= 64 ; i++)
        cout << C[i] << endl;
    */
    ll n;
    while( scanf("%llu",&n) == 1 ){
        //vector<ll> v;
        p = 0;
        for(ll i = 2 ; i * i <= n ; i++){
            if( n%i == 0 ){
                int k = 0;
                while( n%i == 0 ){
                    n /= i;
                    k++;
                }
                num[p] = i;
                F[p++] = k;
            }
        }
        if( n > 1 ){
            num[p] = n;
            F[p++] = 1;
        }
        int r = 0;
        for(int i = 0 ; i < p ; i++)
           r += F[i];
        
        
        printf("%llu\n",C[r] * f( r ) );

    }
    return 0;
}
