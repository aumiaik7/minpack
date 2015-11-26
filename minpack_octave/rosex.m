% Extended Rosenbrock function 
% ---------------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=rosex(n,m,x,option)
% Dimensions -> n=variable but even, m=n 
% Problem no. 21            
% Standard starting point -> x=(s(j)) where 
%                            s(2*j-1)=-1.2, 
%                            s(2*j)=1 
% Minima -> f=0 at (1,.....,1)              
%                                     
% 11/21/94 by Madhu Lamba  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%{
function [fvec,J] = rosex(n,m,x,option)  

J=zeros(m,n);

for i=1:m/2
i
   if (option==1 | option==3)
        fvec(2*i-1)=10*(x(2*i)-x(2*i-1)^2);
        fvec(2*i)=1-x(2*i-1);
    else fvec='?';
   end;        

   if (option==2 | option==3)
        J(2*i-1,2*i-1) = -20*x(2*i-1);
        J(2*i-1,2*i)   = 10; 
        J(2*i,2*i-1)   = -1;
    else J='?';
   end;

end;

if (option==1 | option==3)
	fvec=fvec'
else fvec='?';
end;
%}
m=n;
vect=zeros(1,n);
values=zeros(n,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
	
for i=1:m/2
	t1(i)=x(2*i-1)^2;
	t2(i)=x(2*i)-t1(i);
        f(2*i-1)=10*t2(i);
        f(2*i)=1-x(2*i-1);
        values((2*i-1),:) = [double(f(2*i-1))];
	values((2*i),:) = [double(f(2*i))];
	
end
F = values(:,1)
J = values(:,2:n+1)