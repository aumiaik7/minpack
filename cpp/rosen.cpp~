//main.cpp

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

  


  valder u,v,w,rad,tana,vhor,f;
   double der1[] = {1,0,0};
   double der2[] = {0,1,0};
   double der3[] = {0,0,1};

   u.val = 20;
   u.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );
//u.der[0] =1;
//w = sin(v);
   v.val = 44;
   v.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

   w.val = 9;
   w.der = vector<double>(der3, der3 + sizeof(der3) / sizeof(der3[0]) );
   rad = u*3.1416/180;
   tana = tan(rad);
   vhor = (v*cos(rad))^2;
   f = (vhor/32)*(tana + sqrt((tana^2)+64*w/vhor));
   // f = (u^2)+(v^2)+(w^2);
   
 cout <<"F val: "<< f.val <<" U der: "<< f.der[0]<<" V der: "<<f.der[1] << " W der: "<< f.der[2] <<endl;
   
  
    return 0;
}
