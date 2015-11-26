%function [fvec,J] = sing(n,m,x,opt)

% ***************************************
% Function [fvec,J]= sing(n,m,x,opt)
% Powell singular function  [13]
% Dimensions:    n=4    m=4
% Function definitions:
%       f1(x)=x1 + 10x2      
%       f2(x)= 5^.5*(x3 - x4)
%       f3(x)= (x2-2x3)^2
%       f4(x)= 10^.5*(x1-x4)^2
% Starting point: (3,-1,0,1)
% Minima of f=0 at the origin
%
% Coded in Matlab  October 31   PLK
% **************************************8
%{
if((opt ==1 )|(opt ==3))

        fvec =  [  x(1)+10*x(2)
          	   sqrt(5)*(x(3)-x(4))
          	   (x(2)-2*x(3))^2
                   sqrt(10)*((x(1)-x(4))^2)  ] ;
           else fvec='?';
end;

if((opt==2)|(opt==3))

J    =  [  1                           10       0                            0
           0                            0       sqrt(5)               -sqrt(5)
           0              2*(x(2)-2*x(3))      -4*(x(2)-2*x(3))              0 
           2*sqrt(10)*(x(1)-x(4))       0       0      -2*sqrt(10)*(x(1)-x(4))];
   else J='?';

end;
if((opt<1)|(opt>3))
        disp('Error: Option value for SING.M is either <1 or >3');
end;
%}function [fvec,J] = sing1(a)
x1=a(1);
x2=a(2);
x3=a(3);
x4=a(4);
	v1=10*x2;
	f1=x1+v1
	v2=x3-x4;
	v3=sqrt(5);
	f2=v3*v2
	v4=2*x3;
	v5=x2-v4;
	f3=v5^2
	v6=x1-x4;
	v7=v6^2;
	v8=sqrt(10);
	f4=v8*v7
	

