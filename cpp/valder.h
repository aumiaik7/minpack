//File name valder.h

#ifndef VALDER_H
#define VALDER_H
#include<vector>

using namespace std;
class valder
{
     private :
          
          
     public :
          double val;
          double der[];
          //with default value
	  // int add(vector<double> a, vector<double> b);
	  
	  

        
      
};
valder operator+(valder u, valder v);
valder operator+(valder u, double v);
//valder operator+(valder u, double v);
valder operator+(double u,valder v);

 
#endif
