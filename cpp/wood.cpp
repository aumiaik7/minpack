//helix.cpp

/*
% *******************************************
% *******************************************
% function [ fvec, J]= helix(n,m,x,opt)
%
% Helical valley function  [7]
% Dimensions    n=3,   m=3
% Function Definition:
%       f1(x) = 10[x3 - 10*(x1,x2)]
%       f2(x) = 10[((x1)^2 + (x2)^2)^.5 -1]
%       f3(x) = x3
% Standard starting point  x= (-1,0,0)
% Minima of f=0 at (1,0,0)
%
% Revised 10/23/94   PLK
% *********************************************

*/

#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;

void display(valder f);

int main()
{
	  
	double x1,x2,x3,x4;
	
	
	
	cout<<"Enter values for x1 x2 x3 and x4:";
      	cin >> x1 >> x2 >> x3 >> x4;



      	valder a1,a2,a3,a4,v1,v2,v3,v4,v6,v7,v9,f1,f2,f3,f4,f5,f6;
	int vali;
      	double der1[] = {1,0,0,0};
      	double der2[] = {0,1,0,0};
	double der3[] = {0,0,1,0};
      	double der4[] = {0,0,0,1};

	a1.val = x1;
      	a1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

      	a2.val = x2;
      	a2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

	a3.val = x3;
      	a3.der = vector<double>(der3, der3 + sizeof(der3) / sizeof(der3[0]) );

	a4.val = x4;
      	a4.der = vector<double>(der4, der4 + sizeof(der4) / sizeof(der4[0]) );

	double v5,v8,v10;
	
	v1 = pow(a1,2);
	v2 = a2-v1;
	f1 = 10*v2;
	f2 = 1-a1;
	v3 = pow(a3,2);
	v4 = a4-v3;
	v5 = sqrt(90);
	f3 = v5*v4;
	f4 = 1-a3;
	v6 = a2+a4;
	v7 = v6-2;
	v8 = sqrt(10);
	f5 = v8*v7;
	v9 = a2-a4;
	v10 = 1/v8;
	f6 = v10*v9;
	
 	cout<<"F :"<<endl << f1.val<<endl <<f2.val<<endl <<f3.val<<endl<<f4.val<<endl<<f5.val<<endl<<f6.val<<endl;
      	cout<<"J: "<<endl;
      	/*for(int i=0; i<f1.der.size(); i++ )
		cout<<setw(10) << left<<f1.der[i]<<" ";
      	cout<< endl;
      	for(int i=0; i<f2.der.size(); i++ )
		cout<<setw(10) << left<<f2.der[i]<<" ";
      	cout<< endl;
   	for(int i=0; i<f3.der.size(); i++ )
		cout<<setw(10) << left<<f3.der[i]<<" ";
      	cout<< endl;
	for(int i=0; i<f4.der.size(); i++ )
		cout<<setw(10) << left<<f4.der[i]<<" ";
      	cout<< endl;
	for(int i=0; i<f5.der.size(); i++ )
		cout<<setw(10) << left<<f5.der[i]<<" ";
      	cout<< endl;   
	for(int i=0; i<f6.der.size(); i++ )
		cout<<setw(10) << left<<f6.der[i]<<" ";
      	cout<< endl;    */
	display(f1);
	display(f2);
	display(f3);
	display(f4);
	display(f5);
	display(f6);  
  
    	return 0;
}

void display(valder f)
{
	for(int i=0; i<f.der.size(); i++ )
		cout<<setw(10) << left<<f.der[i]<<" ";
      	cout<< endl;
}
