%function [fvec,J] = bd(n,m,x,opt)

%  function [fvec,J] = bd(n,m,x,opt)
%  Brown and Dennis function  [16]
%  Dimensions:  n=4,  m=20
%  Function Definition:
%       f(x)=(x1 + t(i)x2- exp[t(i)])^2 +(x3 + x4sin(t(i))- cos(t(i)))^2
%       where t(i)=i/5
%  Standard starting point (25,5,-5,-1)
%  Minima of f=85822.2... if m=20
%
%  Revised  11/94               PLK
%
%{  
      two = 2.d0
      point2 = .2d0
      x1 = x(1);
      x2 = x(2);
      x3 = x(3);
      x4 = x(4);

     if opt==1
	for i = 1: m
        	ti   = (i)*point2;
        	ei   = exp(ti);
        	si   = sin(ti);
       		ci   = cos(ti);
        	fvec(i) = (x1 + ti*x2 - ei)^2 + (x3 + x4*si - ci)^2;
	end
	fvec=fvec'; J='?';

     elseif opt==2
	for i=1:m
        	ti = (i)*point2;
        	ei = exp(ti);
        	si = sin(ti);
        	ci = cos(ti);
        	f1 = two*(x1 + ti*x2 - ei);
        	f3 = two*(x3 + x4*si - ci);
        	J( i, 1) = f1;
        	J( i, 2) = f1 * ti;
        	J( i, 3) = f3;
        	J( i, 4) = f3 * si; fvec='?';
	end

     elseif opt==3
	for i=1:m
        	ti = (i)*point2;
        	ei = exp(ti);
        	si = sin(ti);
        	ci = cos(ti);
        	f1 = two*(x1 + ti*x2 - ei);
        	f3 = two*(x3 + x4*si - ci);
        	fvec(i) = (x1 + ti*x2 - ei)^2 + (x3 + x4*si - ci)^2;
        	J( i, 1) = f1
        	J( i, 2) = f1 * ti
        	J( i, 3) = f3
        	J( i, 4) = f3 * si
	end
	fvec=fvec';

     else 
	error('Error: bd.m - Invalid option')
     end; 
%}
function [fvec,J] = bd1(m,a)
values=zeros(m,5);
      two = 2.d0
      point2 = .2d0
        x1=valder(a(1),[1 0 0 0]);
	x2=valder(a(2),[0 1 0 0]);
	x3=valder(a(3),[0 0 1 0]);
	x4=valder(a(4),[0 0 0 1]);

	for i = 1: m
        	t(i)   = (i)*point2;
        	e(i)   = exp(t(i));
        	s(i)   = sin(t(i));
       		c(i)   = cos(t(i));
		v1(i) = x4*s(i);
		v2(i) = v1(i)- c(i);
		v3(i) = x3+v2(i);
		v4(i) = v3(i)^2;
		v5(i) = t(i)*x2;
		v6(i) = x1+v5(i);
		v7(i) = v6(i)-e(i);
		v8(i) = v7(i)^2;
        	f(i) = v8(i) + v4(i);
		values(i,:) = [double(f(i))];
end
F = values(:,1)
J = values(:,2:5)
