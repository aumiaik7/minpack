%Brown almost linear function[27]
function [fvec,J]= ba1(n,a)
m=n;
v=n+1;
for i=1:n
	x(i)=a(i);
end
sum1=0;
        for j=1:n
                sum1=sum1 + x(j)
        end;
mul1=1;
        for j=1:n
                mul1=mul1 * x(j)
        end;
for i=1:n-1
		v1(i)=x(i)+sum1
                f(i)=v1(i)-v
end
    f(n)=mul1-1
  f=f'
