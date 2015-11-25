//badscp.cpp

#include <iostream>
#include <vector>
#include <iomanip>
#include<cmath>
#include "valder.h"
using namespace std;



int main()
{
  
	double x1,x2;
	cout<<"Enter values for x1 and x2:";

      	cin >> x1 >> x2;



      	valder v1,v2,v3,v4,v5,v6,v7,v8,v9,f1,f2;
      	double der1[] = {1,0};
      	double der2[] = {0,1};
      
      	v1.val = x1;
      	v1.der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

	v2.val = x2;
      	v2.der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );

	v3=v1*v2;
	v4=pow(10,4)*v3;
	v5=-v1;
	v6=-v2;
	v7=exp(v5);
	v8=exp(v6);
	v9=v7+v8;
	f1 = v4-1;
	f2 = v9-1.0001;
   
      	cout<<"F :"<<endl << f1.val<<" "<<f2.val<<endl;
      	cout<<"J: "<<endl;
      	for(int i=0; i<f1.der.size(); i++ )
		cout<<setw(15) << left<<f1.der[i]<<" ";
      	cout<< endl;
      	for(int i=0; i<f2.der.size(); i++ )
		cout<<setw(15) << left<<f2.der[i]<<" ";
      	cout<< endl;
  
    	return 0;
}
