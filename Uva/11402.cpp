#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cctype>
 
#define N 1024005
 
using namespace std;
 
int n , u , v ;
int tree[4*N] , flag[4*N];
string A;
 
int g(int x,int y){
      if( x == 0 ) return y;
      if( y <= 2 ) return y;
      if( x == 3 )
            return 0;
    if( x == 2 )
            return 1;
        return 2;            
}
 
void push( int node , int a , int b )
{
    int v1 = 2*node + 1 , v2 = 2*node + 2;
        if( flag[node] )
        {
            int r = flag[node];
                if( a == b )
                {     
                        if( r == 3 ) tree[ node ] = 1^tree[ node ];
                        else if( r == 2 ) tree[ node ] = 1;
                        else tree[node] = 0;
                }
                else
                {     
                  if( r == 3 ){
                        tree[ node ] = ( b - a  + 1 ) - tree[ node ];
                        flag[ v1 ] = g( flag[v1] , r );
                        flag[ v2 ] = g( flag[v2] , r ); 
                  }
                  else if( r == 2 ){
                        tree[ node ] = ( b - a  + 1 );
                        flag[ v1 ] = g( flag[v1] , r );
                        flag[ v2 ] = g( flag[v2] , r );
                  }
                  else{
                        tree[node] = 0;
                        flag[ v1 ] = g( flag[v1] , r );
                        flag[ v2 ] = g( flag[v2] , r );
                  }
                        
                }       
        }       
        flag[ node ] = 0;
}
 
 
void build(int node, int a , int b ){
       flag[node] = 0;
      if( a == b ){
            tree[node] = A[a] - '0';
            return;
      }
      int v1 = 2 * node + 1 , v2 = 2 * node + 2 , mid = (a+b)/2;
      build( v1 , a , mid );
      build( v2 , mid + 1 , b );
      tree[node] = tree[v1] + tree[v2];
}
 
void update( int node, int a , int b , int x , int y , int option )
{
        push( node , a , b );
        if( x > b || a > y )return;
        if( a >= x && y >= b )
        {
                flag[ node ] = option;
                push( node , a , b );
                return;
        }
        int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/ 2;
        update( v1 , a , med , x , y , option );
        update( v2 , med + 1 , b , x , y , option );
        tree[ node ] = tree[ v1 ] + tree[ v2 ];         
}
int query( int node , int a , int b , int x , int y )
{
        push( node , a , b );
        if( x > b || a > y )return 0;
        if( a >= x && y >= b )
                return tree[ node ];
        int v1 = 2*node + 1 , v2 = 2*node + 2 , med = ( a + b )/ 2;             
        return query( v1 , a , med , x , y ) + query( v2 , med + 1 , b , x , y );
}
int main()
{     
      int tc , test = 1 , q;
      scanf("%d",&tc);
        while( tc-- )
        {              
            printf("Case %d:\n",test++);
            int k , z;
            string s;
                A.clear();
            scanf("%d",&k);
            for(int i = 0 ; i < k ; i++){
                  scanf("%d",&z);
                  cin >> s;
                  while(z--) A += s;
            }
            n = A.size();
            build( 0 , 0 , n - 1);
            scanf("%d",&q);
            string op;
            k = 1;
            for(int i = 1 ; i <= q ; i++){
                  cin >>op;
                  scanf("%d%d",&u,&v);
                  if( op[0] == 'F' )
                  update(0 , 0 , n - 1 , u , v , 2 );
                  else if( op[0] == 'E' )
                  update( 0 , 0 , n - 1 , u , v , 1 );
                  else if( op[0] == 'I' )
                  update( 0 , 0 , n - 1 , u , v , 3 );
                  else printf("Q%d: %d\n",k++, query( 0 , 0 , n - 1 , u , v ));
                }
        }
}
