% Broyden tridiagonal function
% ---------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=trid(n,m,x,option)
% Dimensions -> n=variable, m=n
% Problem no. 30
% Standard starting point -> x=(-1,..,-1)
% Minima -> f=0 
%                                     
% 11/21/94 by Madhu Lamba  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%{
function [fvec,J] = trid(n,m,x,option)  

J=zeros(m,n);
for i=1:n

   if (option==1 | option==3)
      x(n+1)=0;
      if (i==1)
         fvec(i)=(3-2*x(i))*x(i)-2*x(i+1)+1;
      elseif (i==n)
         fvec(i)=(3-2*x(i))*x(i)-x(i-1)+1;
      else
         fvec(i)=(3-2*x(i))*x(i)-x(i-1)-2*x(i+1)+1;
      end; 
  else fvec='?';
   end;       

   if (option==2 | option==3)
      J(i,i)=3-4*x(i);
      if (i<n)
         J(i,i+1)=-2;
         J(i+1,i)=-1;
      end;
  else J='?';
   end;
end; 

if (option==1 | option==3)
   fvec=fvec';
J
else fvec='?';
end;
%}function [fvec,J] = trid(n,a)
m=n;
two=2.d0;
three=3.d0;
vect=zeros(1,n);
values=zeros(n,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
x(n+1)=valder(0,vect);
for i=1:n         
	v1(i)=two*(x(i));
	v2(i)=two*x(i+1);
	v3(i)=three-v1(i);
	v4(i)=v3(i)*x(i);
      if (i==1)
	v5(i)=v4(i)-v2(i);
         f(i)=v5(i)+1;
      elseif (i==n)
	v5(i)=v4(i)-x(i-1);
         f(i)=v5(i)+1;
      else
	 v5(i)=v4(i)-x(i-1);
         v6(i)=v5(i)-v2(i);
         f(i)=v6(i)+1;
      end; 
     values(i,:) = [double(f(i))];
end
F = values(:,1)
J = values(:,2:n+1)

