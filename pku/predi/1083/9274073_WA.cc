#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
bool used[205];
vector<int> x , y;

bool val(vector<int> &v , vector<int> &v1 ,int pos ){
    int a = (min( x[pos] , y[pos] ) + 1)/2;
    int b = (max( x[pos] , y[pos] ) + 1)/2;
    for(int i = 0 ; i < v.size() ; i++){
        if( v[i] <= a && a <= v1[i] ) return 0;
        if( v[i] <= b && b <= v1[i] ) return 0;
    }
    return 1;
}

void doit(){
    memset(used,0,sizeof(used));
    x.clear();
    y.clear();
    scanf("%d",&n);
    int a , b;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d",&a,&b);
        x.push_back(a);
        y.push_back(b);
    }
    int cont = 0;
    while(1){
        int ini = -1;
        for(int i = 0 ; i < x.size() ; i++) if( used[i] == 0 ){ ini = i; break; }
        if( ini == -1 ) break;
        used[ini] = 1;
        cont++;
        vector<int> v , v1;
        v.push_back( (min(x[ini],y[ini])+1)/2 );
        v1.push_back( (max(x[ini],y[ini])+1)/2 );
        for(int i = ini + 1 ; i < x.size() ; i++){
            if( used[i] == 1 ) continue;
            if( val( v , v1 , i ) ){
                v.push_back(  (min(x[i],y[i])+1)/2 );
                v1.push_back( (max(x[i],y[i])+1)/2 );
                used[i] = 1;
            }
        }
    }
    printf("%d\n",cont*10);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t; i++) doit();
}
