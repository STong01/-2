function m=maspline(x,y,dy0,dyn,xx)
n=length(x)-1;
h=diff(x);lambda=h(2:n)./(h(1:n-1)+h(2:n));mu=1-lambda;
theta=3*(lambda.*diff(y(1:n-1))./h(1:n-1)+mu.*diff(y(2:n+1))./h(2:n));
theta(1)=theta(1)-lambda(1)*dy0;
theta(n-1)=theta(n-1)-lambda(n-1)*dyn;
dy=machase(lambda,2*ones(1:n-1),mu,theta);
m=[dy0;dy;dyn];
if nargin>=5
    s=zeros(size(xx));
    for i=1:n
        if i==1
            kk=find(xx<=x(2));
        else if i==n
                kk=find(xx>x(n));
            else 
                kk=find(xx>x(i)&xx<=x(i+1));
            end
            xbar=(xx(kk)-x(i))/h(i);
            s(kk)=alpha0(xbar)*y(i)+alpha1(xbar)*y(i+1)...
                +h(i)*beta0(xbar)*m(i)+h(i)*beta1(xbar)*m(i+1);
        end
        m=s;
    end
    function x=machase(a,b,c,d)
    n=length(a);
    for k=2:n
        b(k)=b(k)-a(k)/b(k-1)*c(k-1);
        d(k)=d(k)-a(k)/b(k-1)*d(k-1);
    end
    x(n)=d(n)/b(n);
    for k=n-1:-1:1
        x(k)=(d(k)-c(k)*x(k+1))/b(k);
    end
    x=x(:);
    %������
    functinon y=alpha0(x)
    y=2*x,^3-3*x.^2+1;
    function y=alpha1(x)
    y=-2*x.^3+3*x.^2;
    function y=beta0(x)
    y=x.^3-2*x.^2+x;
    function y=beta1(x)
    y=x.^3-x.^2;