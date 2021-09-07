%Aim:- a. To plot basic functions sin, cos, tan and exp in MATLAB
%      b. To plot basic signals like Unit step, pulse and ramp in MATLAB
%      c. To plot periodic signals such as impulse strain, square
%      wave,saw-tooth wave and triangular wave in MATLAB.
%% Part A

clc; %Clear console
clear all; %Clear variables
close all; %Close all windows except Editor window

t = -10:0.001:10; %Initialise t
subplot(2,2,1); %Using subplot to plot next graphs
plot(t,sin(t)); %Plotted Sine graphs
xlabel('Time(in s)'); %X Label for Sine graph
ylabel('Voltage(in V)'); %Y Label for Sine graph
title('Sine');%Title for Sine graph
axis([-10 10 -2 2]); %Axis limitations for Sine graph

subplot(2,2,2);
plot(t,cos(t)); %Plotted Cosine graph
axis([-10 10 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Cosine');

subplot(2,2,3);
plot(t,tan(t)); %Plotted Tangent graph
axis([-10 10 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Tangent');

subplot(2,2,4);
plot(t,exp(t)); %Plotted Exponential graph
axis([-10 10 -2 20000]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Exponential');


%% Part B


clc;
clear all;
close all;

t = -10:0.001:10;
unit_step = double(t>0); %Set values for unit_step for different values of t
unit_impulse = double(t==0); %Set value for unit_impulse for different values of t (1 when t=0 else 0)
unit_ramp = zeros(size(t)); %Initialise unit_ramp with 0
[m n] =  size(t); %Retrieve size of t for the below loop
for i=1:n
   if (t(1,i)>0)
       unit_ramp(1,i)=t(1,i); %Set unit_ramp = t when t>0
   end
end

subplot(3,1,1);
plot(t,unit_step) %Plotted Unit Step graph
axis([-2 10 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Unit Step');

subplot(3,1,2);
plot(t,unit_impulse) %Plotted Unit Impulse graph
axis([-1 1 -1 1]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Unit Impulse');

subplot(3,1,3);
plot(t,unit_ramp) %Plotted Unit Ramp graph
axis([-2 2 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Unit Ramp');

%% Part C


clc;
clear all;
close all;

t = -10:0.001:10;
time_period =0.5; %Set period for Impulse strain and triangle function
[m n] = size(t);


impulse_train=double(mod(t,time_period)==0);  %Iterating Impulse over certain period
sqr = square(t); %Generating Square Wave
saw = sawtooth(t); %Generating Sawtooth Wave
trngl = sawtooth(t,time_period); %Generating triangle wave by setting width = time_period

subplot(2,2,1);
plot(t,impulse_train); %Plotted Impulse Train graph
axis([-5,5 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Impulse Train');

subplot(2,2,2);
plot(t,sqr); %Plotted Square Wave graph
axis([-10 10 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Square');

subplot(2,2,3);
plot(t,trngl); %Plotted Triangle Wave graph
axis([-10 10 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Triangle');

subplot(2,2,4);
plot(t,saw); %Plotted Sawtooth Wave graph
axis([-10 10 -2 2]);
xlabel('Time(in s)');
ylabel('Voltage(in V)');
title('Sawtooth');

