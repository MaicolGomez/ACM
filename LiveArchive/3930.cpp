#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

#define N 1600000
#define inf 10000000

int a[2][15] , t[N];
map< vector<int> ,int> M;

int f( vector<int> v ){
    
    /*int hash = 0 , pot = 1;
    for(int i = 1 ; i <= 13 ; i++)
            hash = hash + pot * v[i] , pot *= 3;
    */
    if( M.find(v) != M.end() ) return M[v];
    int ret = 0;
    for(int i = 1 ; i <= 13 ; i++)if( v[i] > 0 )
            for(int j = i + 1 ; j <= 13 ; j++)if( v[j] > 0 )
                    for(int k = j + 1 ; k <= 13 ; k++)if( v[k] > 0 ){
                            if( k < i + j ){
                                v[ i ]-- , v[ j ]-- , v[ k ]--;
                                ret = max( ret , 1 + f( v ) );
                                v[ i ]++ , v[ j ]++ , v[ k ]++;
                            }
                    }
                    
    for(int i = 1 ; i <= 13 ; i++)if( v[i] == 2 )
            for(int j = i + 1 ; j <= 13 ; j++)if( v[j] > 0 ){
                            if( j < i + i ){
                                v[ i ]-- , v[ i ]-- , v[ j ]--;
                                ret = max( ret , 1 + f( v ) );
                                v[ i ]++ , v[ i ]++ , v[ j ]++;
                            }
            }
    
    for(int i = 1 ; i <= 13 ; i++)if( v[i] > 0 )
            for(int j = i + 1 ; j <= 13 ; j++)if( v[j] == 2 ){
                            if( j < i + j ){
                                v[ i ]-- , v[ j ]-- , v[ j ]--;
                                ret = max( ret , 1 + f( v ) );
                                v[ i ]++ , v[ j ]++ , v[ j ]++;
                            }
            }
    
    
    return M[v] = ret;
}

int main(){
    int n;
    while( scanf("%d",&n) == 1 && n != 0 ){
           int x;
           
            for(int i = 0 ; i < 2 ; i++)
                memset( a[i] , 0 , sizeof(a[i]) );
           
           for(int i = 0 ; i < n ; i++){
                 scanf("%d",&x); 
                 a[ (i%2 == 0)?0:1 ][x]++;
           }
           int A = 0 , B = 0;
           for(int i = 1 ; i <= 13 ; i++){
                   A += a[0][i]/3 , a[0][i] = a[0][i]%3;
                   B += a[1][i]/3 , a[1][i] = a[1][i]%3;
           }
           if( A > B ) printf("1\n");
           else if( B > A ) printf("2\n");
           else{
                vector<int> v(14,0);
                
                for(int i = 1 ; i <= 13 ; i++)
                        v[i] = a[0][i];
                
                A = f( v );
                vector<int> v1(14,0);
                for(int i = 1 ; i <= 13 ; i++)
                        v1[i] = a[1][i];

                
                B = f( v1 );
                if( A > B ) printf("1\n");
                else if( B > A ) printf("2\n");
                else printf("0\n");
           }
    }
}
