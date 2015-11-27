/*
% Variably Dimensioned function
% ----------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=vardim(n,m,x,option)
% Dimensions -> n=variable, m=n+2
% Problem no. 25
% Standard starting point -> x=(s(j)) where 
%                            s(j)=1-(j/n) 
% Minima -> f=0 at (1,.....1)
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
	m = n+2;
	
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

      	valder v1[m+1],v2[m+1],f[m+1],var_1;

	
	
	for(int i=1; i<=n; i++)
	{   	
		f[i]=a[i]-1;
	}

	var_1.val = 0;
	derMaker(der,n+1,n);//all pos will be 0;
	var_1.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	for(int j=1; j<=n;j++)
	{
		v1[j] = a[j]-1;
		v2[j] = j*v1[j];
		var_1 = var_1+v2[j];
	}
	
        f[n+1] = var_1;
        f[n+2] = pow(var_1,2);
	
	
		
	
	
   
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
