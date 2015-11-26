//gulf.cpp
/*
% ****************************************************
% ****************************************************
% Gulf research and development function      [11]
% Dimensions  n=3,  n=<m=<100
% Function definition:
%       f(x)= exp[-(| y(i)mi x(2)|^x(3) / x(1))- t(i)
%       where t(i) = i/100
%       and y(i)=25 +(-50 ln(t(i))^2/3)
% Standard starting point x=(5,2.5,0.15)
% minima of f=0 at (50,25,1.5)
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
	
	
	int m;
	cout<<"Enter values for m:";
      	cin >> m;
	cout<<"Enter values for x1 x2 and x3:";
      	cin >> x1 >> x2 >> x3;

	double x1inv,two3rd, point1 = .01,twnty5 = 25.0,fifty = -50.0;

	x1inv = 1.0 / x1;
      	two3rd = 2.0 / 3.0;
      	valder v1,v2,v3,a[m],a1[m],a2[m],a3[m],a4[m],a5[m],f[m];
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
      
	double ti,y1,y2,y3,yi;
	for(int i = 1 ; i <= m ; i++)
	{
		
		ti  = i*point1;
		y1 = log(ti);
		y2 = fifty*y1;
		y3 = pow(y2,two3rd);
	        yi  = twnty5 + y3;
	        a[i-1]  = yi - v2;
		a1[i-1] = abs(a[i-1]);
		a2[i-1] = pow(a1[i-1],v3);
		a3[i-1] = a2[i-1]/v1;
		a4[i-1] = -a3[i-1];
		a5[i-1] = exp(a4[i-1]);
	        f[i-1]  = a5[i-1] - ti;
		
		
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


