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

   u.val = 20;
   u.der = {1,0,0};
   v.val = 10;
   // v.der = {0,1,0};
   w = u+v;
   cout << w.der[0] <<endl;
   
  
    return 0;
}
