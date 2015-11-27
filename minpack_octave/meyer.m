%function [fvec,J] = meyer(n,m,x,opt)

% ************************************************
% ************************************************             
% function [fvec,J]= meyer(n,m,x,opt)
% Meyer function   [10]
% Dimensions   n=3   m=16
% Function definition:
%       f(x) = x(1)*exp[x(2)/(t(i) + x(3))]-y(i)
%       where t(i)= 45 + 5i
% Standard starting point at x=(0.02,4000,250)
% Minima of f=87.9458...
%
% Revised 10/23/94      PLK
% ************************************************
%{

      zero = 0.d0;
      one = 1.d0;

      y = [ 34780.d0
      28610.d0
      23650.d0
      19630.d0
      16370.d0
      13720.d0
      11540.d0
      9744.d0
      8261.d0
      7030.d0
      6005.d0
      5147.d0
      4427.d0
      3820.d0
       3307.d0
       2872.d0 ]' ;
      
      x1 = x(1);
      x2 = x(2);
      x3 = x(3);

    if opt==1
      for i = 1: m
        ti = (45+5*i);
        di = ti + x3;
        ei = exp(x2/di);
        fvec(i) = (x1 * ei) - y(i);
      end
      fvec=fvec'; J='?';

    elseif opt==2
      for i = 1: m
        ti = (45+5*i);
        di = ti + x3;
        qi = one / di;
        ei = exp(x2*qi);
        si = x1*qi*ei;
        J(i,1) =  ei;
        J(i,2) =  si;
        J(i,3) = -x2*qi*si; fvec='?';
      end

     elseif opt==3
      for i = 1: m
        ti = (45+5*i);
        di = ti + x3;
        qi = one / di;
        ei = exp(x2*qi);
        si = x1*qi*ei;
        fvec(i) = (x1*ei) - y(i);
        J(i,1) =  ei;
        J(i,2) =  si;
        J(i,3) = -x2*qi*si;
      end
      fvec=fvec';
J
     else
        disp('Error: Option value sent to MEYER.M is either <1 or >3');
     end;
%}
function [fvec,J] = meyer(a)

zero = 0.d0;
      one = 1.d0;
values=zeros(16,4);
      y = [ 34780.d0
      28610.d0
      23650.d0
      19630.d0
      16370.d0
      13720.d0
      11540.d0
      9744.d0
      8261.d0
      7030.d0
      6005.d0
      5147.d0
      4427.d0
      3820.d0
      3307.d0
      2872.d0 ]' ;
      
        x1 = valder(a(1),[1 0 0]);
	x2 = valder(a(2),[0 1 0]);
	x3 = valder(a(3),[0 0 1]);

for i = 1: 16
        ti = (45+5*i);
	
        z1(i) = ti + x3;
        z2(i) = x2/z1(i);
	z3(i) = exp(z2(i));
	z4(i) = x1*z3(i);
        f(i) = z4(i) - y(i);
	values(i,:) = [double(f(i))]
end;
F = values(:,1)
J = values(:,2:4)
