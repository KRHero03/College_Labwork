%Assignment 3
%Author:- Krunal Rank
%IDE:- MATLAB

%% Question 1
clc;
clear all;
close all;



A = [2 3 4 5 6];
getEven = [];
maxIndex = findMaxIndex(A);
getEven = getEvenFrom(A);  
fprintf('Maximum Value:- %d\n',maxIndex);
fprintf('Even values:-\n');
disp(getEven);

%% Question 2
clc;
clear all;
close all;

prompt = 'Enter a number:-';
A = int32(input(prompt));
if isArmstrongNumber(A)==true
  fprintf("%d is an Armstrong Number!\n",A);
else
  fprintf("%d is not an Armstrong Number!\n",A);
end
  
%% Question 3
clc;
clear all;
close all;

R = int32(input('Enter number of rows:-'));
C = int32(input('Enter number of columns:-'));
P = zeros(R,C);
for i=1:R
    for j = 1:C
        fprintf('Enter value at (%d,%d):-',i,j);
    	P(i,j) = input('');
    end
end
[charEq,eigenVal,eigenVec] = getMatrixProp(P);
disp(charEq);
disp(eigenVal);
disp(eigenVec);

%% Question 4

Q = input('Enter Quadratic Coefficient:-');
L = input('Enter Linear Coefficient:-');
C = input('Enter Constant:-');
roots = findQuadraticRoots(Q,L,C);
fprintf('The roots are:-\n');
disp(roots);

%% Question 5
clc;
clear all;
close all;

n = int32(input('Enter number of students:-'));
A = zeros(n,1);
for i = 1:n
    A(i,1) = input('Enter marks of Student '+string(i)+' :-');
end
status = getResult(A);
fprintf('The result of the students is as follows:-\n');
disp(status);

%% Question 6
clc;
clear all;
close all;

n = int32(input('Enter number:-'));
printSeries(n);

%% Question 7

clc;
clear all;
close all;

s = input('Please enter an infix expression:-','s');
postfix = infixToPostfix(s);
fprintf('Postfix Expression:-\n')
disp(postfix);

val = evaluatePostfix(postfix);
if val=='null'
    fprintf('Invalid Postfix Expression!\n');
else
    fprintf('Value of Infix Expression: %d\n',val);
end

s = input('Please enter an prefix expression:-','s');
postfix = prefixToPostfix(s);
if(postfix=='null')
    fprintf('Invalid Prefix Expression!\n');
else
    fprintf('Postfix Expression:- %s\n',postfix);
    val = evaluatePostfix(char(postfix));
    fprintf('Evaluated Value of Postfix Expression:- %d\n',val);
end

