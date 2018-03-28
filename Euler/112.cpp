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
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0)
#define N 100000

bool good(int number){
    bool inc = false;
    bool dec = false;
 
    int last = number % 10;
    number /= 10;
    while (number > 0) {
        int next = number % 10;
        number /= 10;
        if (next < last)
            inc = true;
        else if (next > last)
            dec = true;
        last = next;
        if (dec && inc) return true;
    } 
    return dec && inc;
}

int main(){
    int b = 0;
    for(int i = 1 ; i <= N*100 ; i++){
        if( good( i ) ) b++;
        if( 100 * b / i >= 99  ){cout << "--> " << i << "\n"; break;}
    }
    return 0;
}
