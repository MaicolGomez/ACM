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
#define N 1000000

int f[10] = {1,1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
int FacSum(int n){
    int temp = n;
    int facsum = 0;
 
    while (temp > 0) {
        facsum += f[temp % 10];
        temp /= 10;
    }
    return facsum;
}


int main(){
    int limit = 1000000;             
    int result = 0;
                 
    for(int i = 1; i <= limit; i++){
        int n = i;
        set<int> seq;
                     
        while( seq.count(n) == 0 ){
            seq.insert(n);
            n = FacSum(n);
        }
                     
        if (seq.size() == 60) result++;
    }
    cout << result << endl;
    return 0;
}
