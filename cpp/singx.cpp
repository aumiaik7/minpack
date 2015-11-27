//rosex.cpp
/*
% Extended Powell Singular function
% --------------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=singx(n,m,x,option)
% Dimensions -> n=variable but a multiple of 4, m=n             
% Problem no. 22
% Standard starting point -> x=(s(j)) where 
%                            s(4*j-3)=3, 
%                            s(4*j-2)=-1,
%                            s(4*j-1)=0,
%                            s(4*j)=1 
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

      	valder v1[n+1],v2[n+1],v3[n+1],v4[n+1],v5[n+1],v6[n+1],f[n+1];
	
	
	double five = sqrt(5);
	double ten=sqrt(10);
	for(int i=1; i <= m/4; i++)
	{
	
		v1[i] = 10*a[4*i-2];
        	f[4*i-3] = a[4*i-3]+v1[i];
		v2[i] = a[4*i-1]-a[4*i];
       	 	f[4*i-2] = five*v2[i];
		v3[i] = 2*a[4*i-1];
		v4[i] = a[4*i-2]-v3[i];
        	f[4*i-1]=pow(v4[i],2);
		v5[i] = a[4*i-3]-a[4*i];
		v6[i] = pow(v5[i],2);
        	f[4*i] = ten*v6[i];
			
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
