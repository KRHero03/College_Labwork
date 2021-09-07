% Experiment : Frequency Modulation and Demodulation
% Author: Krunal Rank
% RollNo. : U18CO081

%% Part 1
clc;
close all;
clear all;

f_s = 100;

t = -10:1/f_s:10;

A_m = 5;
A_c = A_m;
f_m = 1;
f_c = 10;

w_m = 2 * pi * f_m;
w_c = 2 * pi * f_c;

m = A_m*cos(w_m * t);
c = A_c*cos(w_c * t);
d_m = diff(m);
d_m = [d_m d_m(end)];

syms x;
m_x = @(x) A_m*cos(w_m*x);

k_p = 1;
k_f = 2 * pi * f_m;

s_p = A_c * cos(w_c*t + k_p*m);
s_f = zeros(1,length(t));
for i = 1: length(t)
    s_f(i) = A_c * cos(w_c*t(i) + integral(m_x,-10,t(i)));
end

subplot(5,1,1);
plot(t,m);
title('Input Signal');

subplot(5,1,2);
plot(t,c);
title('Carrier Signal');

subplot(5,1,3);
plot(t,s_f);
title('FM Signal');

subplot(5,1,4);
plot(t,d_m);
title('Derivative of Input Signal');

subplot(5,1,5);
plot(t,s_p);
title('PM Signal');

%% Part 2

n = length(t);
df = f_s/n;
f_p = -f_s/2:df:(f_s/2 - df);

y_p = fftshift(fft(s_p));
y_f = fftshift(fft(s_f));

subplot(2,1,1);
plot(f_p,abs(y_p));
title('Frequency Spectrum of PM');

subplot(2,1,2);
plot(f_p,abs(y_f));
title('Frequency Spectrum of FM');

%% Part 3

d_s_f = diff(s_f);
d_s_f = [d_s_f d_s_f(end)];

y_1 = d_s_f.*c;

[b,a] = butter(2,f_c/f_s,'low');

y_2 = filter(b,a,y_1);


subplot(3,1,1);
plot(t,d_s_f);
title('Derivative of FM Signal');

subplot(3,1,2);
plot(t,y_1);
title('Multiplied FM Signal with Carrier Signal');

subplot(3,1,3);
plot(t,y_2,t,m);
title('Filtered Ouput and Input Signal');