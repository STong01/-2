function F=shuzhi(X)
x=X(1);
y=X(2);
F=zeros(1,2);
F(1)=x.^2-2*x-y+0.5;
F(2)=x.^2+4*y.^2-4
end