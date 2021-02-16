% Assignment 6
% Author:- Krunal Rank
% Adm. No:- U18CO081
% IDE:- MATLAB

%% Question A 
% Solve the following quadratic equation in MATLAB and display their roots.
% Note: If roots are fractions then show their nearby rational number.

%% 1
% x^2 - 7*x + 12 = 0
clc;
close all;
clear all;

syms x;
a = solve(x^2 - 7*x + 12 == 0,x);
disp(vpa(a));

%% 2
% (x-3)^2*(x-7)=0
clc;
close all;
clear all;

syms x;
a = solve((x-3)^2*(x-7)==0,x);
disp(vpa(a));

%% 3
% x^4 - 7*x^3 + 3*x^2 - 5*x + 9 = 0
clc;
close all;
clear all;

syms x;
a = solve(x^4 - 7*x^3 + 3*x^2 - 5*x + 9 ==0);
disp(vpa(a));

%% 4
% 6*x^2 - 11*x - 35 = 0
clc;
close all;
clear all;

syms x;
a = solve(6*x^2 - 11*x - 35 ==0);
disp(vpa(a));

%% 5
% (x-2)^2 -12 = 0
clc;
close all;
clear all;

syms x;
a = solve((x-2)^2 -12 == 0);
disp(vpa(a));

%% Question B
% Solve the following equations in MATLAB.

%% 1
% 5*x+ 9*y = 5
% 3*x - 6*y = 4
clc;
close all;
clear all;

syms x y ;
[solx soly] = solve([5*x+ 9*y == 5, 3*x - 6*y == 4]);
fprintf("X:-\n");
disp(vpa(solx));
fprintf("Y:-\n");
disp(vpa(soly));

%% 2
% x+3*y-2*z = 5
% 3*x+5*z+6*z = 7
% 2*x+4*y+3*z = 8
clc;
close all;
clear all;

syms x y z;
[solx soly solz] = solve([x+3*y-2*z==5,3*x+5*z+6*z==7,2*x+4*y+3*z==8]);
fprintf("X:-\n");
disp(vpa(solx));
fprintf("Y:-\n");
disp(vpa(soly));
fprintf("Z:-\n");
disp(vpa(solz));

%% 3
% 7*x + 5*y - 3*z = 16
% 3*x - 5*y + 2*z = -8
% 5*x + 3*y - 7*z = 0
clc;
close all;
clear all;

syms x y z;
[solx soly solz] = solve([7*x + 5*y - 3*z == 16, 3*x - 5*y + 2*z == -8, 5*x + 3*y - 7*z==0]);
fprintf("X:-\n");
disp(vpa(solx));
fprintf("Y:-\n");
disp(vpa(soly));
fprintf("Z:-\n");
disp(vpa(solz));

%% 4
% 3*x + 2*y = 16
% 7*x + y = 19
clc;
close all;
clear all;

syms x y;
[solx soly] = solve([3*x + 2*y == 16, 7*x + y == 19]);
fprintf("X:-\n");
disp(vpa(solx));
fprintf("Y:-\n");
disp(vpa(soly));

%% 5
% 4*x + 3*y = -2
% 8*x - 2*y = 12
clc;
close all;
clear all;

syms x y;
[solx soly] = solve([4*x + 3*y == -2, 8*x - 2*y == 12]);
fprintf("X:-\n");
disp(vpa(solx));
fprintf("Y:-\n");
disp(vpa(soly));

%% Question C 
% Factorise and simplify the following Algebraic equation.

%% 1
% x^2 - y^2
clc;
close all;
clear all;

syms x y;
a = factor(x^2 - y^2);
disp(a);

%% 2
% x^3 + y^3
clc;
close all;
clear all;

syms x y;
a = factor(x^3 + y^3);
disp(a);

%% 3
% (x^4 - 16)/(x^2 - 4)
clc;
close all;
clear all;

syms x;
a = factor((x^4 - 16)/(x^2 - 4));
disp(a);

%% 4
% x^4 + y^4
clc;
close all;
clear all;

syms x y;
a = factor(x^4 + y^4);
disp(a);

%% 5
% x^5 - y^5
clc;
close all;
clear all;

syms x y;
a = factor(x^5 - y^5);
disp(a);

%% Question D
% Find the limit of following functions.

%% 1
clc;
close all;
clear all;

syms x;
a = limit((x^3 + 5)/(x^4 + 7) , x , 0);
disp(a);

%% 2
clc;
close all;
clear all;

syms x;
a = limit((x - 3)/(x - 1) , x , 1);
disp(a);

%% 3
clc;
close all;
clear all;

syms x;
a = limit((1 - x^0.5)/(1 - x) , x , 1);
disp(a);

%% 4
clc;
close all;
clear all;

syms x;
a = limit((sin(5*x))/(3*x) , x , 0);
disp(a);

%% 5
clc;
close all;
clear all;

syms x;
eqn =  (x-3)/abs(x-3);
left = limit(eqn,x,3,'left');
right = limit(eqn,x,3,'right');

fplot((x-3)/abs(x-3));

fprintf('LHL: ');
disp(left);
fprintf('RHL: ');
disp(right);
