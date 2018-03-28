#include<iostream>
#include<sstream>
#include<cmath>
#include<cstdio>
#include<deque>
#include<algorithm>
#include<cstdio>
using namespace std;
char m[102][102];
char p;

int main(){
 int n; string s;
 cin>>n;   
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){     
     cin>>m[i][j];    
   }
 }
 while(cin>>s){
  bool esta=false;      
  if(s=="0") break;
     p=s[0];
     for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){     
       if(p==m[i][j]){ int posi=i;int posf=j,pos1,pos2;
           //horizontal
           string s3;
           for(int k=j;k<n;k++){
               s3+=m[i][k];
               if(s==s3){ esta=true;pos1=i; pos2=k; i=n;j=n;  break; } 
           } 
            s3="";            
           for(int k=j;k>=0;k--){
               s3+=m[i][k];
               if(s==s3){esta=true;pos1=i; pos2=k; i=n;j=n; break; } 
           } 
            s3="";
           if(esta==true){cout<<posi+1<<","<<posf+1<<" "<<pos1+1<<","<<pos2+1<<endl; break;}              
            //vertical
           if(esta==false){ 
           for(int k=i;k<n;k++){
               s3+=m[k][j];
               if(s==s3){ esta=true;pos1=k; pos2=j;i=n;j=n;  break; } 
           } 
            s3="";            
           for(int k=i;k>=0;k--){
               s3+=m[k][j];
               if(s==s3){esta=true; pos1 = k; pos2 = j ; i=n;j=n;  break; } 
           } 
            s3="";                                                     
           if(esta==true){cout<<posi+1<<","<<posf+1<<" "<<pos1+1<<","<<pos2+1<<endl;break; }   
          }  
          //diagonal1
           if(esta==false){ 
           for(int k=0;k<s.length();k++){  
                if(i+k>n||j+k>n)break;              
                s3+=m[i+k][j+k];        
                if(s==s3){ esta=true;pos1=i+k; pos2=j+k; i=n;j=n;  break; }   
           } 
            s3="";            
           for(int k=0;k<s.length();k++){  
                if(i-k<0||j-k<0)break;                   
                s3+=m[i-k][j-k];        
                if(s==s3){ esta=true;pos1=i-k; pos2=j-k; i=n;j=n;  break; } 
           } 
            s3="";                                                     
           if(esta==true){cout<<posi+1<<","<<posf+1<<" "<<pos1+1<<","<<pos2+1<<endl; break; }
           //diagonal2
           for(int k=0;k<s.length();k++){  
                if(i+k>n||j-k>n)break;              
                s3+=m[i+k][j-k];        
                if(s==s3){ esta=true;pos1=i+k; pos2=j-k; i=n;j=n;  break; }   
           } 
            s3="";            
           for(int k=0;k<s.length();k++){  
                if(i-k<0||j+k<0)break;                   
                s3+=m[i-k][j+k];        
                if(s==s3){ esta=true;pos1=i-k; pos2=j+k; i=n;j=n;  break; } 
           } 
            s3="";                                                     
           if(esta==true){cout<<posi+1<<","<<posf+1<<" "<<pos1+1<<","<<pos2+1<<endl; break; }           
          }                               
        }           
      }
     }  
     if(esta==false)   cout<<"Not found"<<endl;                     
 }       
}
