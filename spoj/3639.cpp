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
#define N 1005

int main(){
    int tc;
    sc(tc);
    while(tc--){
        int x;
        sc(x);
        for(int i = 1 ; i <= 200 ; i++){
            for(int seis = i ; seis >= 0 ; seis--){
                int mod = 0;
                for(int j = 1 ; j <= i - seis ; j++)
                    mod = ( mod * 10 + 8 )%x;
                for(int j = 1 ; j <= seis ; j++)
                    mod = ( 10 * mod + 6 ) % x;
                
                if( mod == 0 ){
                    for(int j = 1 ; j <= i - seis ; j++)
                        printf("8");
                    for(int j = 1 ; j <= seis ; j++)
                        printf("6");
                    printf("\n");
                    goto xx;
                }
                
            }
        }
        printf("-1\n");
        xx:;
        
    }
    return 0;
}
