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

int G[N] , P[N];

int main(){
    int test = 1 , tc;
    sc(tc);
    while( tc-- ){
        int n , x;
        sc(n);
        for(int i = 1 ; i <= n ; i++){
            sc(x); G[i] = G[i-1] + x;
        }
        for(int i = 1 ; i <= n ; i++){
            sc(x); P[i] = P[i-1] + x;
        }
        int gano = -1 , a  = 1 , b = 1;
        for(int i = 1 ; i < n + 1 ; i++){
            for(int j = i ; j < n + 1 ; j++){
                if( (G[j] - G[i-1]) - (P[j] - P[i-1]) > gano ){
                    gano = G[j] - G[i-1] - (P[j] - P[i-1]);
                    a = i , b = j;
                }
            }
        }
        if( a > b ) swap( a , b );
        printf("Caso #%d: ",test++);
        if( gano < 0 ) printf("El productor no tuvo ganancias en esta Hacienda.\n");
        else printf("Inicio %d Fin %d\n",a,b);
    }
    return 0;
}
