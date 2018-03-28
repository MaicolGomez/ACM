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
#define inf (1<<29)
#define eps 1e-6
#define ll long long
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
#define N 10000


int main(){
    int a , b , c;
    while( scanf("%d%d%d",&a,&b,&c) == 3 , a , b , c ){
        int sum = inf , tx = inf , ty = inf;
        
        for(int y = 0 ; y <= N; y++){
            if( ( b * y + c ) % a == 0 ){
                int x = ( b * y + c ) / a;
                if( x + y <= tx + ty ){
                    if( x + y < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                    else if( x * a + y * b < sum  ) tx = x , ty = y , sum = x * a + y * b;
                }
            }
            if( ( c - b * y ) % a == 0 && b * y <= c ){
                int x = ( -b * y + c ) / a;
                if( x + y <= tx + ty ){
                    if( x + y < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                    else if( x * a + y * b < sum  ) tx = x , ty = y , sum = x * a + y * b;
                }
            }
        }
        
        for(int x = 0 ; x <= N; x++){
            if( ( x * a + c ) % b == 0 ){
                int y = ( x * a + c ) / b;
                if( x + y <= tx + ty ){
                    if( x + y < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                    else if( x * a + y * b < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                }
            }
            if( ( -x * a + c ) % b == 0 && a * x <= c ){
                int y = ( -x * a + c ) / b;
                if( x + y <= tx + ty ){
                    if( x + y < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                    else if( x * a + y * b < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                }
            }
        }
        /*
        for(int y = 0 ; y <= N; y++){
            if( ( c - b * y ) % a == 0 && b * y <= c ){
                int x = ( -b * y + c ) / a;
                if( x + y <= tx + ty ){
                    if( x + y < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                    else if( x * a + y * b < sum  ) tx = x , ty = y , sum = x * a + y * b;
                }
            }
        }
        
        for(int x = 0 ; x <= N; x++){
            if( ( -x * a + c ) % b == 0 && a * x <= c ){
                int y = ( -x * a + c ) / b;
                if( x + y <= tx + ty ){
                    if( x + y < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                    else if( x * a + y * b < tx + ty ) tx = x , ty = y , sum = x * a + y * b;
                }
            }
        }
        */
        
        printf("%d %d\n",tx,ty);
        
    }
}