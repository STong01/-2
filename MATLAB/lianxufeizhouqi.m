T0 = [0.05,0.02,0.01,0.01];
L0 = [20,20,20,30];
for i = 1:4
    T = T0(i);
    N = L0(i)/T0(i);
    D = 2 * pi/(N*T);
n = 0:N-1;
x = exp(-5*n*T);
    k = floor(-(N-1)/2:(N-1)/2);
    X = T * fftshift(fft(x));
    [i,X(i)]
    subplot(2,2,i),plot(k*D,abs(X));
    xlabel('Ä£Äâ½ÇÆµÂÊ(rad/s)');
    ylabel('·ù¶È');
    grid;
    axis([min(k*D),max(k*D),0,inf]);
    str = ['T = ',num2str(T),'N = ',num2str(N)];
    title(str);
end