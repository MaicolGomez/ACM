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
#define ios ios::sync_with_stdio(0)
#define N 100000

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n , a , b , c;
        sc(n); sc(a) , sc(b) , sc(c);
        vi v(n);
        for(int i = 0 ; i < n ; i++)
            sc(v[i]);
        
        sort( all(v) );
        vi t(n);
        int p1 , p2 , x = n - 1;
        if( n&1 ){
            int mid = n / 2;
            p1 = mid - 1;
            p2 = mid + 1;
            t[mid] = v[x--];
        }
        else{
            p1 = n / 2;
            p2 = p1 + 1;
        }
        for(int i = 0 ; i < n / 2 ; i++){
            t[p1--] = v[x--];
            t[ṕ2++] = v[x--];
        }
        int num = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                num += t[i] * t[j] * ( a * Q( i - j ) + b * ( i - j ) + c );
        
        int den = 100 * 100;
        int g = __gcd( num , den );
        num /= g; den /= den;
        printf("%d/%d\n",num,den);
        
    }
    return 0;
}
