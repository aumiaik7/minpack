//beale.cpp

#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;



int main()
{
  
	double x1,x2;
	cout<<"Enter values for x1 and x2:";

      	cin >> x1 >> x2;



      	valder v1,v2,v3,v4,v5,v6,v7,v8,v9,v10,f1,f2,f3;
      	double der1[] = {1,0};
      	double der2[] = {0,1};
      
      	v1.val = x1;
      	v1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

	v2.val = x2;
      	v2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

	v3 = 1-v2;
	v4 = v1*v3;
	f1 = 1.5-v4;
	v5 = pow(v2,2);
	v6 = 1-v5;
	v7 = v1*v6;
	f2 = 2.25-v7;
	v8 = v2*v5;
	v9 = 1-v8;
	v10 = v1*v9;
	f3 = 2.625-v10;
   
      	cout<<"F :"<<endl << f1.val<<" "<<f2.val<<" "<<f3.val<<endl;
      	cout<<"J: "<<endl;
      	for(int i=0; i<f1.der.size(); i++ )
		cout<<setw(15) << left<<f1.der[i]<<" ";
      	cout<< endl;
      	for(int i=0; i<f2.der.size(); i++ )
		cout<<setw(15) << left<<f2.der[i]<<" ";
      	cout<< endl;
	for(int i=0; i<f3.der.size(); i++ )
		cout<<setw(15) << left<<f3.der[i]<<" ";
      	cout<< endl;
  
    	return 0;
}
