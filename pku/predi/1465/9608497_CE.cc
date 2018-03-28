#include<cstdio>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int n,m;
vector<int>v;
bool vis[5000];

struct nodo{
   int  x;
   string d;
   nodo(int a,string b){
      x=a,d=b;   
   }
};



string bfs(int  source){
   deque<nodo>Q(1,nodo(source,""));
   while(!Q.empty()){
      nodo q=Q.front();
      if(q.x==0 && q.d!="" && q.d[0]!='0')return q.d;
      Q.pop_front();
      for(int i=0;i<m;++i){
         string s=q.d;
         s+=(v[i]+'0');
         int p=(q.x*10+v[i])%n;
         if(vis[p]==0){
            Q.push_back(nodo(p,s));
         }
         if(s[0]!='0')vis[p]=1;
       
      }   
   }
   return "0";

}

bool valida(int x){
   if(x==1 ||x==3 ||x==7 ||x==9)return 1;
   if(x==0){
      for(int i=0;i<v.size();++i){
         if(v[i]==0)return 1;
      }
      return 0;
   } 
   if(x==5){
      for(int i=0;i<v.size();++i){
         if(v[i]==0 || v[i]==5)return 1;
      }
      return 0;
   }
   if(x%2==0){
      for(int i=0;i<v.size();++i){
         if(v[i]==0 || v[i]==2 || v[i]==4|| v[i]==6|| v[i]==8)return 1;
      }
      return 0;
   }  
}


int main(){
   while(scanf("%d%d",&n,&m)==2){
      int x;
      v.clear();
      memset(vis,0,sizeof(vis));
      for(int i=0;i<m;++i){
         scanf("%d",&x);
         v.push_back(x);
      }
      if(n==0){printf("0\n");continue;}
      if(!valida(n%10)){printf("0\n");continue;}
      sort(v.begin(),v.end());
      printf("%s\n",bfs(0).c_str());
   }

}
