#include<iostream>
using namespace std;
string s;

string f(int ini,int fin,char op){
   int ct1=0,ct2=0;
   for(int i=fin;i>ini;i--){
      if(s[i]=='(')ct1++;
      if(s[i]==')')ct2++;      
         if(s[i]=='+' && ct1==ct2){
            if(op=='*' || op=='/' || op=='-' || op=='d')return "("+f(ini,i-1,'+')+"+"+f(i+1,fin,'+')+")";
            return f(ini,i-1,'+')+"+"+f(i+1,fin,'+');
         }
         if(s[i]=='-' && ct1==ct2){
            if(op=='*' || op=='/' || op=='-' || op=='d')return "("+f(ini,i-1,'+')+"-"+f(i+1,fin,'-')+")";
            return f(ini,i-1,'+')+"-"+f(i+1,fin,'-');
         }
      
   }
   ct1=0,ct2=0;
   for(int i=fin;i>ini;i--){
      if(s[i]=='(')ct1++;
      if(s[i]==')')ct2++;      
         if(s[i]=='*' && ct1==ct2){
            if(op=='/')return "("+f(ini,i-1,'*')+"*"+f(i+1,fin,'*')+")";
            return f(ini,i-1,'*')+"*"+f(i+1,fin,'*');
         }
         if(s[i]=='/' && ct1==ct2){
            if(op=='/')return "("+f(ini,i-1,'d')+"/"+f(i+1,fin,'/')+")";
            return f(ini,i-1,'d')+"/"+f(i+1,fin,'/');
         }
   } 
   if(s[ini]=='(')return f(ini+1,fin-1,op);
   return s.substr(ini,fin-ini+1);
}


int main(){
   int n;
   cin>>n;
   for(int i=0;i<n;++i){
      cin>>s;
      cout<<f(0,s.length()-1,'a')<<endl;
   }   
}
