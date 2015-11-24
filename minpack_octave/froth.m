% Freudenstein and Roth function 
% ------------------------------ 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%  
% function [fvec,J]=froth(n,m,x,option)     
% Problem no. 2
% Dimensions -> n=2, m=2                           
% Standard starting point -> x=(0.5,-2)            
% Minima -> f=0 at (5,4)                           
%           f=48.9842... at (11.41...,-0.8968...)  
%                                                  
% Revised on 10/22/94 by Madhu Lamba               
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%{
function [fvec,J] = froth(n,m,x,option)

if (option==1 | option==3)
        fvec = [ -13+x(1)+((5-x(2))*x(2)-2)*x(2)
                 -29+x(1)+((x(2)+1)*x(2)-14)*x(2) ]; 
         else fvec='?';
end;        
if (option==2 | option==3)
        J    = [ 1       10*x(2)-3*x(2)^2-2
                 1       3*x(2)^2+2*x(2)-14  ] ;
         else J='?';
        
end;
%}
function [fvec,J] = froth(a)
x = valder(a(1),[1 0]);
y = valder(a(2),[0 1]);
v1=x
v2=y
v3=5-v2
v4=v3*v2
v5=v4-2
v6=v5*v2
v7=v1+v6
f1=-13+v7;
v8=v2+1
v9=v8*v2
v10=v9-14
v11=v10*v2
v12=v1+v11
f2=-29+v12;
values = [double(f1); double(f2)];
F = values(:,1)
J = values(:,2:3)
