//jensam.cpp

#include <iostream>
#include <vector>
#include <iomanip> 
#include <cmath> 
#include "valder.h"
using namespace std;



int main()
{
	int m;  
	double x1,x2;
	
	cout<<"Enter value for m:";
      	cin >> m;

	cout<<"Enter values for x1 and x2:";
      	cin >> x1 >> x2;



      	valder v1[m],v2[m],v3[m],v4[m],v5[m],v6[m],v7[m],v8[m],v9[m],f[m];
	int vali;
      	double der1[] = {1,0};
      	double der2[] = {0,1};
      
	for(int i = 1 ; i <= m ; i++)
	{
		int val2i = 2*i;
	      	v1[i-1].val = x1;
	      	v1[i-1].der= vector<double>(der1, der1 + sizeof(der1) / sizeof(der1[0]) );

		v2[i-1].val = x2;
	      	v2[i-1].der = vector<double>(der2, der2 + sizeof(der2) / sizeof(der2[0]) );
		//v3[i]=2*i;
		v4[i-1] = i*v1[i-1];
		v5[i-1] = i*v2[i-1];
		v6[i-1] = exp(v4[i-1]);
		v7[i-1] = exp(v5[i-1]);
		v8[i-1] = v6[i-1]+v7[i-1];
		v9[i-1] = val2i-v8[i-1];
		f[i-1] = 2+v9[i-1];
		
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
