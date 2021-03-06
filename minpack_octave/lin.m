%function [fvec,J]= lin(n,m,x,opt)
%Function [fvec,J]= lin(n,m,x,opt)
%Linear function - full rank [32]
%Dimensions: n variable,      m>=n
%Standard starting point: (1,...,1)
%Minima of f=m-n at (-1,...,-1)
%
%Coded in MATLAB   11/94        plk
%{
J=zeros(m,n);
for i=1:n

    sum1=sum(x);
        
    if((opt==1)|(opt==3))
        fvec(i)= x(i)-(2/m)*sum1-1;
    else fvec='?';
    end;

    if((opt==2)|(opt==3))
        for j=1:n
           if i==j
                J(i,j)=1-(2/m);
           else J(i,j)=-(2/m);
           end;
        end;
    else J='?';
    end;
end;

for i=n+1:m
        
    if((opt==1)|(opt==3))
        fvec(i)= -(2/m)*sum1-1;
    else fvec='?';
    end;

    if((opt==2)|(opt==3))
        for j=1:n
                J(i,j)=-(2/m);
        end;
    else J='?';
    end;
end;
       
fvec=fvec';

if((opt<1)|(opt>3))
        disp('Error: Option value sent to LIN.M is either <1 or >3');
end;
%}function [fvec,J]= lin(n,m,a)
%sum1=sum(a);
vect=zeros(1,n);
values=zeros(m,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end	
sum1=valder(0,vect);
for i=1:n
	%sum1=sum(x);
	sum1=sum1+x(i);
end
for i=1:n
	v1=(2/m)*sum1;
	v1(i)=x(i)-v1;
        f(i)= v1(i)-1;
	values(i,:) = [double(f(i))];

end;
for i=n+1:m
        v2=(2/m)*sum1;
        f(i)= -v2-1;
	values(i,:) = [double(f(i))];
end;
F = values(:,1)
J = values(:,2:n+1)
