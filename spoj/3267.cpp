#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<cstdlib>
using namespace std;
#define N 1000005
#define fi first
#define se second

int n , t[N] , a[N];
int last[N] , ans[N] , pos = 0;

int query(int x){
    int sum = 0;
    while( x > 0 ){
        sum += t[ x ];
        x -= (x&-x);
    }
    return sum;
}

void update(int x,int val){
    while( x <= N-4 ){
        t[x] += val;
        x += x&(-x);
    }
}

pair< pair<int,int> ,int > P[200005];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++)
        scanf("%d", &a[i] );
        
    int q;
    scanf("%d",&q);
    
    for(int i = 0 ; i < q ; i++)
        scanf("%d%d",&P[i].fi.se,&P[i].fi.fi) , P[i].se = i;
    
    sort( P , P + q );
    
    memset( last , -1 , sizeof(last) );
    
    for(int i = 0 ; i < q ; i++){
        int x = P[i].fi.fi;
        for(int j = pos + 1 ; j <= x ; j++){
            if( last[ a[j] ] == -1 ){
                update( j , 1 ) , last[ a[j] ] = j;
            }
            else{
                update( j , 1 );
                update( last[ a[j] ] , -1 );
                last[ a[j] ] = j;
            }
        }
        pos = max(pos , x );
        ans[ P[i].se ] = query( x ) - query( P[i].fi.se - 1 );
    }
    for(int i = 0 ; i < q ; i++)
        printf("%d\n", ans[i] );
}


