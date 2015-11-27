%function [fvec,J] = gulf(n,m,x,opt)

% ***************************************************
% ***************************************************
% function [fvec, J]= gulf(n,m,x,opt)
% Gulf research and development function      [11]
% Dimensions  n=3,  n=<m=<100
% Function definition:
%       f(x)= exp[-(| y(i)mi x(2)|^x(3) / x(1))- t(i)
%       where t(i) = i/100
%       and y(i)=25 +(-50 ln(t(i))^2/3)
% Standard starting point x=(5,2.5,0.15)
% minima of f=0 at (50,25,1.5)
%
% Revised 10/23/94      PLK
% *************************************************** 
%{
	zero = 0.d0;
	one = 1.d0;
	point1 = .01d0;
	twnty5 = 25.d0; 
	fifty = 50.d0;

      x1 = x(1);
      x2 = x(2);
      x3 = x(3);
      if (x1 == zero) 
 	disp(' +++ singularity in gulf function evaluation')
      end
      x1inv = one / x1;
      two3rd = 2.d0 / 3.d0;

      for i = 1: m
        ti       = (i)*point1;
        yi       = twnty5 + (-fifty*log(ti)) ^ two3rd;
        ai       = yi - x2;

      	if((opt==1)|(opt==3))
           fvec(i)  = exp(-((abs(ai)^x3)/x1)) - ti;
       else fvec='?';
        end;

        if((opt==2)|(opt==3))
           av = abs(ai);
           bi = av ^ x3;
           ci = bi*x1inv;
           ei = exp(-ci);
           d1 =   ci * x1inv;
           d2 =   x3 * x1inv * av^(x3 - one);
           d3 = - log(av) * ci;
           J(i,1) = d1 * ei;
           if (ai >= zero)  
		J(i,2) =  d2 * ei;
           else
		J(i,2) = -d2 * ei;
           end
           J(i,3) = d3 * ei;
       else J='?';
       end
  end;
  fvec = fvec';

if((opt<1)|(opt>3))
       disp('ERRROR: option value sent to GULF.M is either <1 or >3');
end;
%}
function [fvec,J] = gulf1(m,a)	zero = 0.d0;
	one = 1.d0;
	point1 = .01d0;
	twnty5 = 25.d0; 
	fifty = -50.d0;
	values=zeros(m,4);
      if (a(1) == zero) 
 	disp(' +++ singularity in gulf function evaluation')
      end
        x1 = a(1);
	x2 = a(2);
	x3 = a(3);
      
      x1inv = one / x1;
      two3rd = 2.d0 / 3.d0;

      for i = 1: m
        t(i)  = (i)*point1;
	y1(i) = log(t(i));
	y2(i) = fifty*y1(i);
	y3(i) = y2(i)^ two3rd;
        y(i)  = twnty5 + y3(i);
        a1(i)  = y(i) - x2;
	a11(i) = abs(a1(i));
	a2(i) = a11(i)^x3;
	a3(i) = a2(i)/x1;
	a4(i) = -a3(i);
	a5(i) = exp(a4(i));
        f(i)  = a5(i) - t(i);
     end	fvec=f'
