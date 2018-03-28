#include<iostream>
#include<cmath>
#include<deque>
#include<cstdio>
#include<sstream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

vector<int>v;
bool prime[10005];
vector<int> adj[10005];
int target , d[10005];
bool val(int a , int b){
    int ct = 0;
    while( a > 0){
        ct += ( a%10 != b%10 );
        a/=10, b/=10;
    }
    return (ct==1);
}

void cons(){
    for(int i = 0 ; i < v.size() ; i++)
        for(int j = 0; j < v.size() ; j++) if( i!=j )
            if( val( v[i] , v[j] ) ) adj[ v[i] ].push_back(v[j]);
}

int bfs(int source){
    if( source == target ) return 0;
    memset( d , -1 , sizeof(d) );
    deque<int> Q(1,source);
    d[source] = 0;
    while( !Q.empty() ){
        int q = Q.front();
        Q.pop_front();
        vector<int> a = adj[q];
        for(int i = 0 ; i < a.size() ; i++)if( d[ a[i] ] == -1 ){
            d[ a[i] ] = d[q] + 1;
            if( a[i] == target ) return d[a[i]];
            Q.push_back( a[i] );
        }
    }
    return -1;
}

int main(){
    memset(prime,1,sizeof(prime));
    for(int i = 2 ; i * i <= 10000 ; i++) if(prime[i])
        for(int j = i*i ; j <= 10000 ; j+=i) prime[j] = 0;
    for(int i = 1000 ; i <= 10000 ; i++) if(prime[i]) v.push_back(i);
    cons();
    int n;
    cin >> n;
    while( n-- ){
        int a;
        cin >> a >> target;
        if( a > target ) swap(a , target);
        int x = bfs(a);
        if(x == -1) puts("Impossible");
        else cout<<x<<endl;
    }
}
