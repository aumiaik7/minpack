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
          vector<double> der;
          //with default value
	  // int add(vector<double> a, vector<double> b);
	  /* ~valder()
	   {

	     delete[] der;
	     }*/
	  
};

valder operator+(valder u, valder v);
valder operator+(valder u, double v);
valder operator+(double u,valder v);

valder operator-(valder u);

valder operator-(valder u, valder v);
valder operator-(valder u, double v);
valder operator-(double u,valder v);

valder operator*(valder u, valder v);
valder operator*(valder u, double v);
valder operator*(double u,valder v);

valder operator/(valder u, valder v);
valder operator/(valder u, double v);
valder operator/(double u,valder v);

valder pow(valder u, valder v);
valder pow(valder u, double v);
valder pow(double u,valder v);


valder exp(valder u);
valder log(valder u);
valder sqrt(valder u);
valder sin(valder u);
valder cos(valder u);
valder tan(valder u);

 
#endif
