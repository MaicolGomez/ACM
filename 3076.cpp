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
#define N 2000001

bool prime[N];
int A[N] , T[N];

int main(){
    me(prime,1);
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i * i < N ; i++) if( prime[i] )
        for(int j = i * i ; j < N ; j += i)
            prime[j] = 0;
    
    int ct = 1 , l = 0;
    for(int i = 4 ; i < N ; i++){
        if( !prime[i] ) A[i] = ct , l++;
        else{
            T[ct] = l + 1;
            ct++, l = 0;
        }
    }
    int n;
    while( sc(n) == 1 and n ){
        printf("%d\n",T[A[n]]);
    }
    return 0;
}