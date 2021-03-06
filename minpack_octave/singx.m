% Extended Powell Singular function
% --------------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=singx(n,m,x,option)
% Dimensions -> n=variable but a multiple of 4, m=n             
% Problem no. 22
% Standard starting point -> x=(s(j)) where 
%                            s(4*j-3)=3, 
%                            s(4*j-2)=-1,
%                            s(4*j-1)=0,
%                            s(4*j)=1 
% Minima -> f=0 at the origin.            
%                                     
% 11/21/94 by Madhu Lamba  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%{
function [fvec,J] = singx(n,m,x,option)  

J=zeros(m,n);
for i=1:m/4

   if (option==1 | option==3)
        fvec(4*i-3)=x(4*i-3)+10*(x(4*i-2));
        fvec(4*i-2)=sqrt(5)*(x(4*i-1)-x(4*i));
        fvec(4*i-1)=(x(4*i-2)-2*(x(4*i-1)))^2;
        fvec(4*i)  =sqrt(10)*(x(4*i-3)-x(4*i))^2;
    else fvec='?';
   end;        

   if (option==2 | option==3)
	J(4*i-3,4*i-3) = 1;
        J(4*i-3,4*i-2) = 10;
        J(4*i-2,4*i-1) = sqrt(5);
        J(4*i-2,4*i)   = -sqrt(5);
        J(4*i-1,4*i-2) = 2*x(4*i-2)-4*x(4*i-1);
        J(4*i-1,4*i-1) = 8*x(4*i-1)-4*x(4*i-2);
        J(4*i,4*i-3)   = 2*sqrt(10)*(x(4*i-3)-x(4*i));
        J(4*i,4*i)     = 2*sqrt(10)*(x(4*i)-x(4*i-3));
    else J='?';
   end;
end;

if (option==1 | option==3)
   fvec=fvec';
J
else fvec='?';
end;
%}function [fvec,J] = singx(n,a)
m=n;
five=sqrt(5);
ten=sqrt(10);
vect=zeros(1,n);
values=zeros(n,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
for i=1:m/4
	v1(i)=10*(x(4*i-2));
        f(4*i-3)=x(4*i-3)+v1(i);
	v2(i)=(x(4*i-1)-x(4*i));
        f(4*i-2)=five*v2(i);
	v3(i)=2*(x(4*i-1));
	v4(i)=x(4*i-2)-v3(i);
        f(4*i-1)=(v4(i))^2;
	v5(i)=x(4*i-3)-x(4*i);
	v6(i)=(v5(i))^2;
        f(4*i)=ten*v6(i);
        values((4*i-3),:) = [double(f(4*i-3))]
	values((4*i-2),:) = [double(f(4*i-2))]
	values((4*i-1),:) = [double(f(4*i-1))]
	values((4*i),:) = [double(f(4*i))]	
end
F = values(:,1)
J = values(:,2:n+1)

