//jensam.cpp
/*
% **********************************************
% **********************************************
%
% Jenrich and Sampson function [6]
% Dimensions n=2,   m>=n
% Function definition 
%               f(x)=2+2i-(exp[ix1] + exp[ix2])
% Standard starting point x=(0.3,0.4)
% minima of f=124.362 at x1=x2=0.2578 for m=10
%
% Revised 10/23/94  PLK
% **********************************************
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
	int m;  
	double x1,x2;
	
	cout<<"Enter value for m:";
      	cin >> m;

	cout<<"Enter values for x1 and x2:";
      	cin >> x1 >> x2;



      	valder v1,v2,v3[m],v4[m],v5[m],v6[m],v7[m],v8[m],v9[m],f[m];
	int vali;
      	double der1[] = {1,0};
      	double der2[] = {0,1};
      
	v1.val = x1;
	v1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

	v2.val = x2;
	v2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );
	for(int i = 1 ; i <= m ; i++)
	{
		int val2i = 2*i;
	      	
		//v3[i]=2*i;
		v4[i-1] = i*v1;
		v5[i-1] = i*v2;
		v6[i-1] = exp(v4[i-1]);
		v7[i-1] = exp(v5[i-1]);
		v8[i-1] = v6[i-1]+v7[i-1];
		v9[i-1] = val2i-v8[i-1];
		f[i-1] = 2+v9[i-1];
		
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
