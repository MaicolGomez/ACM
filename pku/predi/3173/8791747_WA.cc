#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
int n , s;
vector<int> v[21];
int main(){
    scanf("%d%d",&n,&s);
    v[1].push_back( s );
    for(int i = 2 ; i <= n ; i++){
        int r = v[i-1][0] + i;
        if( r > 9 ) r = r%9;
        v[i].push_back( r );
    }
    for(int i = 1; i <= n ; i++){
        int ct = i;
        for(int j = 1 ; j <= n-i ; j++){
            int r = v[i][j-1] + ct;
            if( r > 9 ) r = r%9;
            v[i].push_back( r );
            ct++;
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < 2*(i-1) ; j++) printf(" ");
        printf("%d",v[i][0] );
        for(int j = 1 ; j < v[i].size() ; j++){
            printf(" %d",v[i][j] );
        }
        if( i < n ) printf("\n");
    }
}
