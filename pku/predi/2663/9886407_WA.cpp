#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<deque>
#include<map>
#include<string>
#include<sstream>
using namespace std;
#define inf (1<<30)
#define eps 1e-8
#define ll long long
#define vi vector<int> 
#define all(v) v.begin() , v.end()


//F(n)=4F(n-2)-F(n-4);
int F[31];

int main(){
    F[2] = 3;
    F[4] = 11;
    for(int i = 6 ; i <= 30 ; i++) F[i] = 4*F[i-2] - F[i-4];
    int n;
    while( scanf("%d",&n) && n != -1 ){
        printf("%d\n",F[n]);
    }
}