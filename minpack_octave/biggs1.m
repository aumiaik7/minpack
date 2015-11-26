%function [fvec,J] = biggs(n,m,x,opt)

% ******************************************
%  function [fvec,J] = biggs(n,m,x,opt)
%  Biggs EXP6 function   [18]
%  Dimensions :  n=6,  m=13
%  Standard starting point (1,2,1,1,1,1)
%  Minima of f=5.65565...10^(-3)   if m=13
%            f=0 at (1,10,1,5,4,3)
%
%  Revised  11/94               PLK
% ******************************************
%{
J=zeros(m,n);

for i = 1:m
  t(i) = .1*i;
  y(i) = exp(-t(i))-5*exp(-10*t(i))+3*exp(-4*t(i));

 if((opt==1) | ( opt==3))
  fvec(i) = x(3)*exp(-t(i)*x(1))-x(4)*exp(-t(i)*x(2))+x(6)*exp(-t(i)*x(5))-y(i);
else fvec='?';
 end;

 if((opt==2) | (opt==3))
  J(i,1)  = -t(i)*x(3)*exp(-t(i)*x(1));   
  J(i,2)  =  t(i)*(x(4))*exp(-t(i)*x(2));
  J(i,3)  = exp(-t(i)*x(1));
  J(i,4)  = -exp(-t(i)*x(2));
  J(i,5)  = x(6)*(-t(i))*exp(-t(i)*x(5));
  J(i,6)  = exp(-t(i)*x(5));
else J='?';
 end;

end; 
fvec=fvec';

if((opt<1) | (opt>3))
        disp('Error: Option value sent to BIGGS.M is either <1 or >3');
end;
%}function [fvec,J] = biggs1(m,a)
x1=a(1);
x2=a(2);
x3=a(3);
x4=a(4);
x5=a(5);
x6=a(6);
for i = 1:m
        t(i) = .1*i;
	t1(i)= -t(i);
	t2(i)= 10*t1(i);
	t3(i)= 4*t1(i);
	t4(i)= exp(t2(i));
	t5(i)= exp(t3(i));
	t6(i)= exp(t1(i));
	t7(i)= 5*t4(i);
	t8(i)= 3*t5(i);
	t9(i)= t6(i)-t7(i);
	y(i) = t9(i)+t8(i);
	t10(i) = x1*t1(i);
	t11(i) = x2*t1(i);
	t12(i) = x5*t1(i);
	t13(i)= exp(t10(i));
	t14(i)= exp(t11(i));
	t15(i)= exp(t12(i));
	t16(i) = x3*t13(i);
	t17(i) = x4*t14(i);
	t18(i) = x6*t15(i);
	t19(i)= t16(i)-t17(i);
	t20(i) = t19(i)+t18(i);
  	f(i) = t20(i)-y(i);
	
end; 
fvec=f'
