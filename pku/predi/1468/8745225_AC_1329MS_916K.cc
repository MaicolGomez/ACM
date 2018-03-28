#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

struct nodo{
    int x1, x2 , y1 , y2 , area;
     nodo( int X1 , int X2 , int Y1 , int Y2 ){
            x1 = X1;
            x2 = X2;
            y1 = Y1;
            y2 = Y2;
            area = abs(X1-X2)*abs(Y1-Y2);
    }
};

bool operator<(nodo A , nodo B){
    return A.area < B.area;
}

int n;
int main(){
    while( scanf("%d",&n) == 1 ){
        vector<nodo>v;
        int a , b , c , d;
        for(int i = 0 ; i < n ; i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            v.push_back( nodo( a , b , c , d ) );
        }
        int res = 0;
        sort(v.begin() , v.end() );
        bool m[100000];
        memset( m , 0 , sizeof(m) );
        for(int i = v.size() - 1 ; i >= 0 ; i--){
            for(int j = v.size() - 1 ; j >= 0  ;  j--)if(!m[j]){
                if( j == i || v[i].area < v[j].area ) continue;
                if( v[i].x1 <= v[j].x1 && v[j].x2 <= v[i].x2 && v[j].y1 >= v[i].y1 && v[j].y2 <= v[i].y2 ) m[j] = 1;
            }
        }
        for(int i = 0 ; i < n ; i++) if( m[i] ) res++;
        printf("%d\n",res);
    }
}
