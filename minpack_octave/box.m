%function [fvec,J] = box(n,m,x,opt)

% *****************************************************************
% *****************************************************************
% Function [fvec,J] = box(n,m,x,opt)
% Box three-dimensional function      [12]
% Dimensions:   n=3     m=10
% Function definition:
%       f(x)= exp[-t(i)x1]-exp[-t(i)x2]-x3[exp[-t(i)]-exp[-10t(i)]]
%       where t(i)=(0.1)i
% Standard Starting Points: (0,10,20)
% Minima of f=0 at (1,10,1), (10,1,-1) and wherever x1=x2 and x3-0
% ******************************************************************
%{
for i = 1:m

  t(i) = .1*i;
     
  if((opt==1) | (opt==3))
     fvec(i) =  exp(-t(i)*x(1))-exp(-t(i)*x(2))-x(3)*(exp(-t(i))-exp(-10*t(i)));
 else fvec='?';
  end;

  if((opt ==2) | (opt ==3))
     J(i,1)  =  -t(i)*exp(-t(i)*x(1));
     J(i,2)  =  t(i)*exp(-t(i)*x(2));
     J(i,3)  = -(exp(-t(i))-exp(-10*t(i)));
 else J='?';
  end;

end;
fvec=fvec';
J
if((opt<1)|(opt>3))
        disp('Error: Option value sent to  BOX.M is either <1 or >3');
end;
%}
function [fvec,J] = box(m,a)
	values=zeros(m,4);
	x1=valder(a(1),[1 0 0]);
	x2=valder(a(2),[0 1 0]);
	x3=valder(a(3),[0 0 1]);
	for i = 1:m

  		t(i) = .1*i;
		v1(i) = -t(i);
		v2(i)= v1(i)*x1;
		v3(i)= exp(v2(i));
		v4(i)= v1(i)*x2;
		v5(i)= exp(v4(i));
		v6(i)= exp(v1(i));
		v7(i)= 10*v1(i);
		v8(i)= exp(v7(i));
		v9(i) = v6(i)-v8(i);
		v10(i)= x3*v9(i);
		v11(i)=v3(i)-v5(i);
     		fvec(i) =  v11(i)-v10(i);
  	end;
fvec=fvec'
