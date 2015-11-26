//osb1.cpp
/*
% ****************************************************
% ****************************************************
%  Osborne 1 function   [17]
% Dimensions: n=5 , m=33
% Function Definition:
%       f(x)=y(i)-(x1+x2*exp[-t(i)x4]+x3*exp[-t(i)x5])
%       where t(i)=10(i-1)
% Standard starting point: (0.5,1.5,-1,0.01,0.02)
% Minima of f=5.46489...10^(-5)
%           at (.3754,1.9358,-1.4647,0.01287,0.02212)
*/
#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;



int main()
{
	  
	double x1,x2,x3,x4,x5;
	
	double y[] = {0.844,0.908,0.932,0.936,0.925,0.908,0.881,0.850,0.818,0.784,  
0.751,0.718,0.685,0.658,0.628,0.603,0.580,0.558,0.538,
0.522,0.506,0.490,0.478,0.467,0.457,0.448,0.438,0.431,
0.424,0.420,0.414, 0.411, 0.406 };
	
	
	int m = 33;
	cout<<"Enter values for x1 x2 x3 x4 and x5:";
      	cin >> x1 >> x2 >> x3 >> x4 >> x5;



      	valder a1,a2,a3,a4,a5,e2[m],e3[m],e4[m],e5[m],t2[m],t3[m],t4[m],t5[m],f[m];
	
      	double der1[] = {1,0,0,0,0};
      	double der2[] = {0,1,0,0,0};
	double der3[] = {0,0,1,0,0};
      	double der4[] = {0,0,0,1,0};
	double der5[] = {0,0,0,0,1};
	

	a1.val = x1;
	a1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

	a2.val = x2;
      	a2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );
	
	a3.val = x3;
	a3.der = vector<double>(der3, der3 + sizeof(der3) / sizeof(der3[0]) );

	a4.val = x4;
      	a4.der = vector<double>(der4, der4 + sizeof(der4) / sizeof(der4[0]) );

	a5.val = x5;
      	a5.der = vector<double>(der5, der5 + sizeof(der5) / sizeof(der5[0]) );
      
	double ti,e1;
	double im1 = 0.0;
	for(int i = 1 ; i <= m ; i++)
	{
		
		ti   =  im1*10.0;
		e1 = -ti;
		e2[i-1] = e1*a4;
        	e3[i-1] = exp(e2[i-1]);
		e4[i-1] = e1*a5;
        	e5[i-1] = exp(e4[i-1]);
        	t2[i-1] = a2*e3[i-1];
        	t3[i-1] = a3*e5[i-1];
		t4[i-1] = t2[i-1]+t3[i-1];
		t5[i-1] = a1+t4[i-1];
		f[i-1] = y[i-1]-t5[i-1];
		im1 = i;
		
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


