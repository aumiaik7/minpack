function [fvec,J] = trig(n,a)  
m=n;
  zero=0.d0;
  one=1.d0;
<<<<<<< HEAD
     vect=zeros(1,n);
values=zeros(n,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
      sum1 = zero;
for i=1:n
        x1(i)   = x(i);
        cx(i)  = cos(x1(i));
        sum1  = sum1 + cx(i);
end
=======
     vect=zeros(1,n);
values=zeros(n,n+1);
for i=1:n
	vect(:,i)=1;
	x(i)=valder(a(i),vect);
	vect=zeros(1,n);
end
      sum1 = zero;
for i=1:n
        x1(i)   = x(i);
        cx(i)  = cos(x1(i));
        sum1  = sum1 + cx(i);
end
>>>>>>> ea04d8095009d235b7f21b3e273cb893983b15d3
	v=n-sum1;
      for i=1:n
        x1(i)   = x(i);
        cx(i)  = cos(x1(i));
<<<<<<< HEAD
     	v1(i) = one - cx(i);
	v2(i) = i*v1(i);
	sx(i) = sin(x1(i));
	v3(i) = v+v2(i);
        f(i)=v3(i)-sx(i);
	values(i,:) = [double(f(i))]
      end
F = values(:,1)
J = values(:,2:n+1)
=======
     	v1(i) = one - cx(i);
	v2(i) = i*v1(i);
	sx(i) = sin(x1(i));
	v3(i) = v+v2(i);
        f(i)=v3(i)-sx(i);
	values(i,:) = [double(f(i))]
      end
F = values(:,1)
J = values(:,2:n+1)
>>>>>>> ea04d8095009d235b7f21b3e273cb893983b15d3