#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int p[100005] , n , m;

void makeset(int NN){
   for(int i = 0 ; i < NN ; i++) p[i] = i;
}

int FIND(int x){
   if( x != p[x] ) x = FIND( p[x] );
   return x;
}

void UNION(int x,int y){
   x = FIND(x);
   y = FIND(y);
   p[x] = y;
}

void doit(){
   int x , y;
   char l;
   scanf("%d %d\n",&n,&m);
   makeset( 2*n );
   for(int i = 0 ; i < m ; i++){
      scanf("%c %d %d\n",&l,&x,&y);
      x--, y--;
      if( l == 'A' ){
         int a = FIND(x) , b = FIND(y);
         if( a == b ) puts("In the same gang.");
         else if( b == FIND(x+n) ) puts("In different gangs.");
         else puts("Not sure yet.");
      }
      else{
         UNION( x , y+n ) , UNION( x+n , y );
      }
   }
}

int main(){
   int t;
   scanf("%d",&t);
   for(int i = 0 ; i < t ; i++){
      doit();
   }
}
