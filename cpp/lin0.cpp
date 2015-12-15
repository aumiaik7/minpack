//lin0.cpp
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
	int m,n;
	double val;  
	
	
	cout<<"Enter value for m and n:";
      	cin >> m >> n;
	
	valder a[m+1];	
	double der[n];
	
	cout<<"enter values for "<< n <<" variables :";

	for(int i = 1; i <= n; i++)
	{
		cin >> val;
		a[i].val = val; 
		derMaker(der,i,n);
		a[i].der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
		
	}

      	valder sum1,v1[m+1],s[m+1],v2,f[m+1];

	double v;	
	sum1.val = 0.0;
	derMaker(der,m+1,n);//all pos will be 0;
	sum1.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

  	for(int j=2; j<=n-1 ; j++)
	{
		s[j] = j*a[j];
                sum1 = sum1 + s[j];
        }
	for(int i=2; i<=m-1; i++)
	{        
        	v = i-1;
		v1[i] = sum1*v;
                f[i] = v1[i]-1;
		
	}
    	f[1].val = -1;
	derMaker(der,m+1,n);//all pos will be 0;
	f[1].der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
    	f[m].val = -1;
	derMaker(der,m+1,n);//all pos will be 0;
	f[m].der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );       

	   
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
