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
#define N 100001

char s[N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%s",s);
        int n = strlen(s) , pot = 1 , ans = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            if( s[i] == '1' ) ans += pot;
            ans %= 3;
            pot *= 2;
            pot %= 3;
        }
        if( ans == 0 ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
