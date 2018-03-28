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
#define MOD 1000000007
#define N 2005
#define ALP 27
string s;
vi P[N];
ll inverso;

ll fpow(int a,ll b){
    if( b == 0 ) return 1;
    if( b % 2 == 0 ){
        ll x = fpow( a , b/2 )%MOD;
        return (x*x)%MOD;
    }
    return ( a * fpow(a , b - 1)%MOD )%MOD;
}

void g(int n){
    ll a = 0 , b = 0 , pot = 1;
    for(int i = 0 ; i < n ; i++){
        a = (a * ALP + (s[i]-'a'+1))%MOD , b = (b + (s[i]-'a'+1)*pot)%MOD;
        if( i != n - 1 )
            pot *= 27 , pot %= MOD;
    }

    //cout << s << " " << n << endl;
    //cout << a << " valores iniciales " << b << " pot: " << pot  << endl;
    if( a == b ) P[0].pb(n);
    for(int i = n ; i < s.size() ; i++){
        a = (((a - pot*(s[i-n]-'a' + 1))* ALP + (s[i]-'a'+1))%MOD + MOD )%MOD;
        b = (((b - (s[i-n]-'a' + 1)) * inverso )%MOD + (pot * (s[i]-'a'+1))%MOD )%MOD;
        //cout << i << " - a: " << a << " b: " << b << " debe estar en: " << i - n + 1 << endl;
        if( a == b ) P[i-n+1].pb(n);
    }
}

ll L[N] , R[N];

int main(){
    int n;
    inverso = fpow( ALP , MOD - 2 );
    while( cin >> s ){
        for(int i = 0 ; i < s.size() ; i++)
            P[i].clear();
        for(int i = 1 ; i <= s.size() ; i++)
            g( i );
            
        /*for(int i = 0 ; i < s.size() ; i++){
            cout << i << " son ";
            for(int j = 0 ; j < P[i].size() ; j++)
                cout << P[i][j] << " ";
            cout << endl;
        }*/
        R[s.size()] = 0;
        for(int i = s.size() - 1 ; i >= 0 ; i--)
            R[i] = R[i+1] + P[i].size();
        
        ll ans = 0;
        for(int i = 0 ; i < s.size() ; i++)
            for(int j = 0 ; j < P[i].size() ; j++)
                if( i + P[i][j] < s.size() ) ans += R[ i + P[i][j] ];
        
        cout << ans << endl;
    }
    return 0;
}
