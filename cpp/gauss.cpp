//gauss.cpp
/*
% ****************************************************
% ****************************************************
% Gaussian function [9]      
% Dimensions   n=3,  m=15
% Function definition:
%       f(x)= x(1) exp[-x(2)*[(t(i)-x(3)]^2 / 2]-y(i)
%       where t(i) = (8-i)/2
% Standard starting point at x=(0.4,1,0)
% Minima of f=1.12793...10^(-8)
%
% Revised 10/23/94    PLK
% ****************************************************
%{
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
	
	double y[] = {.0009,.0044,.0175,.0540,.1295,.2420,.3521,.3989,.3521,.2420,.1295,.0540,.0175,.0044,.0009};
	
	int m = 15;
	cout<<"Enter values for x1 x2 and x3:";
      	cin >> x1 >> x2 >> x3;



      	valder v1,v2,v3,z1[m],z2[m],z3[m],z4[m],z5[m],z6[m],z7[m],f[m];
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
      
	double t;
	for(int i = 1 ; i <= m ; i++)
	{
		
		t = (8.0 - i)/2.0;

		z1[i-1] = t-v3;
		z2[i-1] = pow(z1[i -1],2);
		z3[i-1] = -v2;
			
		z4[i-1] = z3[i-1]*z2[i-1];
		z5[i-1] = z4[i-1]/2;
		z6[i-1] = exp(z5[i-1]);
		z7[i-1]= v1*z6[i-1];
		f[i-1] = z7[i-1]-y[i-1];
		
		
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


