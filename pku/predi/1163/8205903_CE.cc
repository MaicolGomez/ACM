#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>


using namespace std;
int t[25*13+1], n;
vector<int>v;

int f(int pos,int fil){
   if(fil==n+1)return 0;
   int &ret=t[pos];
   if(ret!=-1)return ret;
   ret=v[pos]+max(f(pos+fil,fil+1),f(pos+fil+1,fil+1));
   return ret;
}

int main(){
   int x;
   scanf("%d",&n);
   memset(t,-1,sizeof(t));   
   for(int i=0;i<((n*(n+1))/2);++i){
      scanf("%d",&x);
      v.push_back(x);
   }
   printf("%d\n",f(0,1));
}
