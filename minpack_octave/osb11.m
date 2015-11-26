%function [fvec,J]  =  osb1(n,m,x,option)

% *******************************************************
% function [fvec,J] = osb1(n,m,x,option)
%  Osborne 1 function   [17]
% Dimensions: n=5 , m=33
% Function Definition:
%       f(x)=y(i)-(x1+x2*exp[-t(i)x4]+x3*exp[-t(i)x5])
%       where t(i)=10(i-1)
% Standard starting point: (0.5,1.5,-1,0.01,0.02)
% Minima of f=5.46489...10^(-5)
%           at (.3754,1.9358,-1.4647,0.01287,0.02212)
%
% Revised  11/94                PLK
% *******************************************************
function [fvec,J]  =  osb11(a)
    % global FIRSTIME y1;

      x1 = a(1);
      x2 = a(2);
      x3 = a(3);
      x4 = a(4);
      x5 = a(5);

%if (FIRSTIME),y1=[];
      y1( 1) = 0.844d0;
      y1( 2) = 0.908d0;
      y1( 3) = 0.932d0;
      y1( 4) = 0.936d0;
      y1( 5) = 0.925d0;  
      y1( 6) = 0.908d0;
      y1( 7) = 0.881d0;
      y1( 8) = 0.850d0;
      y1( 9) = 0.818d0;
      y1(10) = 0.784d0;
      y1(11) = 0.751d0;
      y1(12) = 0.718d0;
      y1(13) = 0.685d0;
      y1(14) = 0.658d0;
      y1(15) = 0.628d0;
      y1(16) = 0.603d0;
      y1(17) = 0.580d0;
      y1(18) = 0.558d0;
      y1(19) = 0.538d0;
      y1(20) = 0.522d0;
      y1(21) = 0.506d0;
      y1(22) = 0.490d0;
      y1(23) = 0.478d0;
      y1(24) = 0.467d0;
      y1(25) = 0.457d0;
      y1(26) = 0.448d0;
      y1(27) = 0.438d0;
      y1(28) = 0.431d0;
      y1(29) = 0.424d0;
      y1(30) = 0.420d0;
      y1(31) = 0.414d0;
      y1(32) = 0.411d0;
      y1(33) = 0.406d0;
      y1 = y1';
     % FIRSTIME=0;
     %end;
%{
      im1 = 0.0d0;
      for i = 1: m
        ti   =  im1*10.d0;
        e4 = exp(-ti*x4);
        e5 = exp(-ti*x5);
        t2 = x2*e4;
        t3 = x3*e5;
	if (option==1 | option==3)
          fvec(i) = (x1 + t2 + t3) - y1(i);
      else fvec='?';
	end
	if (option ==2 | option ==3)
        	J( i, 1) = 1.d0;
        	J( i, 2) =  e4;
        	J( i, 3) =  e5;
        	J( i, 4) = -ti*t2;
        	J( i, 5) = -ti*t3;
        else J='?';
	end
        im1 = i;
      end
      fvec = fvec';


% x0 = [.5,1.5,-1,.01,.02]';
%}

im1 = 0.0d0;
      for i = 1: 33
        t(i)   =  im1*10.d0;
	e1(i) = -t(i);
	e2(i) = e1(i)*x4;
        e3(i) = exp(e2(i));
	e4(i) = e1(i)*x5;
        e5(i) = exp(e4(i));
        t2(i) = x2*e3(i);
        t3(i) = x3*e5(i);
	t4(i) = t2(i)+t3(i);
	t5(i) = x1+t4(i);
	f(i) = y1(i)-t5(i);
          %fvec(i) = (x1 + t2 + t3) - y1(i);
        im1 = i;
      end
      fvec = f'
