#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
bool used[205];
int cont[205];
vector<int> x , y;

/*
bool val(vector<int> &v , vector<int> &v1 ,int pos ){
    int a = (x[pos] + 1)/2;
    int b = (y[pos] + 1)/2;
    for(int i = 0 ; i < v.size() ; i++){
        if( v[i] <= a && a <= v1[i] ) return 0;
        if( v[i] <= b && b <= v1[i] ) return 0;
    }
    return 1;
}*/

void doit(){
    memset(used,0,sizeof(used));
    memset(cont,0,sizeof(cont));
    x.clear();
    y.clear();
    scanf("%d",&n);
    int a , b;
    for(int i = 0 ; i < n ; i++){
        scanf("%d%d",&a,&b);
        x.push_back(min(a,b));
        y.push_back(max(a,b));
    }
    int res = 0;
    for(int i = 0 ; i < x.size() ; i++){
        a = (x[i]+1)/2;
        b = (y[i]+1)/2;
        for(int j = a ; j <= b ; j++) cont[j]++;
    }
    for(int i = 0 ; i < 201 ; i++) res = max( res , cont[i] );
    printf("%d\n",res*10);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t; i++) doit();
}
