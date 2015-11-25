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

// (+) overload when both of them are valder objet
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

// (+) overload when v is scalar
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

// (+) overload when u is scalar
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

// (-) overload when both of them are valder objet
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

// (-) overload when u is scalar
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


//  (*) overload when both of them are valder objet
valder operator*(valder u, valder v)
{

  valder w;
  w.val = u.val*v.val;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
     w.der[i] = u.der[i]*v.val + u.val*v.der[i];
  }
      

  return w;
}

// (*) overload when v is scalar
valder operator*(valder u, double v)
{
  valder w;
  w.val = v*u.val;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
    w.der[i] = v*u.der[i] ;

  }

  //w.der = u.der;
  return w;
}

// (*) overload when u is scalar
valder operator*(double u,valder v)
{
  valder w;
  w.val = u*v.val;
  w.der = vector<double>(v.der.size());
  for(int i = 0; i < v.der.size(); i++)
  {	
    w.der[i] = u*v.der[i] ;
  }
      //w.der = v.der;
  return w;
}

// (/) overload when both of them are valder objet
valder operator/(valder u, valder v)
{

  valder w;
  w.val = u.val/v.val;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
     w.der[i] = (u.der[i]*v.val-u.val*v.der[i])/pow(v.val,2);
  }
      

  return w;
}

// (/) overload when v is scalar
valder operator/(valder u, double v)
{
  valder w;
  w.val = u.val/v;
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
    w.der[i] = u.der[i]/v;

  }

  //w.der = u.der;
  return w;
}

// (/) overload when u is scalar
valder operator/(double u,valder v)
{
  valder w;
  w.val = u/v.val;
  w.der = vector<double>(v.der.size());
  for(int i = 0; i < v.der.size(); i++)
  {	
     w.der[i] = (-u*v.der[i])/pow(v.val,2) ;
  }
      //w.der = v.der;
  return w;
}

// (^) overload when both of them are valder objet
valder pow(valder u, valder v)
{

  valder w;
  //w.der = vector<double>(u.der.size());
  w = exp(v*log(u));
  
/*

  for(int i = 0; i < u.der.size(); i++)
  {	
     w.der[i] = (u.der[i]*v.val-u.val*v.der[i])/pow(v.val,2);
  }
*/    

  return w;
}

// (^) overload when v is scalar
valder pow(valder u, double v)
{
  valder w;
  w.val = pow(u.val,v);
  w.der = vector<double>(u.der.size());

  for(int i = 0; i < u.der.size(); i++)
  {	
     w.der[i] = v*pow(u.val,(v-1))*u.der[i];
  }  
  //w.der = u.der;
  return w;
}

// (^) overload when u is scalar
valder pow(double u,valder v)
{
  valder w;
  w.val = pow(u,v.val);
  w.der = vector<double>(v.der.size());
  for(int i = 0; i < v.der.size(); i++)
  {
    w.der[i] = pow(u,v.val)*log(u)*v.der[i] ;
  }
      //w.der = v.der;
  return w;
}

// (^) overload when u and v are scalar
/*double operator^(double u,double v)
{
  double w;
  w = pow(u,v);
 
  return w;
}
*/
// (log) overload
valder log(valder u)
{
   valder w;
   w.val = log(u.val);

   w.der = vector<double>(u.der.size());
   for(int i = 0; i < u.der.size(); i++)
   {
      w.der[i] = (1/u.val)*u.der[i] ;
   }

   return w;
}

// (exp) overload 
valder exp(valder u)
{
   valder w;
   w.val = exp(u.val);

   w.der = vector<double>(u.der.size());
   for(int i = 0; i < u.der.size(); i++)
   {
     w.der[i] = exp(u.val)*u.der[i] ;
   }
   
   
   return w;
}

// (sqrt) overload
valder sqrt(valder u)
{
   valder w;
   w.val = sqrt(u.val);

   w.der = vector<double>(u.der.size());
   for(int i = 0; i < u.der.size(); i++)
   {
      w.der[i] = u.der[i]/(2*sqrt(u.val)) ;
   }
   
   
   return w;
}

// (sin) overload
valder sin(valder u)
{
   valder w;
   w.val = sin(u.val);

   w.der = vector<double>(u.der.size());
   for(int i = 0; i < u.der.size(); i++)
   {
      w.der[i] = cos(u.val)*u.der[i] ;
   }

   return w;
}

// (cos) overload
valder cos(valder u)
{
   valder w;
   w.val = cos(u.val);

   w.der = vector<double>(u.der.size());
   for(int i = 0; i < u.der.size(); i++)
   {
      w.der[i] = -sin(u.val)*u.der[i] ;
      cout<<-sin(u.val)<<" "<<u.der[i]<<endl;
   }

   return w;
}

// (tan) overload
valder tan(valder u)
{
   valder w;
   w.val = tan(u.val);

   w.der = vector<double>(u.der.size());
   for(int i = 0; i < u.der.size(); i++)
   {
     w.der[i] = pow(1/ cos(u.val),2)*u.der[i] ;
   }

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
