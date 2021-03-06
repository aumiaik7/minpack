% Powell badley scaled function 
% ----------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=badscp(n,m,x,option)   
% Problem no. 3
% Dimensions -> n=2, m=2                      
% Standard starting point -> x=(0,1)          
% Minima -> f=0 at (1.098...10-E5,9.106...)   
%                                             
% Revised on 10/22/94 by Madhu Lamba          
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%function [fvec,J] = badscp(n,m,x,option)

%if (option==1 | option==3)
%        fvec = [  10^4*x(1)*x(2)-1
%                 exp(-x(1))+exp(-x(2))-1.0001  ] ;
%          else fvec='?';
%end;
%if (option==2 | option==3)
%        J    = [  10^4*x(2)        10^4*x(1)
%                  -exp(-x(1))      -exp(-x(2))  ] ;
%          else J='?';
%end;
%function [F,J] = badscp(a)x = valder(a(1),[1 0]);
y = valder(a(2),[0 1]);
v1=x
v2=y
v3=v1*v2
v4=(10^4)*v3
v5=-v1
v6=-v2
v7=exp(v5)
v8=exp(v6)
v9=v7+v8
f1 = v4-1;
f2 = v9-1.0001;
%f1=10^4*x*y-1
%f2=exp(-x)+exp(-y)-1.0001 
values = [double(f1); double(f2)];
F = values(:,1)
J = values(:,2:3)
