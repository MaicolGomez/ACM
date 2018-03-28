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
#define N 1005

char S[50];
string s[N];

int main(){
    int n;
    while( sc(n) == 1 and n ){
        for(int i = 0 ; i < n ; i++)
            scanf("%s",S) , s[i] = S;
        
        sort( s , s + n );
        string ans = "";
        bool solve = 0;
        while( !solve ){
            bool hit = 0;
            for(char i = 'A' ; i <= 'Z' ; i++){
                string ns = ans + i;
                if( ns < s[ n/2 - 1 ] ) continue;                
                if( s[ n/2 - 1 ] <= ns and ns < s[ n/2 ] ){
                    ans = ns;
                    solve = 1;
                    hit = 1;
                    break;
                }
                if( s[ n/2 ] <= ns ){
                    ans += (i-1);
                    hit = 1;
                    break;
                }
            }
            if( !hit ) ans += "Z";
        }
        printf("%s\n",ans.c_str());
    }
    return 0;
}
