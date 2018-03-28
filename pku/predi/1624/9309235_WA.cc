#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

struct point{
    double x,y;
    point(double X,double Y){
        x = X;
        y = Y;
    }
    point(){};
};
point v[10];

point medio(point A , point B){
    return point( (A.x+B.x)/2 , (A.y+B.y)/2 );
}
double area;
double f( vector<point> &h ){
    double res = 0.0;
    int n = (int)h.size();
    for(int i = 0 ; i < n ; i++){
        res += ( h[i].x*h[(i+1)%n].y - h[(i+1)%n].x*h[i].y );
    }
    return fabs( res/2.0 );
}
int test=0;
void doit(){
    for(int i = 1 ; i < 9 ; i+=2) v[i] = medio( v[i-1] , v[(i+1)%8] );
    double ans = 10000000000.00;
    double a = -1.0 , b = -1.0;
    for(int i = 0 ; i < 8 ; i+=2){
        for(int j = i+3; j < i+6 ; j++){
            int k = j%8;
            vector<point> p;
            p.push_back(v[i]);
            p.push_back(v[(i+2)%8]);
            if( j > i+4 ) p.push_back( v[(i+4)%8] );
            p.push_back( v[k] );
            double r = f( p );
            if( fabs(area - 2*r) < ans ){
                ans = fabs(area - 2*r);
                a = (area - r);
                b = r;
            }
        }
    }
    for(int i = 1 ; i < 9 ; i+=2){
        for(int j = i+2; j <= i+6 ; j++){
            int k = j%8;
            vector<point> p;
            p.push_back(v[i]);
            p.push_back(v[(i+1)%8]);
            if( j > i+3 ) p.push_back( v[(i+3)%8] );
            if( j > i+5 ) p.push_back( v[(i+5)%8] );
            p.push_back( v[k] );
            double r = f( p );
            if( fabs(area - 2*r) < ans ){
                ans = fabs(area - 2*r);
                a = area - r;
                b = r;
            }
        }
    }
    if(a>b) swap(a,b);
    printf("Cake %d: ",++test);
    printf("%.3lf %.3lf\n",a,b);
}

int main(){
    while(1){
        bool ok = 1;
        vector<point> p;
        for(int i = 0 ; i < 8 ; i+=2){
            scanf("%lf%lf",&v[i].x,&v[i].y);
            p.push_back(v[i]);
            if( v[i].x == 0.0 && v[i].y == 0.0 ) continue;
            ok = 0;
        }
        if(ok) break;
        area = f(p);
        doit();
    }
}
