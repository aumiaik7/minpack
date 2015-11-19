#include <iostream>
#include <vector>
using namespace std;
#include "valder.h"


int main()
{
  /*Time t1(10, 50, 59);
     t1.print();   // 10:50:59
     Time t2;
     t2.print(); // 06:39:09
     t2.setTime(6, 39, 9);
     t2.print();  // 06:39:09
   
     if(t1.equals(t2))
          cout << "Two objects are equal\n";
     else
     cout << "Two objects are not equal\n";*/

  


   valder u,v,w,x;
   double der1[] = {1,0,0};
   double der2[] = {0,1,0};
   double der3[] = {0,0,1};

   u.val = 20;
   u.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );
//u.der[0] =1;
//w = sin(v);
   v.val = 10;
   v.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );
   x = 20 + u;
w = v-u;
   cout <<"U der: "<< w.der[0]<<" V der: "<<w.der[1] <<endl;
   
  
    return 0;
}
