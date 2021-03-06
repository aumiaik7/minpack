% ****************************************************
% Function[fvec,J] = lin0(n,m,x,opt)
% Linear function - rank 1 with zero columns and rows  [34] 
% Dimensions: n variable,     m>=n
% Standard starting point: (1,...1)
% Minima of f=(m^2 + 3m - 6)/2(2m - 3)
%
% Coded in MATLAB    11/94      PLK
% *****************************************************


function[fvec,J]=lin0(n,m,a)
vect=zeros(1,n);
values=zeros(m,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
sum1=valder(0,vect);
        for j=2:n-1
		s(j)=j*x(j);
                sum1=sum1 + s(j);
        end;
for i=2:m-1
        
        	v(i)=i-1;
		v1(i)=sum1*v(i);
                f(i)=v1(i)-1;
		values(i,:) = [double(f(i))]
end
    f(1)=valder(-1,vect);
    f(m)=valder(-1,vect);
	values(1,:) = [double(f(1))]
        values(m,:) = [double(f(m))]
F = values(:,1)
J = values(:,2:n+1)
