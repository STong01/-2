function varargout=saxplaxliu(varargin)
clc,clear
x0=0;xn=0.5;y0=1;h=0.1;
[y,x]=lgkt4j(x0,xn,y0,h);
n=length(x);
fprintf('i x(i) y(i)\n');
for i=1:n
fprintf('%2d %4.4f %4.4f\n',i,x(i),y(i));
end
function z=f(x,y) 
z=x+y;
function [y,x]=lgkt4j(x0,xn,y0,h)
x=x0:h:xn;
n=length(x);
y1=x;
y1(1)=y0;
for i=1:n-1
K1=f(x(i),y1(i));
K2=f(x(i)+h/2,y1(i)+h/2*K1);
K3=f(x(i)+h/2,y1(i)+h/2*K2);
K4=f(x(i)+h,y1(i)+h*K3);
y1(i+1)=y1(i)+h/6*(K1+2*K2+2*K3+K4);
end
y=y1;