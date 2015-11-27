//trig.cpp
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
	
	
	cout<<"Enter value for n:";
      	cin >> n;
	m=n;
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

      	valder sum1,cx[m+1],x1[m+1],v,v1[m+1],v2[m+1],sx[m+1],v3[m+1],f[m+1];

	
	
	

	double one=1.0;
		
	sum1.val = 0.0;
	derMaker(der,n+1,n);//all pos will be 0;
	sum1.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	for(int i=1; i<=m; i++)
	{
		x1[i]   = a[i];
		cx[i]  = cos(x1[i]);
		sum1  = sum1 + cx[i];
	}
	v = n-sum1;
	for(int i=1; i<=m ; i++)
	{
		x1[i] = a[i];
		cx[i] = cos(x1[i]);
	     	v1[i] = one - cx[i];
		v2[i] = i*v1[i];
		sx[i] = sin(x1[i]);
		v3[i] = v+v2[i];
		f[i] = v3[i]-sx[i];
	
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
