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
#define N 1000001

char s[N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        scanf("%s",s);
        if( s[0] != 'M' ){
            printf("No\n");
            continue;
        }
        int S = 0 , n = strlen(s) , ok = 0;
        for(int i = 1 ; i < n and !ok ; i++){
            if( s[i] == 'M' ) ok = 1;
            else if( s[i] == 'I' ) S++;
            else S += 3;
        }
        if( !ok and ( (S % 2 == 0 and S % 3 != 0) or S == 1 ) ) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
