//osb1.cpp
/*
% ****************************************************
% ****************************************************
 Osborne 2 function      [19]
%  Dimensions:  n=11, m=65
%  Standard starting point: (1.3,0.65,0.7,0.6,3,5,7,2,4.5,5.5)
%  Minima of f=4.01377...10^(-2) 
%  at (1.31,.4315,.6336,.5993,.7539,.9056,1.3651,4.8248,2.3988,
%       4.5689,5.6754)

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
	  
	double x1,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11;
	
	double y[] = {1.366,  1.191,  1.112,  1.013,  .991, 
        	.885,  .831,  .847,  .786, .725, 
         	.746,   .679,   .608,  .655,  .616,  
             	.606,  .602,  .626,    .651,  .724, 
             	.649,   .649,  .694,  .644,  .624,  
             	.661,  .612,   .558,  .533,  .495, 
               	.500,  .423,  .395,  .375,  .372,  
            	.391,  .396,   .405,   .428,   .429,  
              	.523,  .562,  .607,  .653,  .672,  
           	.708,   .633,   .668,   .645,  .632,  
              	.591,  .559,  .597,  .625,  .739,  
              	.710,   .729,   .720,  .636,  .581,  
              	.428,  .292,  .162,  .098,   .054, };
	
	
	int m = 65;
	cout<<"Enter values for x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 and x11:";
      	cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6 >> x7 >> x8 >> x9 >> x10 >> x11;



      	valder a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,t09[m],t10[m],t11[m],s09[m],s10[m],s11[m],s1[m],s2[m],s3[m],m1[m],m2[m],m3[m],m4[m],e1[m],e2[m],e3[m],e4[m],v1[m],v2[m],v3[m],v4[m],v5[m],v6[m],v7[m],f[m];
	
      	
	
	double der[11];

	


	a1.val = x1;
	derMaker(der,1,11);
	a1.der= vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a2.val = x2;
	derMaker(der,2,11);      	
	a2.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
	
	a3.val = x3;
	derMaker(der,3,11);	
	a3.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a4.val = x4;
	derMaker(der,4,11);      	
	a4.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a5.val = x5;
	derMaker(der,5,11);      	
	a5.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a6.val = x6;
	derMaker(der,6,11);      	
	a6.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a7.val = x7;
	derMaker(der,7,11);      	
	a7.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a8.val = x8;
	derMaker(der,8,11);      	
	a8.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a9.val = x9;
	derMaker(der,9,11);      	
	a9.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a10.val = x10;
	derMaker(der,10,11);      	
	a10.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );

	a11.val = x11;
	derMaker(der,11,11);      	
	a11.der = vector<double>(der, der + sizeof(der) / sizeof(der[0]) );
      
	double ti,mi;
	
	for(int i = 1 ; i <= m ; i++)
	{
		
		ti = (i-1)/10.0;
		t09[i-1] = ti-a9;
		t10[i-1] = ti-a10;
		t11[i-1] = ti-a11;
		s09[i-1] = pow(t09[i-1],2);
		s10[i-1] = pow(t10[i-1],2);
		s11[i-1] = pow(t11[i-1],2);
		s1[i-1] = -s09[i-1];
		s2[i-1]= -s10[i-1];
		s3[i-1]= -s11[i-1];
		mi= -ti;
		m1[i-1] = mi*a5;
		m2[i-1] = s1[i-1]*a6;
		m3[i-1] = s2[i-1]*a7;
		m4[i-1] = s3[i-1]*a8;
		e1[i-1] = exp(m1[i-1]);
		e2[i-1] = exp(m2[i-1]);
		e3[i-1] = exp(m3[i-1]);
		e4[i-1] = exp(m4[i-1]);
		v1[i-1] = a1*e1[i-1];
		v2[i-1] = a2*e2[i-1];
		v3[i-1] = a3*e3[i-1];
		v4[i-1] = a4*e4[i-1];
		v5[i-1] = v1[i-1]+v2[i-1];
		v6[i-1] = v3[i-1]+v4[i-1];
		v7[i-1] = v5[i-1]+v6[i-1];
		f[i-1] = y[i-1]-v7[i-1];
		
	}
   
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


