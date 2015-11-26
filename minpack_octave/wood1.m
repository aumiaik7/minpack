%function [fvec,J] = wood(n,m,x,opt)

% *********************************************
% *********************************************
%
% Function [fvec,J]=WOOD (n,m,x,opt)
% Wood function    [14] 
% Dimensions:     n=4   m=6
% Function Definition:
%       f1(x)= 10(x2 -x1^2)
%       f2(x)= 1 - x1
%       f3(x)= (90)^.5*(x4-x3^2)
%       f4(x)= 1-x3
%       f5(x)= (10)^.5 * (x2+x4-2)
%       f6(x)= (10)^(-.5) * (x2-x4)
% Standard starting point:  (-3,-1,-3,-1)
% Minima of f=0 at (1,1,1,1)
% *********************************************x
%{
if((opt==1)|(opt ==3))

fvec =   [  10*(x(2)-x(1)^2)
            1-x(1)
            sqrt(90)*(x(4)-x(3)^2)
            1-x(3)
            sqrt(10)*(x(2)+x(4)-2)
            (1/sqrt(10))*(x(2)-x(4))  ];
    else fvec='?';
end;

if ((opt==2)|(opt==3))
J    =   [  -20*x(1)       10        0            0
            -1     	   0         0            0
             0             0   -2*sqrt(90)*x(3)  sqrt(90)    
             0             0        -1            0
             0           sqrt(10)    0           sqrt(10)
             0         1/sqrt(10)    0          -1/sqrt(10)  ] ;
     else J='?';

end;

if((opt<1)|(opt>3))
        disp('Error: Option value for WOOD.M is either <1 or >3');
end;
%}       function [fvec,J] = wood1(a)
x1=a(1);
x2=a(2);
x3=a(3);
x4=a(4);
	v1=x1^2;
	v2=x2-v1;
	f1=10*v2
	f2=1-x1
	v3=x3^2;
	v4=x4-v3;
	v5=sqrt(90);
	f3=v5*v4
	f4=1-x3
	v6=x2+x4;
	v7=v6-2;
	v8=sqrt(10);
	f5=v8*v7
	v9=x2-x4;
	v10=1/sqrt(10);
	f6=v10*v9
