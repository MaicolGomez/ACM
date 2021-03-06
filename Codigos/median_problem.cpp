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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define N 1005

int toint(char *s){
    int x = 0 , n = stlren(s);
    for(int i = 0 ; i < n ; i++) x = x * 10 + (s[i]-'0');
    return x;
}

int main(){
    priority_queue < int , vector<int>, less <int> > a;
    priority_queue < int , vector<int>, greater <int> > b;
    char s[12];
    int n = 0;
    while( scanf("%s",s) == 1 ){
        if( s[0] == '#' ){             //query o consulta
            if( n&1 ) printf("%d\n",a.top()); a.pop();
            else if( b.size() > 0 )
                printf("%d\n",b.top()); b.pop();
            n--;
        }
        else{           //insert value
            int x = toint( s );
            if( n&1 ){
                a.push(x);
                b.push( a.top() ); a.pop();
            }
            else{
                b.push(x);
                a.push( b.top() ); b.pop();
            }
        }
    }
    
    return 0;
}
