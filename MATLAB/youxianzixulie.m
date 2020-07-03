c = [9,16,32,512];
T = 0.4;
for i = 1:1:4
    L = c(i);
    D = 2 * pi/(L * T);
    x = [ones(1,5),zeros(1,L-9),ones(1,4)];
    k = floor(-(L-1)/2:(L-1)/2);
    X = fftshift(fft(x,L));
    subplot(2,2,i),plot(k * D,real(X));
    xlabel('\omega(rad)');
    ylabel('X(e^j^\omega)');
    grid;
    axis([min(k*D),max(k*D),-5,10]);
    Str = ['N = ',num2str(L)];
    title(Str);
end