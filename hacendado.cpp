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

int S[N] , R[N], a[N];

int main(){
    int tc , test = 1;
    sc(tc);
    while( tc-- ){
        int n , x , q;
        printf("Caso #%d:",test++);
        sc(n);
        R[n+1] = 0;
        S[0] = 0;
        for(int i = 1 ; i < n + 1 ; i++){
            sc(a[i]);
            S[i] = S[i-1] + a[i];
        }
        for(int i = n ; i >= 1 ; i--)
            R[i] = R[i+1] + a[i];
        
        sc(q);
        while( q-- ){
            int c , len , pos , sur = 1 , have;
            sc(c);
            for(int i = n ; i >= 1 ; i--){
                if( R[i] >= c ){
                    len = n - i + 1;
                    have = R[i];
                    pos = i;
                    break;
                }
            }
            for(int i = 1 ; i < n + 1 ; i++){
                if( (S[i] >= c ) and ( (S[i] < have) or (S[i] == have and i < len ) ) ){
                    len = i;
                    sur = 0;
                    break;
                }
            }
            char r;
            if( sur ) r = 'S';
            else r = 'N';
            printf(" %d %c",len,r);
        }
        printf("\n");
        
    }
    return 0;
}
