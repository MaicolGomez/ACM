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
#define inf 2000000000
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
#define N 100005
#define ALF 55

int n, T[N][ALF] , node;

int get( char *s ){
    char suit;
    int x;
    if( strlen(s) == 3 )
        suit = s[2] , x = 10;
    else{
        suit = s[1];
        if( s[0] == 'A' ) x = 1;
        else if( s[0] == 'J' ) x = 11;
        else if( s[0] == 'Q' ) x = 12;
        else if( s[0] == 'K' ) x = 13;
        else x = s[0] + '0';
    }
    if( suit == 'C' ) return x;
    else if( suit == 'D' ) return 13 + x;
    else if( suit == 'H' ) return 26 + x;
    else return 39 + x;
}


int main(){
    while( sc(n) , n ){
        me(T,-1);
        node = 1;
        int k;
        char s[55][4];
        for(int i = 0 ; i < n ; i++){
            sc(k);
            for(int j = 0 ; j < k ; j++)
                scanf("%s",s[j]);
            int ac = 0;
            for(int j = k - 1 ; j >= 0 ; j--){
                int r = get( s[j] );
                if( T[ac][r] == -1 ) T[ac][r] = node++;
                ac = T[ac][r];
            }
        }
        printf("%d\n",node-1);
    }
}
