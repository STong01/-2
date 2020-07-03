NN=[100,200,500,800];
for i=1:4
N = NN(i);
T = 0.05;
n = 1:N;
D = 2*pi/(N*T);
xa = cos(5*n*T);
Xa = T*fftshift(fft(xa,N));
Xa(1)
k = floor(-(N-1)/2:(N-1)/2);
TITLE = sprintf('N = %i,L = %i',N,N*T);
subplot(2,2,i),plot(k*D ,abs(Xa));
xlabel('\omega');
ylabel('|X(j\omega)|');
grid;
axis([-20,20,0,max(abs(Xa))+2]);
title(TITLE);
end