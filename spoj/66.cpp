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
#define inf (1<<30)
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
#define fi first
#define se second
#define MOD 10009
#define N 2005

int a[N] , b[N];
int t[N][N];

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int x , l = 0 , ans = 0 , l1 = 0;
        for( ; sc(x) && x != 0 ; )
            a[l++] = x;
        
        /*cout << "a: " << endl;
        for(int i = 0 ; i < l ; i++)
            cout << a[i] << " ";
            cout << endl;
          */  
        while( sc(x) && x != 0 ){
            l1 = 1;
            b[0] = x;
            for( ; sc(x) && x != 0 ; )
                b[l1++] = x;
            
            /*cout << "b: " << endl;
            for(int i = 0 ; i < l1 ; i++)
                cout << b[i] << " ";
            cout << endl;*/
            
            me(t,0);
            for(int i = l-1 ; i >= 0 ; i--)
                for(int j = l1-1 ; j >= 0 ; j--){
                    t[i][j] = max( t[i+1][j] , t[i][j+1] );
                    if( a[i] == b[j] ) t[i][j] = max( t[i][j] , t[i+1][j+1] + 1 );
                }
            
            ans = max( t[0][0] , ans );
        }
        printf("%d\n",ans);
    }
    return 0;
}
