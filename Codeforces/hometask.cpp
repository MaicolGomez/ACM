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
#define ios ios::sync_with_stdio(0);
#define N 100001

int a[N] , C[10];
bool used[N];

int main(){
    int n;
    while( sc(n) == 1 ){
        int S = 0 , c = 0;
        
        me(C,0);
        for(int i = 0 ; i < n ; i++)
            sc(a[i]), S += a[i] , c += (a[i]==0) , used[i] = 1 , C[a[i]]++;
        
        
        
        if( S % 3 == 0 and c > 0 ){
            if( S == 0 ) cout << 0 ;
            else{
                sort( a , a + n );
                for(int i = n-1 ; i >= 0 ; i--)
                    printf("%d",a[i]);
            }
            printf("\n");
        }
        else if( c > 0){
            bool solve = 0;
            for(int i = 1 ; i < 10 ; i++)if( C[i] > 0 ){
                if( (S - i) % 3 == 0 ){
                    S -= i;
                    C[i]--;
                    solve = 1;
                    if( S == 0 ) cout << 0 << '\n';
                    else{
                        for(int ii = 9 ; ii >= 0 ; ii--)
                            for(int j = 0 ; j < C[ii] ; j++)
                                printf("%d",ii);
                    
                        cout << '\n';
                    }
                    break;
                }
            }
            if( solve == 0 ){
                for(int j = 1 ; j <= 9 ; j++)if( C[j] )
                    for(int k = 1 ; !solve and k <= j ; k++)if( C[j] and C[k] ){
                        if( j == k and C[j] < 2 ) continue;
                        if(  (S - j - k) % 3 != 0 ) continue;
                        C[j]-- , C[k]--;
                        S -= (j+k);
                        
                        if( S == 0 ){
                            cout << "0";
                            solve = 1;
                        }
                        
                        for(int p = 9 ; !solve and p >= 0 ; p--)
                            for(int q = 0 ; q < C[p] ; q++)
                                cout << p;
                        
                        cout << '\n';
                        solve = 1;
                        break;
                    }
                
                if( !solve ) cout << -1 << '\n';
                
            }
        }
        else cout << -1 << '\n';
    }
    return 0;
}
