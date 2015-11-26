//kowosb.cpp
/*
% ****************************************************
% ****************************************************
% Kowalik and Osborne function    [15]
% Dimensions:     n=4   m=11
% Function Definition:
%       f(x)= y[i-1] - [x1(u^2 +u*x2) / (u^2 + u*x3 + x4)]
% Standard starting point: (0.25,0.39,0.415,0.39)
% Minima of f= 3.07505...10^-4 and
%           f= 1.02734...10^-3  at (inf,-14.07...,-inf,-inf)
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
	  
	double x1,x2,x3,x4;
	
	
	
	int m ;
	cout<<"Enter value m:";
      	cin >> m;

	cout<<"Enter values for x1 x2 x3 and x4:";
      	cin >> x1 >> x2 >> x3 >> x4;



      	valder a1,a2,a3,a4,v1[m],v2[m],v3[m],v4[m],v5[m],v6[m],v7[m],v8[m],f[m];
	
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
      
	double ti,ei,si,ci;
	double two = 2.0, point2 = 0.2;
	for(int i = 1 ; i <= m ; i++)
	{
		
		ti   = i*point2;
        	ei   = exp(ti);
        	si   = sin(ti);
       		ci   = cos(ti);
		v1[i-1] = a4*si;
		v2[i-1] = v1[i-1]- ci;
		v3[i-1] = a3+v2[i-1];
		v4[i-1] = pow(v3[i-1],2);
		v5[i-1] = ti*a2;
		v6[i-1] = a1+v5[i-1];
		v7[i-1] = v6[i-1]-ei;
		v8[i-1] = pow(v7[i-1],2);
        	f[i-1] = v8[i-1] + v4[i-1];
		
		
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


