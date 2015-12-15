//ba.cpp
/*
% **********************************************

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
	int m,n,v;
	double val;  
	
	
	cout<<"Enter value for n:";
      	cin >> n;
	m=n;
	v = n + 1;
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

      	valder sum1,mul1,v1[m+1],f[m+1];

	
	
	

	
		
	sum1.val = 0.0;
	derMaker(der,n+1,n);//all pos will be 0;
	sum1.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
	 for(int j=1; j<=m; j++)
       	 {
	 	sum1 = sum1 + a[j];
	 }	
       
	
	mul1.val = 1.0;
	derMaker(der,n+1,n);//all pos will be 0;
	mul1.der =  vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
        for(int j=1; j<=m ;j++)
        {
	        mul1 = mul1 * a[j];
	}
        
	for(int i=1; i<m; i++)
	{
		v1[i] = a[i]+sum1;
                f[i] = v1[i]-v;
		
	}
    	f[n] = mul1-1;
        

	   
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
