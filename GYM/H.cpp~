
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

map<int,int> mapa;


string romanos[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV" ,"I"};
int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};


int f(int num){
    string res = "";
    for(int i = 0 ; i < 13 ; i++){
        while( val[i] <= num ){
            res += romanos[i];
            num -= val[i];
        }
    }
    return res.size();
}

int get(string s){
    int ans = 0;
    bool A = 0 , B = 0;
    for(int i = 0 ; i < s.size() ; i++){
        if( s[i] == 'A' ) A = 1;
        if( s[i] == 'B' ) B = 1;
        if( s[i] >= '0' && s[i] <= '9' )
            ans = ans * 10 + (s[i]-'0');
    }
    if(B) return mapa[ans];
    if(A) return ans + A*753;
}

int main(){
    freopen( "roman.in" , "r" , stdin );
    freopen( "roman.out" , "w" , stdout );
    string s;
    int k = 1;
    for(int i = 753 ; i >= 1 ; i--)
        mapa[i] = k++;
    while( cin >> s ){
        for(int i = 0 ; i < s.size() ; i++)
            if( s[i] == '-' ) s[i] = ' ';
        
        stringstream in(s);
        string a , b;
        in >> a >> b;
        int x = get(a) , y = get(b);
        int ans = 0;
        for(int i = x ; i <= y ; i++){
            ans = max( ans , f( i ) );
        }
        printf("%d\n",ans);
    }
    return 0;
}

