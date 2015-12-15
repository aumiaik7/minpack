//bv.cpp
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
	double val,h;  
	
	
	cout<<"Enter value for n:";
      	cin >> n;
	m=n;
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
	a[n+1].val = 0.0;
	derMaker(der,n+1,n);//all pos will be 0;
	a[n+1].der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	h=1.0/(n+1);

      	valder v[m+1],v1[m+1],v2[m+1],v3[m+1],v4[m+1],v5[m+1],f[m+1];
	double t;
	
	
	

	
		
	for(int i=1; i<=m ; i++)
	{
		t = i*h;
		v[i] = a[i]+t;
		v1[i] = v[i]+1;
		v2[i] = 2*a[i];
		v3[i] = pow(v1[i],3);
		v4[i] = pow(h,2)*v3[i];
		v5[i] = v4[i]/2;
		if(i == 1)
			f[i] = v2[i]-a[i+1]+v5[i]; 
		else if(i == n)
			f[i] = v2[i]-a[i-1]+v5[i];
		else
			f[i] = v2[i]-a[i-1]-a[i+1]+v5[i];
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
