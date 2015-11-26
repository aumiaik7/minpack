//jensam.cpp
/*
% **************************************************************
%  function [fvec,J]= bard(n,m,x,opt)
%  Bard function       [8] 
%  Dimensions  n=3,    m=15
%  Function definition:
%       f(x) = y(i) - [x1 + (u(i) / v(i)x2 + w(i)x3)]
%       where u(i) = i, v(i) = 16-i, w(i) = min(u(i),v(i))
%  Standard starting point at x= (1,1,1)
%  Minima f=8.21487...10^(-3)   and f=17.4286 at (0.8406...,-inf,-inf)
%
%  Revised 10/23/94   PLK
% **************************************************************

%{
*/
#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;

int min(int num1, int num2);

int main()
{
	  
	double x1,x2,x3;
	
	double y[] = {.14,.18,.22,.25,.29,.32,.35,.39,.37,.58,.73,.96,1.34,2.10,4.39};
	
	int m = 15;
	cout<<"Enter values for x1 x2 and x3:";
      	cin >> x1 >> x2 >> x3;



      	valder v1,v2,v3,b1[m],b2[m],b3[m],b4[m],b5[m],f[m];
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
      
	int diff , check;
	for(int i = 1 ; i <= m ; i++)
	{
		
		diff = 16 - i;
		check = min(i,diff);
	      	b1[i-1] = diff*v2;
		b2[i-1] = check*v3;
		b3[i-1] = b1[i-1]+b2[i-1];
		b4[i-1] = i/b3[i-1];
		b5[i-1] = v1+b4[i-1];
		f[i-1] = y[i-1]-b5[i-1];
		
		
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

int min(int num1, int num2)
{
	if(num1 < num2)
		return num1;
	else
		return num2;
}
