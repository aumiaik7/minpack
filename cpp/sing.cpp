//sing.cpp

/*
% *******************************************
% *******************************************
% Powell singular function  [13]
% Dimensions:    n=4    m=4
% Function definitions:
%       f1(x)=x1 + 10x2      
%       f2(x)= 5^.5*(x3 - x4)
%       f3(x)= (x2-2x3)^2
%       f4(x)= 10^.5*(x1-x4)^2
% *********************************************

*/

#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;

void display(valder f);

int main()
{
	  
	double x1,x2,x3,x4;
	
	
	
	cout<<"Enter values for x1 x2 x3 and x4:";
      	cin >> x1 >> x2 >> x3 >> x4;



      	valder a1,a2,a3,a4,v1,v2,v4,v5,v6,v7,f1,f2,f3,f4;
	int vali;
      	double der1[] = {1,0,0,0};
      	double der2[] = {0,1,0,0};
	double der3[] = {0,0,1,0};
      	double der4[] = {0,0,0,1};

	a1.val = x1;
      	a1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

      	a2.val = x2;
      	a2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

	a3.val = x3;
      	a3.der = vector<double>(der3, der3 + sizeof(der3) / sizeof(der3[0]) );

	a4.val = x4;
      	a4.der = vector<double>(der4, der4 + sizeof(der4) / sizeof(der4[0]) );

	double v3,v8,v10;
	
	v1 = 10*a2;
	f1 = a1+v1;
	v2 = a3-a4;
	v3 = sqrt(5);
	f2 = v3*v2;
	v4 = 2*a3;
	v5 = a2-v4;
	f3 = pow(v5,2);
	v6 = a1-a4;
	v7 = pow(v6,2);
	v8 = sqrt(10);
	f4 = v8*v7;
	
 	cout<<"F :"<<endl << f1.val<<endl <<f2.val<<endl <<f3.val<<endl<<f4.val<<endl;
      	cout<<"J: "<<endl;
      	
	display(f1);
	display(f2);
	display(f3);
	display(f4);
	
    	return 0;
}

void display(valder f)
{
	for(int i=0; i<f.der.size(); i++ )
		cout<<setw(10) << left<<f.der[i]<<" ";
      	cout<< endl;
}
