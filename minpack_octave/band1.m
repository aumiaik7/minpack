%function [fvec,J] = band(n,m,x,opt)
%******************************************
% Function [Fvec, J]= band (n,m,x,opt)
% Broyden banded function   [31]
% Dimensions: n variable,   m=n
% Standard starting point: (-1,...,-1)
% minima of f=0
% coded in MATLAB  11/94        plk
% *****************************************   

function [fvec,J] = band1(n,a)
m=n;
ml=5;
mu=1;
for i=1:n	
	x(i)=a(i);
end
for i=1:m
        sum1=0;
        lb=max(1,i-ml);
        lu=min(n,i+mu);
         
        for j=1:n
           if (j ~= i)
              if((j>=lb)&(j<=lu))
		v1(j)=1+x(j);
		v2(j)=x(j)*v1(j);
                 sum1=sum1 + v2(j);
              end;
           end;
        end;
	v(i)=x(i)^2;
	v3(i)=5*v(i);
	v4(i)=2+v3(i);
	v5(i)=x(i)*v4(i);
	v6(i)=v5(i)+1;
          fvec(i)=v6(i)-sum1;
end;                 
fvec=fvec'
