#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<cstdlib>
#include<string> 
#include<cctype>
using namespace std;

int main(){
 int n,k;
 while(scanf("%d",&n)==1){
  if(n==0)break;
  bool a=true;
  int i=1,num;
  while(a){
    int p;
    p=i*(i+1);
    p/=2;
    if(p>n){num=i-1; k=num;a=false; }
    i++;
  }
  int total;
  total=num*(num+1)*(2*num+1);
  total/=6;
  num=num*(num+1);
  num/=2;
  int r=(n-num)*(k+1);
  total+=r; 
  printf("%d %d\n",n,total);
  
 }
}