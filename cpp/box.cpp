//box.cpp
/*
% ****************************************************
% ****************************************************
% Box three-dimensional function      [12]
% Dimensions:   n=3     m=10
% Function definition:
%       f(x)= exp[-t[i-1]x1]-exp[-t[i-1]x2]-x3[exp[-t[i-1]]-exp[-10t[i-1]]]
%       where t[i-1]=(0.1)i
% Standard Starting Points: (0,10,20)
% Minima of f=0 at (1,10,1), (10,1,-1) and wherever x1=x2 and x3-0
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

	
      	valder a1,a2,a3,v2[m],v3[m],v4[m],v5[m],v10[m],v11[m],f[m];
	int vali;
      	double der1[] = {1,0,0};
      	double der2[] = {0,1,0};
	double der3[] = {0,0,1};
	

	a1.val = x1;
	a1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

	a2.val = x2;
      	a2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );
	
	a3.val = x3;
	a3.der = vector<double>(der3, der3 + sizeof(der3) / sizeof(der3[0]) );
      
	double ti,v1,v6,v7,v8,v9;
	for(int i = 1 ; i <= m ; i++)
	{
		
		ti = 0.1*i;
		v1 = -ti;
		v2[i-1] = v1*a1;
		v3[i-1] = exp(v2[i-1]);
		v4[i-1] = v1*a2;
		v5[i-1] = exp(v4[i-1]);
		v6 = exp(v1);
		v7 = 10*v1;
		v8 = exp(v7);
		v9 = v6-v8;
		v10[i-1] = a3*v9;
		v11[i-1] = v3[i-1]-v5[i-1];
     		f[i-1] =  v11[i-1]-v10[i-1];
		
		
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


