#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int y,n;
   double i,m;
   while(cin>>y && y)
   {
      n = 4<<((int(y)-1960)/10);
      m = 0;
      for(i = 1; ; i++)
      {
         m += log(i)/log(2.0);
         if(m > n)break;
      }
      cout<<i-1<<endl;
   }
   return 0;
}

