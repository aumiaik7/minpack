//rosen.cpp

#include <iostream>
#include <vector>
#include <iomanip> 
#include "valder.h"
using namespace std;



int main()
{
  
      double x1,x2;
      cout<<"Enter values for x1 and x2:";

      cin >> x1 >> x2;



      valder v1,v2,v3,v4,f1,f2;
      double der1[] = {1,0};
      double der2[] = {0,1};
      
      v1.val = x1;
      v1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

      v2.val = x2;
      v2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

      v3 = v1^2;
      v4 = v2-v3;
      f1 = 10*v4;
      f2 = 1-v1;
   
      cout<<"F :"<<endl << f1.val<<" "<<f2.val<<endl;
      cout<<"J: "<<endl;
      for(int i=0; i<f1.der.size(); i++ )
	cout<<setw(15) << left<<f1.der[i]<<" ";
      cout<< endl;
      for(int i=0; i<f2.der.size(); i++ )
	cout<<setw(15) << left<<f2.der[i]<<" ";
      cout<< endl;
  
    return 0;
}
