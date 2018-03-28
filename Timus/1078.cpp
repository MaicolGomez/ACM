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
 #define N 505
 
struct nodo{
    int x , y , id;
    nodo(){}
    nodo(int X,int Y,int Id){
        x = X;
        y = Y;
        id = Id;
    }
};

bool operator<(nodo A,nodo B){
    if( A.y - A.x != B.y - B.x ) return A.y - A.x < B.y - B.x;
    if( A.x > B.x ) return A.y < B.y;
    return 1;
}
 
 nodo P[N];
 int t[N] , pa[N];
 
 bool in(int a,int b){
    return P[b].x < P[a].x && P[a].y < P[b].y;
 }
 
int main(){
    int n;
    sc(n);
    for(int i = 1 ; i <= n ; i++)
        sc(P[i].x) , sc(P[i].y) , P[i].id = i , t[i] = 1;
    sort( P + 1 , P + n + 1 );
    
    me(pa,-1);
    int ans = 0 , x = 502;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j < i ; j++)
            if( in( j , i ) )
                if( t[j] + 1 > t[i] ){
                    t[i] = t[j] + 1;
                    if( t[i] > ans ){
                        ans = t[i];
                        x = i;
                    }
                    pa[i] = j;
                }
            
    
    if( x == 502 ){
        printf("1\n1\n");
        return 0;
    }
    printf("%d\n",t[x]);
    vector<int> res;
    
    int r = x;
    while( r != -1 ){
        res.pb( P[r].id );
        r = pa[r];
    }
    reverse( all(res) );
    for(int i = 0 ; i < res.size() ; i++){
        if( i ) printf(" ");
        printf("%d",res[i]);
    }
    printf("\n");
    return 0;
 }
