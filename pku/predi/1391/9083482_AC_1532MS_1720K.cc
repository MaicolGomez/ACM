#include<deque>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<map>
using namespace std;

vector<int> v[10000];
map<string , int > M;
int per;

void trata(string s){
   vector<int>nom;
   int ct = 0;
   string aux = "";
   for(int i = 0 ; i < s.length() ; i++){
       if( s[i] == ',' || s[i] == ':' ) ct++;
       if( ct == 2 ){
           ct = 0;
           if( M.find(aux) == M.end() ) M[aux] = per++;
           nom.push_back( M[aux]);
           aux = "";
           i++;
           if(s[i]==':')break;
       }
       else aux += s[i];
   }
   for(int i = 0 ; i < nom.size() ; i++){
       for(int j = i+1 ; j < nom.size() ; j++){
           v[ nom[i] ].push_back( nom[j] );
           v[ nom[j] ].push_back( nom[i] );
       }
   }
}

vector<int> bfs(int source){
   deque<int> Q(1 , source);
   vector<int> d(per , -1);
   if(source==-1)return d;
   d[source] = 0;
   while( !Q.empty() ){
       int q = Q.front();
       Q.pop_front();
       for(int i = 0 ; i < v[q].size() ; i++)if( d[v[q][i]] == -1 ){
           d[ v[q][i] ] = d[q]+1;
           Q.push_back( v[q][i] );
       }
   }
   return d;
}
int t = 0;
bool doit(){
    t++;
   int l , q ;
   string s;
   M.clear();
   per = 0;
   for(int i = 0; i < 10000 ; i++) v[i].clear();
   scanf("%d%d",&l,&q);
   if(l==0&&q==0) return 0;
   getline( cin , s );
   for(int i = 0 ; i < l ; i++){
       getline( cin , s );
       trata(s);
   }
   int source;
   if( M.find("Erdos, P.") == M.end() ) source = -1;
   else source = M["Erdos, P."];
   vector<int> d = bfs( source );
   printf("Database #%d\n",t);
   for(int i = 0 ; i < q ; i++){
       getline(cin,s);
       if( s == "Erdos, P." ) cout<<s<<": 0"<<endl;
       else{
           if( M.find(s) == M.end() ) cout<<s<<": infinity"<<endl;
           else{
               if( d[M[s]] == -1 ) cout<<s<<": infinity"<<endl;
               else cout<<s<<": "<<d[M[s]]<<endl;
           }
       }
   }
   puts("");
   return 1;
}

int main(){
   while(doit()){}
}
