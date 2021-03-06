//meyer.cpp
/*
% ****************************************************
% ****************************************************
% Meyer function   [10]
% Dimensions   n=3   m=16
% Function definition:
%       f(x) = x(1)*exp[x(2)/(t(i) + x(3))]-y(i)
%       where t(i)= 45 + 5i
% Standard starting point at x=(0.02,4000,250)
% Minima of f=87.9458...
%
*/
#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;



int main()
{
	  
	double x1,x2,x3;
	
	double y[] = {34780.0,28610.0,23650.0,19630.0,16370.0,13720.0,11540.0,9744.0,8261.0,7030.0,6005.0,5147.0,4427.0,3820.0,3307.0,2872.0};
	
	int m = 16;
	cout<<"Enter values for x1 x2 and x3:";
      	cin >> x1 >> x2 >> x3;



      	valder v1,v2,v3,z1[m],z2[m],z3[m],z4[m],f[m];
	int vali;
      	double der1[] = {1,0,0};
      	double der2[] = {0,1,0};
	double der3[] = {0,0,1};
	

	v1.val = x1;
	v1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

	v2.val = x2;
      	v2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );
	
	v3.val = x3;
	v3.der = vector<double>(der3, der3 + sizeof(der3) / sizeof(der3[0]) );
      
	double ti;
	for(int i = 1 ; i <= m ; i++)
	{
		
		ti = (45.0+5.0*i);
	
      		z1[i-1] = ti + v3;
	       	z2[i-1] = v2/z1[i-1];
		z3[i-1] = exp(z2[i-1]);
		z4[i-1] = v1*z3[i-1];
	        f[i-1] = z4[i-1] - y[i-1];
		
		
	}
   
	cout<<"F :"<<endl;
	for(int i = 0; i < m; i++)
	      	cout<<f[i].val<<endl;
	
      	cout<<endl<<"J: "<<endl;

      	for(int i = 0; i < m; i++)
	{	
		for(int j=0; j<f[i].der.size(); j++ )
		{	cout<<setw(15) << left<<f[i].der[j]<<" ";
		}
	     	cout<< endl;
	}      
  
    	return 0;
}


