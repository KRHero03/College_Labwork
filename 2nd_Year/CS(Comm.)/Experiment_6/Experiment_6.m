%%Aim: To compute the Fourier Coefficients for Exponential and Square Wave,
%and plot their magnitude and phase spectra

%% Exponential Wave

clc;
clear all;
close all;

T = pi;
N = 100;
t = -4*pi:0.01:4*pi;
w = (-N:N)*2*pi/T;

D = zeros(1,2*N+1);
for i=1:length(w)
    D(i) =(1/T)*integral(@(t)exp(-t/2).*exp(-1i*w(i)*t),0,T);
end

subplot(3,1,1);
stem(w,abs(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Magnitude');
title('Magnitude Spectrum of Exponential Wave');

subplot(3,1,2);
stem(w,angle(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Angle');
title('Phase Spectrum of Exponential Wave');

subplot(3,1,3);
[m,n] = size(t);
g = zeros(m,n);
for i=1:length(t)
    g(i) = sum(D.*(exp(1i*w*t(i))));
end
plot(t,g);
xlabel('Time');
ylabel('Magnitude');
title('Synthesis of Signal from Exponential Fourier Series');
    
%% Square Wave

clc;
clear all;
close all;

T = 2*pi;
N = 11;
t = -4*pi:0.01:4*pi;
w = (-N:N)*2*pi/T;

D = zeros(1,2*N+1);
for i=1:length(w)
    D(i) =(1/T)*integral(@(t)square(t).*exp(-1i*w(i)*t),0,T);
end

subplot(3,1,1);
stem(w,abs(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Magnitude');
title('Magnitude Spectrum of Square Wave');

subplot(3,1,2);
stem(w,angle(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Angle');
title('Phase Spectrum of Square Wave');

subplot(3,1,3);
[m,n] = size(t);
g = zeros(m,n);
for i=1:length(t)
    g(i) = sum(D.*(exp(1i*w*t(i))));
end
plot(t,g);
xlabel('Time');
ylabel('Magnitude');
title('Synthesis of Signal from Square Fourier Series');

%% Sine Wave

clc;
clear all;
close all;

T = 2*pi;
N = 11;
t = -4*pi:0.01:4*pi;
w = (-N:N)*2*pi/T;

D = zeros(1,2*N+1);
for i=1:length(w)
    D(i) =(1/T)*integral(@(t)sin(t).*exp(-1i*w(i)*t),0,T);
end

subplot(3,1,1);
stem(w,abs(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Magnitude');
title('Magnitude Spectrum of Sine Wave');

subplot(3,1,2);
stem(w,angle(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Angle');
title('Phase Spectrum of Sine Wave');

subplot(3,1,3);
[m,n] = size(t);
g = zeros(m,n);
for i=1:length(t)
    g(i) = sum(D.*(exp(1i*w*t(i))));
end
plot(t,g);
xlabel('Time');
ylabel('Magnitude');
title('Synthesis of Signal from Sine Fourier Series');

%% Cosine Wave

clc;
clear all;
close all;

T = 2*pi;
N = 11;
t = -4*pi:0.01:4*pi;
w = (-N:N)*2*pi/T;

D = zeros(1,2*N+1);
for i=1:length(w)
    D(i) =(1/T)*integral(@(t)cos(t).*exp(-1i*w(i)*t),0,T);
end

subplot(3,1,1);
stem(w,abs(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Magnitude');
title('Magnitude Spectrum of Cosine Wave');

subplot(3,1,2);
stem(w,angle(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Angle');
title('Phase Spectrum of Cosine Wave');

subplot(3,1,3);
[m,n] = size(t);
g = zeros(m,n);
for i=1:length(t)
    g(i) = sum(D.*(exp(1i*w*t(i))));
end
plot(t,g);
xlabel('Time');
ylabel('Magnitude');
title('Synthesis of Signal from Cosine Fourier Series');

%% Tangent Wave

clc;
clear all;
close all;

T = pi;
N = 11;
t = -4*pi:0.01:4*pi;
w = (-N:N)*2*pi/T;

D = zeros(1,2*N+1);
for i=1:length(w)
    D(i) =(1/T)*integral(@(t)tan(t).*exp(-1i*w(i)*t),0,T);
end

subplot(3,1,1);
stem(w,abs(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Magnitude');
title('Magnitude Spectrum of Tangent Wave');

subplot(3,1,2);
stem(w,angle(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Angle');
title('Phase Spectrum of Tangent Wave');

subplot(3,1,3);
[m,n] = size(t);
g = zeros(m,n);
for i=1:length(t)
    g(i) = sum(D.*(exp(1i*w*t(i))));
end
plot(t,g);
xlabel('Time');
ylabel('Magnitude');
title('Synthesis of Signal from Tangent Fourier Series');

%% Sawtooth Wave

clc;
clear all;
close all;

T = pi;
N = 11;
t = -4*pi:0.01:4*pi;
w = (-N:N)*2*pi/T;

D = zeros(1,2*N+1);
for i=1:length(w)
    D(i) =(1/T)*integral(@(t)sawtooth(t).*exp(-1i*w(i)*t),0,T);
end

subplot(3,1,1);
stem(w,abs(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Magnitude');
title('Magnitude Spectrum of Sawtooth Wave');

subplot(3,1,2);
stem(w,angle(D));
xlabel('Angular Frequency');
ylabel('Fourier Coefficient Angle');
title('Phase Spectrum of Sawtooth Wave');

subplot(3,1,3);
[m,n] = size(t);
g = zeros(m,n);
for i=1:length(t)
    g(i) = sum(D.*(exp(1i*w*t(i))));
end
plot(t,g);
xlabel('Time');
ylabel('Magnitude');
title('Synthesis of Signal from Sawtooth Fourier Series');