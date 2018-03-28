#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int f( double x1 , double y2 ){
    if( x1*x1 + y2*y2 <= 9.00 ) return 100;
    if( x1*x1 + y2*y2 <= 36.00 ) return 80;
    if( x1*x1 + y2*y2 <= 81.00 ) return 60;
    if( x1*x1 + y2*y2 <= 144.00 ) return 40;
    if( x1*x1 + y2*y2 <= 225.00 ) return 20;
    return 0;
}

int main(){
    while( 1 ){
        double a , b;
        vector<double> x , y;
        for(int i = 0 ; i < 6 ; i++){
            cin >> a >> b;
            x.push_back(a), y.push_back(b);
        }
        if(x[0] == -100.0) break;
        int p1 = 0; for( int i = 0 ; i < 3 ; i++) p1 += f( x[i] , y[i] );
        int p2 = 0; for( int i = 3 ; i < 6 ; i++) p2 += f( x[i] , y[i] );
        printf("SCORE: %d to %d, ",p1,p2);
        if( p1 == p2 ) puts("TIE.");
            else if( p1 > p2 ) puts("PLAYER 1 WINS.");
                else puts("PLAYER 2 WINS.");
    }
}
