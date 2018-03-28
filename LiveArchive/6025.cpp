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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 105

int R[N][N] , C[N][N];
char s[N][N];

int main(){
    while( ~sc(n) ){
        for(int i = 0 ; i < n ; i++)
            scanf("%s",s[i]);
        
        int V1 = 0;
        for(int i = 0 ; i < n ; i++){
            int j = 0;
            while( j < n ){
                if( s[i][j] == 'X' ) j++;
                else{
                    while( j < n and s[i][j] == '.' ){
                        R[i][j++] = V1;
                    }
                    V1++;
                }
            }
        }
        int V2 = 0;
        for(int j = 0 ; j < n ; j++){
            int i = 0;
            while( i < n ){
                if( s[i][j] == 'X' ) i++;
                else{
                    while( i < n and s[i][j] == '.' ){
                        C[i++][j] = V2;
                    }
                    V2++;
                }
            }
        }
        
    }
    return 0;
}
