/*
ID: maycolg1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int daysinmonth(int month, int year){
 if(month == 1)
  return ((year % 4) || (!(year % 100) && ((year+300) % 400))) ? 28 : 29;
 switch(month){
  case 8:
  case 3:
  case 5:
  case 10:
   return 30;
   // break;
  default:
   return 31;
   // break;
 }
}
 
int main() {
 ofstream fout ("friday.out");
 ifstream fin ("friday.in");
  
 // sanitize input
 int N;
 fin >> N;
 if(N < 0) N = 0;
 if(N > 400) N = 400;
  
 int result[7] = {0};
  
 int dow = 0, month = 0;
 for(int i = 0; i < N; ++i)
  for(int m = 0; m < 12; ++m){
   ++result[((dow + 6) % 7)];
   dow = (dow + daysinmonth(m, i)) % 7;
  }
  
 // output!
 for(int i = 0; i < 7; ++i){
  fout << result[(i + 6) % 7];
  if(i == 6) fout << endl;
  else fout << " ";
 }
 return 0;
}
