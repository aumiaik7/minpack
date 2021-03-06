%function [fvec,J]= lin1(n,m,x,opt)

% **********************************
% Function [fvec,J] = lin1(n,m,x,opt)
% Linear function - rank 1   [33]
% Dimensions:  n variable,    m>=n
% Standard starting point: (1,....,1)
% Minima of f=[(m(m-1))/(2(2m+1))]
%
% Coded in MATLAB    11/94      PLK
% **********************************
%{
J=zeros(m,n);
for i = 1:m
   
    sum1=0;
    for j = 1:n
       sum1=sum1 + j*x(j);
    end;

    if((opt==1)|(opt==3))
        fvec(i)= i*sum1 - 1;
    else fvec='?';
    end;

    if((opt==2)|(opt==3))
       
        for j= 1:n
           J(i,j)=i*j;
        end;
    else J='?';

    end;
end;
fvec=fvec';

if((opt<1)|(opt>3))
        disp('Error: Option value sent to LIN1.M is either <1 or >3');
end;
%}function [fvec,J]= lin1(n,m,a)
vect=zeros(1,n);
values=zeros(m,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end	
for i = 1:m
   
    sum1=valder(0,vect);
    for j = 1:n
	v(j)=j*x(j);
       sum1=sum1 + v(j);
    end;
	v1(i)=i*sum1;
        f(i)= v1(i) - 1;
	values(i,:) = [double(f(i))];
end
F = values(:,1)
J = values(:,2:n+1)
