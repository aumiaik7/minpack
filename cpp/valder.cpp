//File name valder.cpp

#include <iostream>
#include <iomanip>
#include <vector>
#include "valder.h"
using namespace std;
#include<cmath>

/*int valder::add(vector<double> a,vector<double> b)
{

   cout<< "Whazzaaaapp"<<endl;
   return 2;
   }*/

// + overload when both of them are valder objet
valder operator+(valder u, valder v)
{

  valder w;
  w.val = u.val + v.val;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
      w.der[i] = u.der[i] + v.der[i];
  }
      

  return w;
}

// + overload when v is scalar
valder operator+(valder u, double v)
{
  valder w;
  w.val = u.val + v;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
    w.der[i] = u.der[i] ;

  }

  //w.der = u.der;
  return w;
}

// + overload when u is scalar
valder operator+(double u,valder v)
{
  valder w;
  w.val = u + v.val;
  w.der = vector<double>(v.der.size());
  for(int i = 0; i < v.der.size(); i++)
  {	
    w.der[i] = v.der[i] ;
  }
      //w.der = v.der;
  return w;
}

// unary minus overload
valder operator-(valder u)
{
  valder w;
  w.val = -u.val;
  w.der = vector<double>(u.der.size());
  for(int i = 0; i < u.der.size(); i++)
  {	
    w.der[i] = -u.der[i] ;
  }
      //w.der = v.der;
  return w;
  
}

// - overload when both of them are valder objet
valder operator-(valder u, valder v)
{

  valder w;
  w.val = u.val - v.val;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
      w.der[i] = u.der[i] - v.der[i];
  }
      

  return w;
}

// - overload when v is scalar
valder operator-(valder u, double v)
{
  valder w;
  w.val = u.val - v;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
    w.der[i] = u.der[i] ;

  }

  //w.der = u.der;
  return w;
}

// - overload when u is scalar
valder operator-(double u,valder v)
{
  valder w;
  w.val = u - v.val;
  w.der = vector<double>(v.der.size());
  for(int i = 0; i < v.der.size(); i++)
  {	
    w.der[i] = -v.der[i] ;
  }
      //w.der = v.der;
  return w;
}


valder sin(valder u)
{
  valder w;

  cout <<sin(2)<<endl;

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
