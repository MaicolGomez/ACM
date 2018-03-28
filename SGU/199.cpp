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
#define N 100005

using namespace std;  
  
struct Int {  
    int s,b;  
    int id;  
    Int(){}
    bool operator < (const Int & a) const {  
        if(s!=a.s) return s<a.s;  
        return b>a.b;  
    }  
};

Int a[N];
  
int n;  
int dp[N],f[N],fa[N],lo[N];
int size;
  
int bsearch(int a) {  
    int l=1,r=size;  
    int ans = 0;
    while( l <= r) {  
        int mid=(l+r)/2;  
        if(a>f[mid]){
            if(ans<mid) ans=mid;  
            l=mid+1;  
        }else {  
            r=mid-1;  
        }  
    }  
    return ans+1;  
}  
  
int LIS(){  
    size=0;  
    f[0]=0;lo[0]=0;  
    for(int i = 1 ; i <= n ; i++) {  
        int j = bsearch(a[i].b);
        if( j > size ){
            lo[j]=i;  
            f[j]=a[i].b;  
            fa[i]=lo[j-1];  
            size++;  
        }
        else{
            lo[j]=i;  
            f[j]=a[i].b;  
            fa[i]=lo[j-1];  
        }  
    }  
    return size;  
}  
  
int main(){  
    scanf("%d",&n);  
    for(int i=1;i<=n;i++) {  
        scanf("%d%d",&a[i].s,&a[i].b);  
        a[i].id=i;  
    }
    sort(a+1,a+n+1);  
    int ans = LIS();  
    printf("%d\n",ans);
    int u = lo[ans];  
    while(u) {  
        printf("%d ",a[u].id);  
        u = fa[u];  
    }  
    printf("\n");  
    return 0;  
}  
