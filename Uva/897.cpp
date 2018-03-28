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
#define N 3500

bool prime[N+5];
vi v;
vi res;

string g(int x){
    string s = "";
    while( x ){
        s += (x%10 + '0');
        x /= 10;
    }
    reverse( all(s) );
    return s;
}

int A[4] = { 1 , 3 , 7 , 9 };

bool isPrime(int n){
    for(int i = 0 ; i < v.size() ; i++)if( v[i] != n )
        if( n % v[i] == 0 ) return 0;
    return 1;
}

bool anagram(int x){
    string s = g( x );
    sort( all(s) );
    do{
        int n = 0;
        for(int i = 0 ; i < s.size() ; i++)
            n = n * 10 + (s[i] - '0');
        
        if( isPrime( n ) == 0 ) return 0;
    }while( next_permutation( all(s) ) );
    return 1;
}

void generate(int x,int C,int L){
    if( C == L ){
        if( anagram( x ) )
            res.pb( x );
        return;
    }
    for(int i = 0 ; i < 4 ; i++)
        generate( x * 10 + A[i] , C + 1 , L );
}

void criba(){
    me(prime,1);
    prime[0] = prime[1] = 0;
    for(int i = 2 ; i * i <= N ; i++)
        if( prime[i] )
            for(int j = i * i ; j <= N ; j += i)
                prime[j] = 0;
    
    for(int i = 2 ; i < N; i++)
        if(prime[i]) v.pb(i);
    
    res.pb( 2 ) , res.pb( 3 ) , res.pb( 5 ) , res.pb( 7 ) ;
    for(int i = 2 ; i <= 8 ; i++)
        generate( 0 , 0 , i );

}

int main(){
    int x;
    criba();
    while( cin >> x , x ){
        int lo , hi = -1;
        if( x < 10 ) lo = 0 , hi = 10;
        else if( x < 100 ) lo = 10 , hi = 100;
        else if( x < 1000 ) lo = 100 , hi = 1000;
        for(int i = 0 ; i < res.size() ; i++){
            if( res[i] > x && res[i] < hi ){
                cout << res[i] << endl;
                goto gg;
            }
        }
        cout << 0 << endl;
        gg:;
    }
    return 0;
}
