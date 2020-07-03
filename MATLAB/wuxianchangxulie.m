T = 0.4;
r = 1;
beta = 3e-3;
b = 0.01;
while b>beta
    N1= 2^r;
    n1 = 0:N1-1;
    x1 = 0.5.^n1;
    X1 = fft(x1);
    N2 = 2*N1;
    n2 = 0:N2-1;
    x2 = 0.5.^n2;
    X2 = fft(x2);
    k1 = 0:N1/2-1;
    k2 = 2*k1;
    d = max(abs(X1(k1+1)-X2(k2+1)));
    X1m = max(abs(X1(k1+1)));
    b = d/X1m;
    r= r+1;
end
k = floor(-(N2-1)/2:(N2-1)/2);
D = 2* pi/(N2*T);
subplot(121),plot(k*D,abs(fftshift(X2)));
title('������');
xlabel('ģ���Ƶ��(rad/s)');
ylabel('����');
grid;
subplot(122),plot(k*D,angle(fftshift(X2)));
title('��λ��')
xlabel('ģ���Ƶ��(rad/s)');
ylabel('���');
grid