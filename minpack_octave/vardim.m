% Variably Dimensioned function
% ----------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=vardim(n,m,x,option)
% Dimensions -> n=variable, m=n+2
% Problem no. 25
% Standard starting point -> x=(s(j)) where 
%                            s(j)=1-(j/n) 
% Minima -> f=0 at (1,.....1)
%                                     
% 11/21/94 by Madhu Lamba  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%{
function [fvec,J] = vardim(n,m,x,option)  

J=zeros(m,n);
for i=1:n

   if (option==1 | option==3)
        fvec(i)=x(i)-1;
    else fvec='?';
   end;        

   if (option==2 | option==3)
	J(i,i)=1;
else J='?';
   end;
end 

var_1=0;
for j=1:n
    var_1=var_1+j*(x(j)-1);
end;
if (option==1 | option==3)
        fvec(n+1)=var_1;
        fvec(n+2)=(var_1)^2;
    else fvec='?';
end;

if (option==2 | option==3)
        for j=1:n
 	    J(n+1,j) = j;
            J(n+2,j) = (2*var_1*j);
        end;
    else J='?';
end;

if (option==1 | option==3)
   fvec=fvec';
else fvec='?';
end;
%}
function [fvec,J] = vardim(n,a)
m=n+2;
vect=zeros(1,n);
values=zeros(m,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
for i=1:n
        f(i)=x(i)-1;
	values((i),:) = [double(f(i))];
end 

var_1=0;
for j=1:n
	v1(j)=x(j)-1;
	v2(j)=j*v1(j);
    var_1=var_1+v2(j);
end;
        f(n+1)=var_1;
        f(n+2)=(var_1)^2;
	values((n+1),:) = [double(f(n+1))];
	values((n+2),:) = [double(f(n+2))];
F = values(:,1)
J = values(:,2:n+1)

