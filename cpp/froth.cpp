//froth.cpp

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



      	valder v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,v11,v12,f1,f2;
      	double der1[] = {1,0};
      	double der2[] = {0,1};
      
      	v1.val = x1;
      	v1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

	v2.val = x2;
      	v2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

	v3 = 5-v2;
	v4 = v3*v2;
	v5 = v4-2;
	v6 = v5*v2;
	v7 = v1+v6;
	f1 = -13+v7;
	v8 = v2+1;
	v9 = v8*v2;
	v10 = v9-14;	
	v11 = v10*v2;
	v12 = v1+v11;
	f2 = -29+v12;
   
      	cout<<"F :"<<endl << f1.val<<" "<<f2.val<<endl;
      	cout<<"J: "<<endl;
      	for(int i=0; i<f1.der.size(); i++ )
		cout<<setw(10) << left<<f1.der[i]<<" ";
      	cout<< endl;
      	for(int i=0; i<f2.der.size(); i++ )
		cout<<setw(10) << left<<f2.der[i]<<" ";
      	cout<< endl;
  
    	return 0;
}
