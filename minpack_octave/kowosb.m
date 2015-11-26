%function [fvec,J] = kowosb(n,m,x,opt)

% ***********************************************************
% Function [fvec, J]=kowosb(n,m,x,opt)
% Kowalik and Osborne function    [15]
% Dimensions:     n=4   m=11
% Function Definition:
%       f(x)= y(i) - [x1(u^2 +u*x2) / (u^2 + u*x3 + x4)]
% Standard starting point: (0.25,0.39,0.415,0.39)
% Minima of f= 3.07505...10^-4 and
%           f= 1.02734...10^-3  at (inf,-14.07...,-inf,-inf)
%
% Coded in Matlab   October 1994        PLK
% **********************************************************
%{
y     = [.1957  .1947  .1735  .1600  .0844  .0627  
         .0456  .0342  .0323  .0235  .0246      0]' ;

u     = [4.0000  2.0000  1.0000  0.5000  0.2500  0.1670
         0.1250  0.1000  0.0833  0.0714  0.0625       0]' ;
         


for i = 1:m
   c1 = u(i)^2 + u(i)*x(2);
   c2 = (u(i)^2 + u(i)*x(3) +x(4));
  
   if((opt==1)|(opt==3))
    fvec(i) =  y(i)-(x(1)*c1)/c2;
else
    fvec='?';
   end;

   if((opt==2)|(opt==3))
    J(i,1) =  -c1/c2;
    J(i,2) = (-x(1)*u(i) ) / c2;
    J(i,3) = x(1)*c1*(c2^(-2))*u(i); 
    J(i,4) = x(1)*c1*(c2^(-2));
else J='?';
   end;
end;

fvec=fvec';
J
if((opt<1)|(opt>3))
        disp('Error: Option value for KOWOSB.M is either <1 or >3');
end;
 %}   function [fvec,J] = kowosb1(a)
values=zeros(11,5);
y     = [.1957  .1947  .1735  .1600  .0844  .0627  
         .0456  .0342  .0323  .0235  .0246      0]' ;

u     = [4.0000  2.0000  1.0000  0.5000  0.2500  0.1670
         0.1250  0.1000  0.0833  0.0714  0.0625       0]' ;
x1=valder(a(1),[1 0 0 0]);
x2=valder(a(2),[0 1 0 0]);
x3=valder(a(3),[0 0 1 0]);
x4=valder(a(4),[0 0 0 1]);
       
for i = 1:11
	v1(i)=u(i)^2;
	v2(i)=u(i)*x2;
	v3(i)=v1(i)+v2(i);
	v4(i)=x1*v3(i);
	v5(i)=u(i)*x3;
	v6(i)=v1(i)+v5(i);
	v7(i)=v6(i)+x4;
	v8(i)=v4(i)/v7(i);
	f(i) =  y(i)-v8(i);
	values(i,:) = [double(f(i))];
end

F = values(:,1)
J = values(:,2:5)
