/*
% Penalty II  function
% ------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=pen2(n,m,x,option)
% Dimensions -> n=variable, m=2*n
% Problem no. 24             
% Standard starting point -> x=(1/2,......,1/2)
% Minima -> f=9.37629...10^(-6)  if n=4
%           f=2.93660...10^(-4)  if n=10     
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
	m = 2*n;
	
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

      	valder v1[m+1],v2[m+1],v3[m+1],v4[m+1],v5[m+1],v6[m+1],v7[m+1],v8[m+1],v9[m+1], v12[m+1],v13[m+1],f[m+1],sum;
	
	
	double sa = sqrt(1.0e-5);
	double ep = exp(-1.0/10.0);

	
	
	f[1] = a[1]-0.2;
	double t1,t2,yi,v10,v11;
	if(n >= 2)
	{
		for(int i=2; i<=n; i++)
		{
			t1 = exp(i/10.0);
			t2 = exp((i-1.0)/10.0); 
			yi = t1+t2;  
			v1[i] = a[i]/10;
			v2[i] = a[i-1]/10;  
			v3[i] = exp(v1[i]);
			v4[i] = exp(v2[i]);
			v5[i] = v3[i]+v4[i];
			v6[i] = v5[i]-yi;
			f[i] = sa*v6[i];

	   	}
	 
	   	for(int i=n+1; i<=(2*n-1); i++)
		{
			v7[i] = a[i-n+1]/10;
			v8[i] = exp(v7[i]);
			v9[i] = v8[i]-ep;
			f[i] = sa*v9[i]; 
		
	   	}
	}		sum.val = 0;
		derMaker(der,n+1,n);//all pos will be 0;
		sum.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
	    
		for(int j=1;j<=n; j++)
		{
			v10 = n-j;
			v11 = v10 + 1;
			v12[j] = pow(a[j],2);
			v13[j] = v11*v12[j];
			sum = sum+v13[j];
	    	}
	   	f[2*n] = sum-1; 
		
	
	
   
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
