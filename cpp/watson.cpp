//watson.cpp
/*
% **********************************************
%  Watson function    [20]
%  Dimensions : n=20,  m=31
%  Standard starting point : (0,....,0)
%  Minima of f=2.28767...10^(-3)    if n=6
%            f=1.39976...10^(-6)    if n=9
%            f=4.72238...10^(-10)   if n=12
%	     f=2.48631...10^(-20)   if n=20
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
	m=31;
	
	cout<<"Enter value for n:";
      	cin >> n;

	valder a[n];	
	double der[n];
	
	cout<<"enter values for "<< n <<" variables :";
	for(int i = 0; i < n; i++)
	{
		cin >> val;
		a[i].val = val; 
		derMaker(der,i+1,n);
		a[i].der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
		
	}

      	valder sum1,sum2,v3[n],v5[n],u3[n],t1[m],t2[m],t3,t4,f[m];

	
	
	

	double ti,v1,v2,v4,u1,u2;
	for(int i = 1; i<=29; i++)   
	{
		ti = i / 29.0;
	        sum1.val = 0;
		derMaker(der,n+1,n);//all pos will be 0;
		sum1.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
	    	for(int j = 2; j<=n; j++)
		{	
			v1 = j-2;
			v2 = pow(ti,v1);
			v3[j-1] =a[j-1]*v2;
			v4 = j-1;
			v5[j-1] = v4*v3[j-1];
			sum1 = sum1 + v5[j-1];
		}
	    
	    	sum2.val = 0;
		sum2.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
	 	for(int j = 1; j<=n; j++)
	 	{	
			u1 = j-1;
			u2 = pow(ti,u1);
			u3[j-1] = a[j -1]*u2;
			sum2 = sum2 + u3[j -1];
		}	
		t1[i-1] = pow(sum2,2);
		t2[i-1] = sum1-t1[i-1];
	    	f[i-1] = t2[i-1] - 1;
		
	}
		f[29] =  a[0];
		t3 = pow(a[0],2);
		t4 = a[1]-t3;
		f[30] =  t4-1;
		
	
   
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
