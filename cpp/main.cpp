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

  


   valder a,v,h,rad,tana,vhor,f,v_2,v_1,v0,v1,v2,v3,v4,v5,
      v6,v7,v8,v9,v10,v11,v12,v13,b;
   double der1[] = {1,0,0};
   double der2[] = {0,1,0};
   double der3[] = {0,0,1};

   a.val = 20;
   a.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );
//u.der[0] =1;
//w = sin(v);
   v.val = 44;
   v.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

   h.val = 9;
   h.der = vector<double>(der3, der3 + sizeof(der3) / sizeof(der3[0]) );
   a.val = a.val*3.1416/180;
   //tana = tan(rad);
   //vhor = (v*cos(rad))^2;
   //f = (vhor/32)*(tana + sqrt((tana^2)+64*w/vhor));
   // f = (u^2)+(v^2)+(w^2);
   v_2 = a;
   v_1 = v;
   v0 = h;

   v1 =pow( v_1,2);
   cout << "Derivative: "<<v1.der[0]<<endl;
   v2 = cos(v_2);
   cout << "Derivative: "<<v2.der[0]<<endl;
   v3 = pow(v2,2);
   cout << "Derivative: "<<v3.der[0]<<endl;
   v4 = v1*v3;
   cout << "Derivative: "<<v4.der[0]<<endl;
   v5 = v4/32;
   cout << "Derivative: "<<v5.der[0]<<endl;
   v6 = tan(v_2);
   cout << "Derivative: "<<v6.der[0]<<endl;
   v7 = pow(v6,2);
   cout << "Derivative: "<<v7.der[0]<<endl;
   v8 = 64*v0;
   cout << "Derivative: "<<v8.der[0]<<endl;
   v9 = v8/v4;
   cout << "Derivative: "<<v9.der[0]<<endl;
   v10 = v7 + v9;
   cout << "Derivative: "<<v10.der[0]<<endl;
   v11 = sqrt(v10);
   cout << "Derivative: "<<v11.der[0]<<endl;
   v12 = v6 + v11;
   cout << "Derivative: "<<v12.der[0]<<endl;
   v13 = v5*v12;
   cout << "Derivative: "<<v13.der[0]<<endl;
   cout <<"F val: "<< v13.val <<" U der: "<< v13.der[0]<<" V der: "<<v13.der[1] << " W der: "<< v13.der[2] <<endl;
   
  
    return 0;
}
