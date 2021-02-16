%Assignment 2
%Author:- Krunal Rank
%IDE:- MATLAB

%% Question 1
clc;
clear all;
close all;

prompt='Enter a number:- ';
A = input(prompt); 
if A>0
    fprintf('%d is greater than 0.\n',A); 
elseif A<0
    fprintf('%d is less than 0.\n',A); 
else
    fprintf('%d is equal to 0.\n',A); 
end

i=1;
while i<=10
    disp(i*5); 
    i = i+1;
end
for i=1:10
    disp(i*5); 
end


%% Question 2
clc;
clear all;
close all;

A = rand(5,4);
[n, m] = size(A);
B = zeros(m,n);
for i=1:n
    for j = 1:m
        B(j,i) = A(i,j);
    end
end
fprintf('Original Matrix:-\n');
disp(A);
fprintf('Transpose of Matrix:-\n');
disp(B);

%% Question 3
clc;
clear all;
close all;

A = rand(5,4);
B = rand(5,4);
[m, n] = size(A);
C = zeros(size(A));
for i=1:m
    for j=1:n
        C(i,j) = A(i,j) + B(i,j);
    end
end
fprintf('Matrix A:-\n');
disp(A);
fprintf('Matrix B:-\n');
disp(B);
fprintf('Addition of A and B:-\n');
disp(C);

%% Question 4
clc;
clear all;
close all;

A = rand(5,4);
B = rand(3,5);
[m, ~] = size(A);
[n, p] = size(B);
C = zeros(m,p);
for i=1:m
    for j=1:p
        sum = 0;
        for k=1:n
            sum = sum + A(i,k)*B(k,j);
        end
        C(i,j) = sum;
    end
end

fprintf('Matrix A:-\n');
disp(A);
fprintf('Matrix B:-\n');
disp(B);
fprintf('Multiplication of A and B:-\n');
disp(C);

%% Question 5
clc;
clear all;
close all;

prompt = 'Enter a number:-';
A = int32(input(prompt));
temp = A;
rev = 0;
while temp>0
    rev = rev*10 + mod(temp,10);
    temp = idivide(temp,10);
end
fprintf('A:- %d Reverse:- %d \n',A,rev);

%% Question 6

clc;
clear all;
close all;

prompt = 'Enter a number:-';
A = int32(input(prompt));
sum = mod(A,10);
greatest = mod(A,10);
while A>10
    digit = mod(A,10);
    if greatest<digit
        greatest = digit;
    end
    A = idivide(A,10);
end
sum = sum + A;
if greatest<A
    greatest = A;
end
fprintf('Sum of first and last digit:- %d \nGreatest Digit:- %d\n',sum,greatest);

%% Question 7
clc;
clear all;
close all;

prompt = 'Enter dimension of square matrix:- ';
n = int32(input(prompt));
p = int32(input('Enter desired row/column index:-'));
assert(p<=n);
A = rand(n,n);
sumRow = sum(A,1);
sumCol = sum(A,2);
fprintf('Sum of Row %d:- %d\nSum of Column %d:- %d\n',p,sumRow(p),p,sumCol(p));


%% Question 8
clc;
clear all;
close all;

A = randi([1 100],5,7);
fprintf('Matrix A:- \n');
disp(A);
C = mod(A,5) == 0 | mod(A,7) == 0;
disp(C);
idx = find(C==1);
idx = int32(idx);
fprintf('Indices of matrix A divisible by 5 or 7:-\n');
disp(idx);

%% Question 9

clc;
clear all;
close all;
A = randi([1 1000],7,8);
fprintf('Matrix A:- \n');
disp(A);
fprintf('Indices with Prime Numbers:- \n');
primes = isprime(A);
idx = find(primes==1);
disp(idx);

%% Question 10

clc;
clear all;
close all;

A = randi([1 50], 9 , 9);
fprintf('Original Matrix A:-\n');
[~,ia1,~] = unique(A);
B = zeros(size(A));
B(ia1) = A(ia1);
A = B;

clear B;
clear ia1;

fprintf('After removing all duplicate entries, A:-\n');
disp(A);

%% Question 11

clc;
clear all;
close all;

A = input('Enter a number:-');
tempA = int32(A);
a = 1;
sqrRoot = sqrt(A);
for i=2:int32(sqrRoot)
    if(mod(tempA,i)==0)
        a = a + i;
        a = a + int32(tempA/i);
    end
end

if(a==A)
    fprintf('%d is perfect number.\n',A);
else
    fprintf('%d is not a perfect number.\n',A);
end

%% Question 12

clc;
clear all;
close all;

P = int32(input('Enter number of Fibonacci Numbers required:- ' ));
a = 0;
b = 1;
fprintf('Fibonacci Series:- \n');
for i=1:P
    fprintf('%d ',a);
    temp = b;
    b = a+b;
    a = temp;
end
fprintf('\n');

%% Question 13

clc;
clear all;
close all;

A = int32(input('Enter a number:- '));
factorial = 1;
for i=1:A
    factorial = factorial*i;
end
fprintf('Factorial of %d: %d\n',A,factorial);


%% Question 14

clc;
clear all;
close all;

A = randi([1 81],9,9); %Use magic(9) to get magic matrix

sumCol = sum(A,1);
sumRow = sum(A,2);
diag1 = sum(diag(A));
diag2 = sum(diag(flip(A)));

if(isequal(sumCol,sumRow') && sumCol(1)==diag1 && sumCol(1)==diag2)
    fprintf('Matrix is a magic matrix!\n');
else
    fprintf('Matrix is not a magic matrix!\n');
end

%% Question 15

clc;
clear all;
close all;

num = int32(input('Enter a number:- '));
temp = int32(num);

num1 = 0;

while(temp>0)
    num1 = num1*10;
    num1 = num1 + mod(temp,10);
    temp = idivide(temp,10);
end

if(num==num1)
    fprintf('%d is a palindrome!\n',num);
else
    fprintf('%d is not a palindrome!\n',num);
end

    

    