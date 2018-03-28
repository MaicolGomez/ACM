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
#define N 100101
#define ALF 30
char s[N] , t[N];
int d[ALF][ALF];

int main(){
    while( scanf("%s%s",s,t) == 2 ){
        int n;
        
        for(int i = 0 ; i < ALF ; i++)
            for(int j = 0 ; j < ALF ; j++)
                d[i][j] = inf;
        
        sc(n);
        char a , b;
        int c;
        for(int i = 0 ; i < n ; i++){
            cin >> a >> b >> c;
            d[ a - 'a' ][ b - 'a' ] = min( d[ a - 'a' ][ b - 'a' ] , c );
        }
        
        for(int k = 0 ; k < 26 ; k++)
            for(int i = 0 ; i < 26 ; i++)
                for(int j = 0 ; j < 26 ; j++)
                    d[i][j] = min( d[i][j] , d[i][k] + d[k][j] );
        
        int size = strlen(s) , size2 = strlen(t);
        if( size != size2 ) cout << -1 << '\n';
        else{
            string ans = "";
            int S = 0;
            for(int i = 0 ; i < size ; i++){
                if( s[i] == t[i] ) ans += s[i];
                else{
                    int p = s[i] - 'a' , q = t[i] - 'a';
                    int mini = 1<<30;
                    char x;
                    for(int j = 0 ; j < 26 ; j++)
                        if( mini > d[p][j] + d[q][j] ){
                            x = 'a' + j;
                            mini = d[p][j] + d[q][j];
                        }
                    
                    if( d[p][q] != inf and d[p][q] < mini ) mini = d[p][q] , mini = d[p][q] , x = 'a' + q;
                    if( d[q][p] != inf and d[q][p] < mini ) mini = d[q][p] , mini = d[q][p] , x = 'a' + p;
                    if( mini >= 1<<29 ){
                        S = -1;
                        break;
                    }
                    ans += x;
                    S += mini;
                }
            }
            if( S == -1 ) cout << S << '\n';
            else cout << S << "\n" << ans << "\n";
            
        }
    }
    return 0;
}
