% Experiment: ASK Modulation and Demodulation
% Author: Krunal Rank
% RollNo. : U18CO081

%% Part 1

clc;
clear all;
close all;

t = 0:0.01:8;
bit_stream =  [1 0 1 1 0 0 0 1];
A_c = 1;
f_c = 1;
w_c = 2 * pi * f_c;
m = zeros(1,length(t));
for i = 1: length(t)
    temp = idivide(t(i),int32(1));
    if temp==8
        temp = temp - 1;
    end
    m(i) = bit_stream(temp+1);
end

c = A_c*sin(w_c*t);

ask_signal = c.*m;

subplot(3,1,1);
plot(t,m);
ylim([-2 2]);
title('Message Signal');

subplot(3,1,2);
plot(t,c);
ylim([-2 2]);
title('Carrier Signal');

subplot(3,1,3);
plot(t,ask_signal);
ylim([-2 2]);
title('ASK Signal');

%% Part 2

ask_signal_rectified = abs(ask_signal);

subplot(2,1,1);
plot(t,ask_signal_rectified);
ylim([-2 2]);
title('Rectified ASK Signal');

output_signal = ask_signal_rectified>0;

subplot(2,1,2);
plot(t,output_signal);
ylim([-2 2]);
title('Output Signal');
