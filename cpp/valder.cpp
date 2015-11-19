//File name valder.cpp

#include <iostream>
#include <iomanip>
#include <vector>
#include "valder.h"
using namespace std;

/*int valder::add(vector<double> a,vector<double> b)
{

   cout<< "Whazzaaaapp"<<endl;
   return 2;
   }*/

   valder operator+(valder u, valder v)
   {
      valder w;
      w.val = u.val + v.val;
      w.der[0] = u.der[0];
      return w;
   }


   valder operator+(valder u, double v)
   {
      valder w;
      w.val = u.val + v;
      //w.der = u.der;
      
      return w;
   }

   valder operator+(double u,valder v)
   {
      valder w;
      w.val = u + v.val;
      //w.der = v.der;
      return w;
   }
/*
   valder operator+(double u, valder v)
   {
      valder w;
      w.val = u.val + v.val;
      cout<<"Hola"<<endl;
      return w;
   }
*/
/*bool Time :: equals(const Time &otherTime)
{
if(hour == otherTime.hour
&& minute == otherTime.minute
&& second == otherTime.second)
return true;
else
return false;
}*/
