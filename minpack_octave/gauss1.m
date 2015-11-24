%function [fvec,J] = gauss(n,m,x,opt)

% ****************************************************
% ****************************************************
% function [fvec, J] =gauss(n,m,x,opt)
% Gaussian function [9]      
% Dimensions   n=3,  m=15
% Function definition:
%       f(x)= x(1) exp[-x(2)*[(t(i)-x(3)]^2 / 2]-y(i)
%       where t(i) = (8-i)/2
% Standard starting point at x=(0.4,1,0)
% Minima of f=1.12793...10^(-8)
%
% Revised 10/23/94    PLK
% ****************************************************

%{

y    = [.0009  .0044  .0175  .0540  .1295  .2420  .3521  .3989             
            .3521  .2420  .1295  .0540  .0175  .0044  .0009   0   ]' ;

J=zeros(m,n);

for i = 1:m

      t(i) = (8 - i)/2;

      if (opt ==1) | (opt == 3)
        fvec(i) =  x(1)*exp((-x(2)*((t(i)-x(3))^2))/2)-y(i) ;
    else fvec='?';
      end;
      
      if (opt ==2) | (opt == 3) 
        J(i,1)  =  exp((-x(2)*((t(i)-x(3))^2))/2);
        J(i,2)  =  x(1)*((-((t(i)-x(3))^2))/2)*exp((-x(2)*((t(i)-x(3))^2))/2);
        J(i,3)  =  x(1)*x(2)*(t(i)-x(3))*exp((-x(2)*((t(i)-x(3))^2))/2);
    else J='?';
      end;
      
end;

fvec=fvec';
 
if ((opt<1) | (opt >3))
        disp('Error: Option value sent to GAUSS.M is either <1 or >3');
end;
%}
function [fvec,J] = gauss(a)
x1=a(1);
x2=a(2);
x3=a(3);

y    = [.0009  .0044  .0175  .0540  .1295  .2420  .3521  .3989             
            .3521  .2420  .1295  .0540  .0175  .0044  .0009   0   ]' ;

%J=zeros(m,n);

for i = 1:15

      t(i) = (8 - i)/2;
	z1(i)=t(i)-x3;
	z2(i)=z1(i)^2;
	z3(i)=-x2;
	z4(i)=z3(i)*z2(i);
	z5(i)=z4(i)/2;
	z6(i)=exp(z5(i));
	z7(i)=x1*z6(i);
	f(i)=z7(i)-y(i);

    %    fvec(i) =  x(1)*exp((-x(2)*((t(i)-x(3))^2))/2)-y(i) ;    
end;
fvec=f'