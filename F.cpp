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
#define N 1005


vi v;
bool vis[N];
string S[N] , ans;

double f(int *A){
    int c = 0;
    for(int i = 0 ; i < 50 ; i++){
        int l = 0 , r = 0;
        for(int j = 0 ; j < 81 ; j++){
            if( S[i][j] == 'L' ) l += A[j];
            else if( S[i][j] == 'R' ) r += A[j];
        }
        if( ans[i] == '=' && l == r ) c++;
        else if( ans[i] == 'L' && l > r ) c++;
        else if( ans[i] == 'R' && r > l ) c++;
    }
    return c / 50.0;
}

int main(){
    /*me(vis,0);
    int k = rand()%5000;
    for(int i = 0 ; i < 50 ; i++){
        int x = rand()%6000;
        cout << x << " " << k << endl;
        x = ( x + k )% 81 + 1;
        while( vis[x] ) x = rand()%81 + 1;
        vis[x] = 1;
        v.pb(x);
    }
    cout << "W\n";
    int L = 0 , R = 0;
    for(int i = 0 ; i < 50 ; i++){
        int ct = 1;
        for(int j = 1 ; j <= 81 ; j++){
            if( v[i] == j ){
                cout << '-'; continue;
            }
            if( ct <= 40  ) cout << 'L' , L++;
            else cout << 'R' , R++;
            ct++;
        }
        cout << '\n';
    }
    */
    
    string s;
    cin >> s;
    for(int i = 0 ; i < 50 ; i++)
        cin >> S[i];
    cin >> ans;
    int A[85] , B[85];
    for(int i = 1 ; i <= 81 ; i++){
        for(int j = 1 ; j <= 81 ; j++){
            if( i == j ) A[j] = 100 , B[j] = 99;
            else A[j] = 99 , B[j]  = 100;
        }
        double p = f( A ) , q = f( B );
        if( p > 0.2 && p < 0.5 ) cout << i << " " << 'H' << " " << p << '\n';
        if( q > 0.2 && q < 0.5 ) cout << i << " " << 'L' << " " << p << '\n';
    }
    return 0;
}
