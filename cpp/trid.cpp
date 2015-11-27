/*
% Broyden tridiagonal function
% ---------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=trid(n,m,x,option)
% Dimensions -> n=variable, m=n
% Problem no. 30
% Standard starting point -> x=(-1,..,-1)
% Minima -> f=0 
%        
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
	m = n;
	
	valder a[n+2];	
	double der[n];
	
	cout<<"enter values for "<< n <<" variables :";
	for(int i = 1; i <= n; i++)
	{
		cin >> val;
		a[i].val = val; 
		derMaker(der,i,n);
		a[i].der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
		
	}
	a[n+1].val = 0;
	derMaker(der,n+1,n);//all pos will be 0;
	a[n+1].der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

      	valder v1[m+1],v2[m+1],v3[m+1],v4[m+1],v5[m+1],v6[m+1],f[m+1];	
	
	

	double two=2.0,three=3.0;

	for(int i=1; i<=m; i++)
	{
		v1[i]=two*(a[i]);
		v2[i]=two*a[i+1];
		v3[i]=three-v1[i];
		v4[i]=v3[i]*a[i];
      		if (i==1)
		{
			v5[i]=v4[i]-v2[i];
			f[i]=v5[i]+1;
		}
      		else if (i==n)
		{
			v5[i]=v4[i]-a[i-1];
    		 	f[i]=v5[i]+1;
		}
		else
		{
			 v5[i]=v4[i]-a[i-1];
      			 v6[i]=v5[i]-v2[i];
         		 f[i]=v6[i]+1;
      		}
	}
	
       
	
	
		
	
	
   
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
