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
#define N 1000000

int di[N+5];
bool ok[N+5];

int main(){
    for(int i = 2 ; i <= N ; i++)
        di[i] = i;
    for(int i = 2 ; i * i <= N ; i++)
        if( di[i] == i )
            for(int j = i  ; j <= N ; j+=i)if( di[j] == j )
                di[j] = i;

    
    for(int i = 2 ; i <= N ; i++){
        if( di[i] == i ){
            ok[i] = 1;
            continue;
        }
        int x = i;
        int ct = 1;
        while( x > 1 ){
            int divisor = di[x], a = 0;
            while( x % divisor == 0 ){
                x /= divisor;
                a++;
            }
            ct *= (a+1);
        }
        if( di[ct] == ct )
            ok[i] = 1;
    }
    
    int tc;
    cin >> tc;
    while( tc-- ){
        int  L , H;
        cin >> L >> H;
        if( H-L >= 10000000 || H >= 10000000 ) while(1){}
        bool act = 0;
        for(int i = max( L , 2 ) ; i <= H ; i++){
            if( ok[i] ){
                if( act == 0 ) printf("%d",i),act = 1;
                else printf(" %d",i);
            }
        }
        if( act == 0 ) printf("-1");
        printf("\n");
    }
}
