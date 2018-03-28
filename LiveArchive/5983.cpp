#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<set>
#include<deque>
#include<map>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
#define pii (2.0*acos(0.0))
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define N 505

int R , C , m[N][N] , t[N][N];

int main(){
    int tc;
    cin >> tc;
    while( tc-- ){
        cin >> R >> C;
        for(int i = 1 ; i <= R ; i++)
            for(int j = 1 ; j <= C ; j++)
                cin >> m[i][j];
        for(int i = 0 ; i <= R ; i++)
            for(int j = 0 ; j <= C ; j++)
                t[i][j] = -inf;
        int ans = inf;
        t[1][1] = 0;
        cout << t[1][1] << " ";
        for(int i = 1 ; i <= R ; i++){
            for(int j = 1 ; j <= C ; j++){
                if( i == 1 && j == 1 ) continue;
                t[i][j] = m[i][j] + max( t[i-1][j] , t[i][j-1] );
                if( t[i][j] <= 0 ) ans = min( ans , -t[i][j] + 1 );
                cout << t[i][j] << " " ;
            }
            cout << endl;
        }
        //if( ans == inf ) ans = 1;
        cout << ans << endl;
        
    }
}
