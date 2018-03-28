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
#define inf (1<<28)
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
#define N 102
int d[N][N];

int toint(string s){
    stringstream in(s);
    int r;
    in >> r;
    return r;
}

int main(){
    int n;
    while( cin >> n ){
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                d[i][j] = inf;
        for(int i = 0 ; i < n ; i++)
            d[i][i] = 0;
        
        string s;
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                cin >> s;
                if( s == "x" ) continue;
                int x = toint(s);
                d[i][j] = d[j][i] = x;
            }
        }
                
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            ans = max( ans , d[0][i] );
        cout << ans << endl;
    }
    return 0;
}
