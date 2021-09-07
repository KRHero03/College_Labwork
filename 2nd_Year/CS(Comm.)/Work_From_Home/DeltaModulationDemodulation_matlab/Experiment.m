% Experiment : Delta Modulation / Demodulation
% Author : Krunal Rank
% RollNo. : U18CO081

A_m = 1;
f_m = 1;
f_s = 20*f_m;

t = -3:1/f_s:3;

m = A_m*cos(2*pi*f_m*t);


del = (2*pi*f_m*A_m)/f_s;

dq = zeros(1,length(t));
d = zeros(1,length(t));
mq = zeros(1,length(t));


for i = 1: length(t)
    if i == 1
        mq(i) = 0;
        d(i) = m(i);
        dq(i) = sign(d(i))*del;
        mq(i) = dq(i);
    else
        d(i) = m(i) - mq(i-1);
        dq(i) = sign(d(i))*del;
        mq(i) = dq(i) + mq(i-1);
    end
end

%% Part 1

plot(t,m);
hold on;
stairs(t,mq);
hold off;
title('Message Signal and Staircase Approximation of Message Signal');

%% Part 2

x = zeros(1,length(t));
for i = 1: length(t)
    if dq(i) > 0
        x(i) = 1;
    else
        x(i) = -1;
    end
end

stem(t,x);
title('Delta Modulated Signal');

%% Part 3

[b,a] = butter(2,f_m/(0.7*f_s),'low');

y = filter(b,a,x);


plot(t,2*y,t,m);
title('Output Signal and Message Signal');