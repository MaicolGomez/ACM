#include<cstdio>

#include<algorithm>

#include<cstring>

#include<iostream>

#include<vector>

#include<sstream>
#include<string>

using namespace std;

#define inf (1<<30)
#define  eps 1e-8

int dx[6] = {-1,0,1,1,0,-1};
int dy[6] = {1,1,0,-1,-1,0};
int n;
int t[200][200][16];
int f(int x, int y , int step){
    if(step == n) return (x == 100 && y == 100);
    int &ret = t[x][y][step];
    if(ret!=-1) return ret;
    ret = 0;
    for(int i = 0 ; i < 6 ; i++) ret += f(dx[i] + x , dy[i] + y , step + 1);
    return ret;
}

void doit(){
    scanf("%d",&n);
    memset(t , -1 , sizeof(t) );
    int r = 0;
    for(int i = 0 ; i < 6 ; i++) r += f(100+dx[i] , 100+dy[i] , 1);
    printf("%d\n",r);
}

int main(){
    int c;
    scanf("%d",&c);
    for(int i = 0 ; i < c ; i++) doit();
}