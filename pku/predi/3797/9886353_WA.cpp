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


//F(n) = F(n-1) + 5*F(n-2) + F(n-3) - F(n-4)
int F[100];

int main(){
    F[1] = 1;
    F[2] = 5;
    F[3] = 11;
    F[4] = 36;
    for(int i = 5 ; i <= 24 ; i++) F[i] = F[i-1] + 5*F[i-2] + F[i-3] - F[i-4];
    int n,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        printf("%d\n",F[x]);
    }
}