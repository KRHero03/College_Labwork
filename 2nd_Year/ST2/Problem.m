%Problem
%Author:- Krunal Rank
%IDE:- MATLAB
%% Question 1
clc;
clear all;
close all;

year = int32(input('Enter Year:-'));
m = year*12;
d = 0;
for i = 1:year
    if(idivide(i,4)==0 && idivide(i,100)~=0) || idivide(i,400)==0
        d = d + 366;
    else
        d = d + 365;
    end
end
h = d * 24;

fprintf('Enter your choice:-\n1.No. of months in  %d years\n2.No. of days in %d years\n3.No. of hours in %d years\n>>',year,year,year);

choice = int32(input(''));
switch(choice)
    case 1
        fprintf('No. of months in %d years: %d\n',year,m);
    case 2
        fprintf('No. of days in %d years: %d\n',year,d);
    case 3
        fprintf('No. of hours in %d years: %d\n',year,h);
    otherwise
        fprintf('Invalid choice!\n');
end