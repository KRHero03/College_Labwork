%Assignment 4
%Author:- Krunal Rank
%IDE:- MATLAB
%% Question 1
clc;
clear all;
close all;

x = -10:0.01:10;
y = sin(x);
plot(x,y);
title('Sin(x)');
xlabel('X');
ylabel('Y');

%% Question 2
clc;
clear all;
close all;

x = -10:0.1:10;
y = sin(x);
z = cos(x);
plot(x,y,'b.','MarkerSize',15,x,z,'g-');
title('Sin(x) and Cos(x)');
xlabel('X');
ylabel('Y');

%% Question 3
clc;
clear all;
close all;

x = 0:0.01:5*pi;
y = x.^2;

polarplot(x,y);
title('X^2');

%% Question 4
clc;
clear all;
close all;

x = -8:0.01:8;
y = -8:0.01:8;
r = sqrt(x.^2 + y.^2);
z = sin(r)./r;

plot(x,z);

%% Question 5
clc;
clear all;
close all;

x = -10:0.01:10;
y1 = 2 - (x-3).^2;
y2 = x./2 + 1;
plot(x,y1,'g-',x,y2,'b.');

%% Question 6
clc;
clear all;
close all;

x = -10:0.01:10;
y = 3*x.^4+ 2*x.^3+ 7*x.^2+ 2*x + 9;
plot(x,y);

%% Question 7
clc;
clear all;
close all;

labels = {'Walk','Bike','Car','Bus'};
x = [9 3 6 12];
explode = [1 1 1 1];
pie(x,explode);
legend(labels);

figure;

bar(x);