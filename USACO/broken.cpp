/*
ID: maycolg
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
 
using namespace std;
 
int main() {
 ofstream fout ("beads.out");
 ifstream fin ("beads.in");
 int N;
 fin >> N;
 string beads;
 fin >> beads;
  
 if(beads.length() != N)
  N = beads.length();
  
 int cur = 0, max = 0;
 char color;
 bool switched;
  
 for(int i = 0; i < N; ++i){
  cur = 0;
  switched = false;
  color = 'w';
  for(int j = 0; j < N; ++j){
   const char cur_c = beads[(i + j) % N];
   if(cur_c != 'w'){
    if(color == 'w'){
     color = cur_c;
    }
    else if(color != cur_c){
     if(switched)
      break;
     else{
      color = cur_c;
      switched = true;
     }
    }
   }
   ++cur;
  }
  if(cur > max)
   max = cur;
 }
  
 fout << max << endl;
 return 0;
}
