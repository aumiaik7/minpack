% Brown badly scaled function 
% --------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=badscb(n,m,x,option)
% Problem no. 4
% Dimensions -> n=2, m=3              
% Standard starting point -> x=(1,1)  
% Minima -> f=0 at (1e+6,2e-6)        
%                                     
% Revised on 10/22/94 by Madhu Lamba  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%function [fvec,J] = badscb(n,m,x,option)  
%if (option==1 | option==3)
%        fvec = [  x(1)-10^6
%                  x(2)-(2e-6)
%                 x(1)*x(2)-2  ]  ;
%          else fvec='?';
%end;        
%if (option==2 | option==3)
%        J    = [  1      0
%                  0      1
%                  x(2)   x(1)  ] ;
%          else J='?';
%end;
%


function [F,J] = badscb(a)x = valder(a(1),[1 0]);
y = valder(a(2),[0 1]);
v1=x
v2=y
v3=x*y
f1 = v1-10^6;
f2 = v2-(2e-6);
f3 = v3-2;
%f1 = x-10^6;
%f2 = y-(2e-6);
%f3 = x*y-2;
values = [double(f1); double(f2); double(f3)];
F = values(:,1)
J = values(:,2:3)


