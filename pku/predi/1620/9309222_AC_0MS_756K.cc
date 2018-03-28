#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
int n;
double x[12], y[12];
vector<int> adj[12];
bool dis(double a,double b){
    double r = a*a + b*b ;
    return (r-400.0)<eps;
}
int colores,color[12];
bool ok = 0;
int test = 0;

void f(int pos){
    if(pos==n){ ok=1; return; }
    for(int i = 1 ; i <= colores ; i++){
        int j;
        for(j = 0 ; j < adj[pos].size() ; j++){
            if( color[ adj[pos][j] ] == i ) break;
        }
        if(j==adj[pos].size()){
            color[pos] = i;
            f(pos+1);
            color[pos] = 0;
        }
    }
}

void doit(){
    for(int i = 0 ; i < 12 ; i++) adj[i].clear();
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)if(i!=j){
            bool r = dis( x[i]-x[j] , y[i]-y[j] );
            if(r) adj[i].push_back(j);
        }
    }
    for(colores = 1 ; colores <= 3 ; colores++){
        ok = 0;
        f(0);
        if(ok){ printf("The towers in case %d can be covered in %d frequencies.\n",++test,colores); return; }
    }
    printf("The towers in case %d can be covered in 4 frequencies.\n",++test);
}

int main(){
    while( scanf("%d",&n) == 1 && n ){
        for(int i = 0 ; i < n ; i++) cin >> x[i] >> y[i];
        doit();
    }
}
