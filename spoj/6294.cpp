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
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define fi first
#define se second
#define MOD 10009
#define N 30005

int A[N] , L[N] , R[N];

int mergesort(int x,int y){
    if( x == y )
        return 0;
    int mid = (x+y)/2;
    int a = mergesort(x,mid);
    int b = mergesort(mid+1,y);
    int u = x , v = mid+1 , c = 0;
    for(int i = x ; i <= mid ; i++)
        L[i] = A[i];
    L[mid+1] = inf;
    for(int i = mid + 1 ; i <= y ; i++)
        R[i] = A[i];
    R[y+1] = inf;
    for(int i = x ; i <= y ; i++){
        if( L[u] <= R[v] )
            A[i] = L[u++];
        else A[i] = R[v++] , c += (u!=mid+1)*( mid + 1 - u );
    }
    return a + b + c;
}

int main(){
    int tc;
    sc(tc);
    while( tc-- ){
        int n;
        sc(n);
        char s[25];
        map<string , int> M;
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s);
            M[s] = i;
        }
        for(int i = 0 ; i < n ; i++){
            scanf("%s",s);
            A[i] = M[s];
        }
        printf("%d\n",mergesort(0,n-1));
        
    }
    return 0;
}
