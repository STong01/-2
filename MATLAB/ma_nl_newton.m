function [p,iter,err]=ma_nl_newton(F,J,p,delta,epsilon,max1)
y=feval(F,p);
for k=1:max1
    j=feval(J,p);
    q=p-(j\y')';
    z=feval(F,q);
    err=norm(q-p);
    relerr=err/(norm(q)+eps);
    p=q;
    y=z;
    iter=k;
    if(err<delta)|(relerr<delta)|(abs(y)<epsilon)
        break
    end
end
end