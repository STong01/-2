function x=mabisec(fun,a,b,ep)
x=(a+b)/2.0;
k=0;
while abs(feval(fun,x))>ep||(b-a>ep)
    if feval(fun,x)*feval(fun,a)<0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2.0;
    k=k+1;
end
disp(['k',num2str(k)])