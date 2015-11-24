%function [fvec,J] = jensam(n,m,x,opt)
% **********************************************
% **********************************************
%
% function [fvec, J]= jensam(n,m,x,opt)
% Jenrich and Sampson function [6]
% Dimensions n=2,   m>=n
% Function definition 
%               f(x)=2+2i-(exp[ix1] + exp[ix2])
% Standard starting point x=(0.3,0.4)
% minima of f=124.362 at x1=x2=0.2578 for m=10
%
% Revised 10/23/94  PLK
% **********************************************
%{
J=zeros(m,n);

if ((opt==1) | (opt==3))
        for i=1:m
                fvec(i) =  (2+2*i-(exp(i*x(1))+exp(i*x(2)))) ;
        end
        fvec=fvec';
    else fvec='?';
end;

if ((opt==2) | (opt ==3))
        for i=1:m
                J(i,1)  =  (-i*exp(i*x(1))) ;
                J(i,2)  =  (-i*exp(i*x(2))) ;
        end
else
        J='?';
end;

if((opt<1)|(opt>3))
  disp(' Error: The option value is either <0 or >3') 
end
%}
function [fvec,J] = jensam(m,a)
values=zeros(m,3);
x=valder(a(1),[1 0]);
y=valder(a(2),[1 0]);
for i=1:m
	v0(i)=2*i;
	v1(i)=i*x;
	v2(i)=i*y;
	v3(i)=exp(v1(i));
	v4(i)=exp(v2(i));
	v5(i)=v3(i)+v4(i);
	v6(i)=v0(i)-v5(i);
	f(i)=2+v6(i);
	values(i,:) = [double(f(i))]
end
F = values(:,1)
J = values(:,2:3)
