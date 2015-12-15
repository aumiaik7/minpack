%Brown almost linear function[27]
function [fvec,J]= ba(n,a)
m=n;
v=n+1;
vect=zeros(1,n);
values=zeros(m,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
sum1=valder(0,vect);
        for j=1:n
                sum1=sum1 + x(j);
        end;
mul1=valder(1,vect);
        for j=1:n
                mul1=mul1 * x(j);
        end;
for i=1:n-1
		v1(i)=x(i)+sum1;
                f(i)=v1(i)-v;
		values(i,:) = [double(f(i))]
end
    f(n)=mul1-1;
        values(n,:) = [double(f(n))]
F = values(:,1)
J = values(:,2:n+1)
