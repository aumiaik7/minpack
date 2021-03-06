/*
% Discrete integral equation function
% ----------------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=ie(n,m,x,option)
% Dimensions -> n=variable, m=n
% Standard starting point -> x=(s[j]) where
%                            s[j]=t[j]*(t[j]-1) where
%                            t[j]=j*h & h=1/(n+1)
% Minima -> f=0 
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
	double val,h;  
	
	
	cout<<"Enter value for n:";
      	cin >> n;
	m = n;
	double t[n+1];
	h=1.0/(n+1);
	for(int i=1; i<=n; i++)
	{   	
		t[i]=i*h;
	}
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

      	valder v1[m+1],v2[m+1],v3[m+1],v4[m+1],u1[m+1],u2[m+1],u3[m+1],u5[m+1],s2[m+1],s3[m+1],s4[m+1],s5[m+1],s6[m+1],f[m+1],sum1,sum2;	
	
	sum1.val = 0;
	derMaker(der,n+1,n);//all pos will be 0;
	sum1.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
	
	

	double two=2.0,three=3.0,u4,s1;

	for(int i=1; i<=n; i++)
	{
		v1[i] = a[i]+t[i];
		v2[i] = v1[i]+1;
		v3[i] = pow(v2[i],3);
		v4[i] = t[i]*v3[i];
		sum1 = sum1+v4[i];
	
		sum2.val = 0;
		derMaker(der,n+1,n);//all pos will be 0;
		sum2.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
       
		if (n>i) 
		{
			for(int j=i+1; j<=n; j++)
			{	
			      u1[j] = a[j]+t[j];
			      u2[j] = u1[j]+1;
			      u3[j] = pow(u2[j],3);
			      u4 = 1-t[j];
			      u5[j] = u4*u3[j];
			      sum2 = sum2+u5[j];
		  	}
		}
		s1=1-t[i];
		s2[i] = s1*sum1;
		s3[i] = t[i]*sum2;
		s4[i] = s2[i]+s3[i];
		s5[i] = s4[i]/2;
		s6[i] = h*s5[i];
		f[i] = a[i]+s6[i];
	
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
