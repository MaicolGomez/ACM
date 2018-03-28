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
#define N 105

string s;
int t[N][3][3];

int f(int n,int l,int r){
    if( n == 0 ) return 0;
    if( n == 1 ){
        if( l == 2 || r == 2 || l == r ) return 1;
        return 0;
    }
    int &ret = t[n][l][r];
    if( ret != -1 ) return ret;
    set<int> S;
    if( l == 2 ) S.insert( f( n - 1 , 0 , r ) ) , S.insert( f( n - 1 , 1 , r ) );
    else if( l == 1 ) S.insert( f( n - 1 , 0 , r ) );
    else if( l == 0 ) S.insert( f( n - 1 , 1 , r ) );
    
    if( r == 2 ) S.insert( f( n - 1 , l , 0 ) ) , S.insert( f( n - 1 , l , 1 ) );
    else if( r == 1 ) S.insert( f( n - 1 , l , 0 ) );
    else if( r == 0 ) S.insert( f( n - 1 , l , 1 ) );
    
    for(int i = 2 ; i < n ; i++)
        S.insert( f( i - 1 , l , 0) ^ f( n - i , 0 , r )  ) , S.insert( f( i - 1 , l , 1) ^ f( n - i , 1 , r )  );
    
    int x = 0;
    while( S.count(x) ) x++;
    
    return ret = x;
}

int main(){
    int tc;
    sc(tc);
    me(t,-1);
    while(tc--){
        cin >> s;
        int who = 0;
        
        for(int i = 0 ; i < s.size() ; i++) who += (s[i]!='.');
        
        int n , ans = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if( s[i] == '.' ){
                int l = i , r , n = 0;
                while( i < s.size() && s[i] == '.' ) n++ , i++;
                if( l > 0 )
                    l = (s[l-1] == 'X')?0:1;
                else l = 2;
                if( i  < s.size() )
                    r = (s[i] == 'X')?0:1;
                 else r = 2;
                 ans ^= f( n , l , r );
            }
        }
        
        if( who % 2 == 0 ){
            if( ans ) printf("Possible.\n");
            else printf("Impossible.\n");
        }
        else{
            if( ans == 0 ) printf("Possible.\n");
            else printf("Impossible.\n");
        }
    }
    return 0;
}
