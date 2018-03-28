#include<bits/stdc++.h>
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
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)
#define N 100000

vector< pair < string , int > > v[4];
int need[4] = { 1 , 4 , 4 , 2 };
int ans;
vector<string> t;
map< pair< string , string > , int > M;

void back(int id,int x,int h,int P){
    cout << id << " " << x << endl;
    if( id == 4 ){
        for(int i = 0 ; i < t.size() ; i++)
            for(int j = i + 1 ; j < t.size() ; j++)
                P += M[mp( t[i] , t[j] )];
        ans = max( ans , P );
        return;
    }
    if( need[id] == h ) back( id + 1 , 0 , 0 , P );
    if( x < v[id].size() ){
        back( id , x + 1 , h , P );
        t.pb( v[id][x].fi );
        back( id , x + 1 , h + 1 , P + v[id][x].se );
        t.pop_back();
    }
    return;
}

int main(){
    ios;
    string name , pos;
    int x;
    while( cin >> name ){
        t.clear();
        M.clear();
        cin>> x >> pos;
        ans = -10000000;
        int a = 0 , d = 0 , m = 0 , e = 0;
        if( pos == "goalkeeper" ) a++ , v[0].pb( mp(name,x) );
        else if( pos == "defender" ) d++ , v[1].pb( mp(name,x) );
        else if( pos == "midfielder" ) m++ , v[2].pb( mp(name,x) );
        else e++ , v[3].pb( mp(name,x) );
        for(int i = 0 ; i < 22 ; i++){
            cin >> name >> x >> pos;
            if( pos == "goalkeeper" ) a++ , v[0].pb( mp(name,x) );
            else if( pos == "defender" ) d++ , v[1].pb( mp(name,x) );
            else if( pos == "midfielder" ) m++ , v[2].pb( mp(name,x) );
            else e++ , v[3].pb( mp(name,x) );
        }
        int c , val;
        string A , B;
        cin >> c;
        for(int i = 0 ; i < c ; i++){
            cin >> A >> B >> val;
            M[ mp(A,B) ] = val;
            M[ mp(B,A) ] = val;
        }
        if( a < 1 or d < 4 or m < 4 or e < 2 ){ cout << "-1\n"; continue; }
        back( 0 , 0 , 0 , 0 );
        cout << "sale\n";
    }
    return 0;
}
