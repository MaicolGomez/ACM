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
#define N 1000001

int a[105] , t[N] , m[50*N];
ll S[N];

int main(){
    int x , n , mini = INT_MAX , maxi = -INT_MAX;
    sc(x);
    for(int i = 0 ; i < x ; i++){
        sc(a[i]);
        if( a[i] < mini ) mini = a[i];
        if( a[i] > maxi ) maxi = a[i];
    }
    sc(n);
    for(int i = 1 ; i <= n ; i++){
        sc(t[i]);
        S[i] = S[i-1] + t[i];
    }
    
    int h = 0;
    for(int i = 1 ; i <= n ; i++){
        for(int j = i ; j <= n ; j++){
            ll r = S[j] - S[i-1];
            if( r <= maxi and r >= mini ) m[h++] = r;
        }
    }
    sort( m , m + h );
    for(int i = 0 ; i < x ; i++)
        printf("%d\n", int(upper_bound( m , m + h , a[i] ) - lower_bound( m , m + h , a[i] )) );
    
    return 0;
}
