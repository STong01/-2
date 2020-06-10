function C=lspoly(X,Y,M)
n=length(X);
b=zeros(1:M+1);
A=zeros(n,M+1);
for k=1:M+1
    A(:,k)=X'.^(k-1);
end
a=A'*A;
b=A'*Y';
C=a\b;
C=flipud(C);