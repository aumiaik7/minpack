/*
% Penalty I  function
% ------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=pen1(n,m,x,option)
% Dimensions -> n=variable, m=n+1
% Problem no. 23             
% Standard starting point -> x=(s(j)) where 
%                            s(j)=j 
% Minima -> f=2.24997...10^(-5)  if n=4
%           f=7.08765...10^(-5)  if n=10      
% **********************************************
%{
*/
#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;

void derMaker(double der[], int pos, int size);


int main()
{
	int m,n;
	double val;  
	
	
	cout<<"Enter value for n:";
      	cin >> n;
	m = n+1;
	
	valder a[n+1];	
	double der[n];
	
	cout<<"enter values for "<< n <<" variables :";
	for(int i = 1; i <= n; i++)
	{
		cin >> val;
		a[i].val = val; 
		derMaker(der,i,n);
		a[i].der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
		
	}

      	valder v1[n+2],v2[n+2],f[n+2],sum;
	
	
	double sa=sqrt(1.0e-5);

	sum.val = 0;
	derMaker(der,n+1,n);//all pos will be 0;
	sum.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
	for(int i=1; i<=n; i++)
	{
		v1[i] =a[i]-1;
        	f[i] = sa*v1[i];
		v2[i] = pow(a[i],2);
       		sum = sum+v2[i];
	}

	f[n+1]=sum-(1.0/4.0);
	
	
   
	cout<<"F :"<<endl;
	for(int i = 1; i <= m; i++)
	      	cout<<f[i].val<<endl;
	
      	cout<<endl<<"J: "<<endl;

      	for(int i = 1; i <= m; i++)
	{	
		for(int j=0; j<f[i].der.size(); j++ )
		{	cout<<setw(15) << left<<f[i].der[j]<<" ";
		}
	     	cout<< endl;
	}      
  
    	return 0;
}

void derMaker(double der[], int pos,int size)
{
	for(int i = 0; i < size ; i++)
	{
		if(i == pos-1)
			der[i] = 1;
		else 
			der[i] = 0;
		
	}
}
