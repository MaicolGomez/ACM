#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
using namespace std;
#define ll long long
#define all(v) v.begin() , v.end()
#define N 100000
#define mod 1000000007LL
#define MAXN 100005

int n, t;
string s;

string rotacion(){
      int mini = 0, p = 1, l = 0;
      while(p < n && mini + l + 1< n)
         if(s[mini + l] == s[p + l])
            l++;
         else if(s[mini + l] < s[p + l]){
            p = p + l + 1;
            l = 0;
         }else if(s[mini + l] > s[p + l]){
            mini = max(mini + l + 1, p);
            p = mini + 1;
            l = 0;
         }
      string ans = "";
      for(int i = mini ; i < mini + n ; i++) ans += s[i];
      return ans;
}

void doit(){
    cin >> s;
    n = s.length();
    s += s;
    printf("%s\n",rotacion().c_str());
}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int i = 0 ; i < tc ; i++){
        doit();
    }
}
