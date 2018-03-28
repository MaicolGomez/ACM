#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

struct point{
    int x , y , z;
        point(int X, int Y , int Z){
            x = X, y = Y, z = Z;
        }
};
vector<point> v;

int dis(int x , int y , int z){
    return x*x+y*y+z*z;
}

point busca(int a ,int b , int c){
    int mini = 100000000;
    point res = point(0,0,0);
    for(int i = 0 ; i < 16 ; i++){
        int t = dis(a-v[i].x,b-v[i].y,c-v[i].z);
        if( t < mini ){ res = v[i]; mini = t; }
    }
    return res;
}

int main(){   
    int a , b, c;
    for(int i = 0 ; i < 16 ; i++){
        scanf("%d%d%d",&a,&b,&c);
        v.push_back( point(a,b,c) );
    }
    while( scanf("%d%d%d",&a,&b,&c) == 3 ){
        if(a == -1 && b == -1 && c == -1) break;
        point mini = busca( a,b,c );
        printf("(%d,%d,%d) maps to (%d,%d,%d)\n",a,b,c,mini.x,mini.y,mini.z);
    }
}
