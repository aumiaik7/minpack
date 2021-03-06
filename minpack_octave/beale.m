% Beale function 
% -------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=beale(n,m,x,option)
% Problem no. 5
% Dimensions -> n=2, m=3              
% Standard starting point -> x=(1,1) 
% Minima -> f=0 at (3,0.5)            
%                                     
% Revised on 10/22/94 by Madhu Lamba  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%function [fvec,J] = beale(n,m,x,option)

%if (option==1 | option==3)
%        fvec = [  1.5-x(1)*(1-x(2))
%                  2.25-x(1)*(1-x(2)^2)
%                  2.625-x(1)*(1-x(2)^3)  ]; 
%          else fvec='?';
%end;        
%if (option==2 | option==3)
%        J    = [  -(1-x(2))      x(1)
%                  -(1-x(2)^2)    x(1)*2*x(2)
%                  -(1-x(2)^3)    x(1)*3*x(2)^2  ]; 
%          else J='?';
%end;
%function [F,J] = beale(a)x = valder(a(1),[1 0]);
y = valder(a(2),[0 1]);
v1=x
v2=y
v3=1-v2
v4=v1*v3
f1 = 1.5-v4;
v5=v2^2
v6=1-v5
v7=v1*v6
f2 = 2.25-v7;
v8=v2*v5
v9=1-v8
v10=v1*v9
f3 = 2.625-v10;
values = [double(f1); double(f2); double(f3)];
F = values(:,1)
J = values(:,2:3)
