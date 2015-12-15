%function[fvec,J]=lin0(n,m,x,opt)
% ****************************************************
% Function[fvec,J] = lin0(n,m,x,opt)
% Linear function - rank 1 with zero columns and rows  [34] 
% Dimensions: n variable,     m>=n
% Standard starting point: (1,...1)
% Minima of f=(m^2 + 3m - 6)/2(2m - 3)
%
% Coded in MATLAB    11/94      PLK
% *****************************************************

function[fvec,J]=lin01(n,m,a)
        for i=1:n
	   x(i)=a(i);
	end
for i=2:m-1
        sum1=0;
        for j=2:n-1
		v1(j)=j*x(j);
                sum1=sum1 + v1(j);
        end;
           v2(i)=(i-1)*sum1;
           fvec(i)=v2(i)-1;
end;
    fvec(1)=-1;
    fvec(m)=-1;
fvec=fvec'
