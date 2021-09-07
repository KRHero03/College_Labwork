% Experiment 8: Amplitude Modulation and Demodulation
% Author: Krunal Rank
% RollNo: U18CO081

%% Part 1: Amplitude Modulation
clc;
clear all;
close all;

f_s = 100;
t = -10:(1/f_s):10;

f_m = 1;
f_c = 10;

w_m = 2 * pi * f_m;
w_c = 2 * pi * f_c;

A_m = 10;
A_c = A_m;

m = A_m * cos(w_m*t);
c = A_c * cos(w_c*t);

s = m.*c;

subplot(3,1,1);
plot(t,m);
xlabel('t (in S)');
ylabel('m(t) (in V)');
title('Message Signal');

subplot(3,1,2);
plot(t,c);
xlabel('t (in S)');
ylabel('c(t) (in V)');
title('Carrier Signal');

subplot(3,1,3);
plot(t,s);
xlabel('t (in S)');
ylabel('s(t) (in V)');
title('Modulated Signal');

%% Part 2: Frequency Spectrum of Modulated Signal

n = length(t);
df = f_s/n;

fp = -f_s/2:df:f_s/2 - df;

fourier_m = fftshift(fft(m));
fourier_c = fftshift(fft(c));
fourier_s = fftshift(fft(s));

subplot(3,1,1);
plot(fp,fourier_m);
xlabel('f (in Hz)');
ylabel('m(f) (in V)');
title('Message Signal');

subplot(3,1,2);
plot(fp,fourier_c);
xlabel('f (in Hz)');
ylabel('c(f) (in V)');
title('Carrier Signal');

subplot(3,1,3);
plot(fp,fourier_s);
xlabel('f (in Hz)');
ylabel('s(f) (in V)');
title('Modulated Signal');

%% Part 3: Demodulation of AM Signal

s_1 = s.*c;

[b, a] = butter(3,f_m/f_s,'low');

[y,z] = filter(b,a,s_1);
mu = mean(y);
y = filter(b,a,y,z)-mu;
subplot(2,1,1);
plot(t,s_1);
xlabel('t (in S)');
ylabel('s(t)*c(t) (in V^2)');
title('Multilication with carrier of AM Signal');

subplot(2,1,2);
plot(t,m,t,y);
xlabel('t (in S)');
ylabel('m(t),y(t) (in V)');
title('Filtered Output and Input Signal');

