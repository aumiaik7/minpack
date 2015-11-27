% Penalty II  function
% ------------------- 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% function [fvec,J]=pen2(n,m,x,option)
% Dimensions -> n=variable, m=2*n
% Problem no. 24             
% Standard starting point -> x=(1/2,......,1/2)
% Minima -> f=9.37629...10^(-6)  if n=4
%           f=2.93660...10^(-4)  if n=10            
%                                     
% 11/21/94 by Madhu Lamba  
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%{
function [fvec,J] = pen2(n,m,x,option)  


J=zeros(m,n);
if (option==1 | option==3)
   fvec(1)=x(1)-0.2;
else fvec='?';
end;

if (option==2 | option==3)
   J(1,1)=1;
else J='?';
end;

if(n>=2)

   for i=2:n
     y(i)=exp(i/10)+exp((i-1)/10);

     if (option==1 | option==3)
        fvec(i)=sqrt(1.e-5)*(exp(x(i)/10)+exp(x(i-1)/10)-y(i));
    else fvec='?';
     end;        

     if (option==2 | option==3)
	J(i,i)   = sqrt(1.e-5)*exp(x(i)/10)*(1/10);
        J(i,i-1) = sqrt(1.e-5)*exp(x(i-1)/10)*(1/10);
    else J='?';
     end;
   end;
  
   for i=n+1:(2*n-1)
       
     if (option==1 | option==3)
        fvec(i)=sqrt(1.e-5)*(exp(x(i-n+1)/10)-exp(-1/10));
    else fvec='?';
     end;
 
     if (option==2 | option==3)
	J(i,i-n+1) = sqrt(1.e-5)*exp(x(i-n+1)/10)*(1/10);
else J='?';
     end; 
   end;
end;

if (option==1 | option==3) 

    sum=0;
    for j=1:n
        sum=sum+(n-j+1)*x(j)^2;
    end;
    fvec(2*n)=sum-1; 
else fvec='?';
end;
if (option==2 | option==3)
    for j=1:n
        J(m,j) = (n-j+1)*2*x(j);
    end;
else J='?';
end;
if (option==1 | option==3)
   fvec=fvec';
end;
%}
function [fvec,J] = pen21(n,a)
m=2*n; 
	for i=1:n
	   x(i)=a(i);
	end
fvec(1)=x(1)-0.2;
sa=sqrt(1.e-5);
if(n>=2)
   for i=2:n
	t1(i)=exp(i/10);
	t2(i)=exp((i-1)/10); 
        y(i)=t1(i)+t2(i);  
	v1(i)=x(i)/10;
	v2(i)=x(i-1)/10;  
	v3(i)=exp(v1(i));
	v4(i)=exp(v2(i));
	v5(i)=v3(i)+v4(i);
	v6(i)=v5(i)-y(i);
        fvec(i)=sa*v6(i);
   end;
  ep=exp(-1/10);
   for i=n+1:(2*n-1)
	v7(i)=x(i-n+1)/10;
	v8(i)=exp(v7(i));
	v9(i)=v8(i)-ep;
        fvec(i)=sa*v9(i); 
   end;
end;sum=0;
    for j=1:n
	v10(j)=n-j;
	v11(j)=v10(j)+1;
	v12(j)=x(j)^2;
	v13(j)=v11(j)*v12(j);
        sum=sum+v13(j);
    end;
    fvec(2*n)=sum-1; 
   fvec=fvec'
