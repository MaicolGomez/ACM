#include<iostream>
#include<sstream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstdlib>
using namespace std;

int main(){
 string s1,s2;
 int n,a=0,b=0;
 cin>>n; 
 if(n!=0)cout<<n<<endl;
 for(int i=1;i<=n;i++){
   cin>>s1>>s2>>b;
    a=atoi(s1.c_str());

    int cont=0;
    if(s2=="pop") cont=0;
    if(s2=="no") cont=20;   
    if(s2=="zip") cont=40;
    if(s2=="zotz") cont=60;
    if(s2=="tzec") cont=80;
    if(s2=="xul") cont=100;
    if(s2=="yoxkin") cont=120;
    if(s2=="mol") cont=140;
    if(s2=="chen") cont=160;
    if(s2=="yax") cont=180;
    if(s2=="zac") cont=200;
    if(s2=="ceh") cont=220;
    if(s2=="mac") cont=240;
    if(s2=="kankin") cont=260;
    if(s2=="muan") cont=280;
    if(s2=="pax") cont=300;   
    if(s2=="koyab") cont=320;
    if(s2=="cumhu") cont=340;
    if(s2=="uayet") cont=360;
  
   cont=cont+b*365+a+1;
   int res,res2,a2,res1; 
   string s;
     a2=cont/260;
     res1=(cont%260)%13;
     if(res1==0){res1=13;}
     if(cont%260!=0)
     {  if((cont%260)%20!=0)
       {res2=(cont%260)%20;}
        else{res2=0;} 
    }
     else{res2=0;a2=cont/260-1;}
     switch(res2)
   {
    case 0: s="ahau"; break;
    case 1: s="imix"; break;
    case 2: s="ik"; break;
    case 3: s="akbal"; break;
    case 4: s="kan"; break;
    case 5: s="chicchan"; break;
    case 6: s="cimi"; break;
    case 7: s="manik"; break;
    case 8: s="lamat"; break;
    case 9: s="muluk"; break;
    case 10: s="ok"; break;
    case 11: s="chuen"; break;
    case 12: s="eb"; break;
    case 13: s="ben"; break;
    case 14: s="ix"; break;
    case 15: s="mem"; break;
    case 16: s="cib"; break;
    case 17: s="caban"; break;
    case 18: s="eznab"; break; 
    case 19: s="canac"; break;  
   }  
   cout<<res1<<" "<<s<<" "<<a2<<endl; 
 }  
}    