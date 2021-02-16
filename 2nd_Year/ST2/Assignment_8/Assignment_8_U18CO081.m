%  Assignment 8
%  Author: Krunal Rank
%  Adm. No.: U18CO081
%  IDE: MATLAB


%  Note: The functions used in the questions are described at the end of the
%  document in the order they are used.
%% Question 1
%  Write a function that takes a vector and counts how many even numbers there are. [Also odd numbers]
%  (i) Write a function that returns a vector of all the even valued elements in a given vector. E.g.,
%  if the given vector is [2 2 4 5 6 9], the returned vector is [2 2 4 6]
%  (ii) Write a function that returns a vector of all the elements in even positions in a given vector,
%  i.e. every second element in the vector. E.g., if the given vector is [2 2 4 5 6 9], the returned
%  vector is [2 5 9].

clc;
close all;
clear all;

A = [2 2 4 5 6 9];
[oddCount,evenCount,evenVal,evenPosVal] = getVectorProps(A);
fprintf("No. of odd elements:- %d\nNo. of even elements:- %d\n",oddCount,evenCount);
fprintf("Even elements:-\n");
disp(evenVal);
fprintf("Elements at Even Position:-\n");
disp(evenPosVal);

%% Question 2
%  Given a vector of heights of students in a class (in meters), return the average height.
%  Given an n by 2 that has the heights of students in a class, where the first column is the part of
%  the height before the decimal point (in meters), and the second column is the part of the height
%  after the decimal point (i.e. in cm), return an n by 1 vector that contains the height of the
%  students in m. Also: in cm. E.g., a row [1 63] means that the height of the person is 1m and
%  63cm.

clc;
close all;
clear all;
fprintf('Enter number of students:-');
val = inputdlg('Enter number of students:-');
n = str2num(val{1});
disp(n);
A = zeros(n,2);
for i = 1:n
    fprintf('Enter height of Student %ld metre Value:-',i);
    val = inputdlg('Enter height of Student '+string(i)+' metre Value:-');
    A(i,1) = str2num(val{1});
    disp(A(i,1));    
    fprintf('Enter height of Student %ld centimetre Value:-',i);
    val = inputdlg('Enter height of Student '+string(i)+' centimetre Value:-');
    A(i,2) = str2num(val{1});
    disp(A(i,2));
end
avgHeight = getAvgHeight(A);
fprintf('The Average Height of the students is %ld m %ld cm.\n',avgHeight(1,1),avgHeight(1,2));

%% Question 3
%  Push and pop from a stack

clc;
close all;
clear all;
stack = [];
p = 0;
while p ~= 2
    fprintf('Enter your action (0 - Push, 1 - Pop, 2 - Exit) :');
    val = inputdlg('Enter your action (0 - Push, 1 - Pop, 2 - Exit) :');
    p = str2num(val{1});
    disp(p);
    if p == 0
        fprintf('Enter a number to push into Stack :');
        val1 = inputdlg('Enter a number to push into Stack :');
        val = str2num(val1{1});
        disp(val);
        stack = [stack val];
        fprintf('Current Stack:\n');
        disp(stack);
    elseif p == 1
        val = stack(end);
        fprintf('Popped Value: %ld\n',val);
        stack(end) = [];
        fprintf('Current Stack:\n');
        disp(stack);
    else
        fprintf('Program Complete.\n');
        break;
    end
end

%% Question 4
%  Write a function that takes a matrix and returns the sum of its Eigenvalues.

clc;
close all;
clear all;

fprintf('Enter number of rows:-');
val = inputdlg('Enter number of rows:-');
R = str2num(val{1});
disp(R);

fprintf('Enter number of columns:-');
val = inputdlg('Enter number of columns:-');
C = str2num(val{1});
disp(C);

P = zeros(R,C);
for i=1:R
    for j = 1:C
        fprintf('Enter value at (%d,%d):-',i,j);
    	val = inputdlg('');
        P(i,j) = str2num(val{1});
        disp(P(i,j));
    end
end
s = getEigenSum(P);
fprintf('The sum of Eigen values is %ld.\n',s);

%% Question 5 A
%  Given a vector of unique names, and given one particular name that has to be found, write a
%  function that searches for that name from the vector and returns the element number. Proceed
%  to returning row/column number from matrix of names.

clc;
close all;
clear all;

names = {};
while true
    fprintf('Enter a name to be added in list(0 to Stop): ');
    val = inputdlg('Enter a name to be added in list(0 to Stop): ');
    name = val{1};
    disp(name);
    
    if(name=='0')
        break;
    end
    names = [names,name];
    
end
fprintf('Enter a name to be searched: ');
val = inputdlg('Enter a name to be searched: ');
search = val{1};
disp(search);

indexC = strfind(names,search);
index = find(not(cellfun('isempty',indexC)));

fprintf('The string is found at following indices:\n');
disp(index);

%% Question 5 B
%  Given a vector of unique names, and given one particular name that has to be found, write a
%  function that searches for that name from the vector and returns the element number. Proceed
%  to returning row/column number from matrix of names.

clc;
close all;
clear all;

fprintf('Enter number of rows: ');
val = inputdlg('Enter number of rows: ');
r = str2num(val{1});
disp(r);

fprintf('Enter number of columns: ');
val = inputdlg('Enter number of columns: ');
c = str2num(val{1});
disp(c);

names = strings([r c]);
for i = 1:r
    for j = 1:c
        fprintf('Enter name for cell at (%d,%d):-',i,j);
        val = inputdlg('');
    	names(i,j) = val{1};
        disp(names(i,j));
    end
end

fprintf('Enter a name to be searched: ');
val = inputdlg('Enter a name to be searched: ');
search = val{1};
disp(search);

indexC = strfind(names,search);
index = find(not(cellfun('isempty',indexC)));

[r1,c1] = size(index);
fprintf('The name was found at (Row,Column):\n');
for i=1:r1
    col = idivide(int32(index(i,1)),int32(r),'ceil');
    row = mod(int32(index(i,1)),int32(r));
    if row==0
        row = r;
    end
    fprintf('( %ld %ld )\n',row,col);
end
%% Question 6
%  Write a function that takes a vector that contains the marks of students and returns the
%  pass/fail status. Any score that is greater than, or equal to 30 is considered to be a passing score.
%  Return a vector of the same size as the input vector, but has a particular element as 1, if the
%  corresponding student passed, and 0 otherwise.

clc;
close all;
clear all;

fprintf('Enter number of students: ');
val = inputdlg('Enter number of students: ');
n = str2num(val{1});
disp(n);

A = zeros(n,1);
for i = 1:n
    fprintf('Enter marks of Student %ld : ',i);
    val = inputdlg('Enter marks of Student '+string(i)+' : ');
    A(i,1) = str2num(val{1});
    disp(A(i,1));
end
status = getResult(A);
fprintf('The result of the students is as follows:-\n');
disp(status);

%% Functions Used in Assignment
function [oddCount,evenCount,evenVal,evenPosVal] = getVectorProps(A)
    
    oddCount = 0;
    evenCount = 0;    
    evenVal = [];
    evenPosVal = [];
    
    [r c] = size(A);
    
    for i = 1:c
       if mod(A(i),2) == 1
           oddCount = oddCount + 1;
       else
           evenCount = evenCount + 1;
           evenVal = [evenVal A(i)];
       end
       if mod(i,2) == 0
           evenPosVal = [evenPosVal A(i)];
       end
    end       
end

function avg = getAvgHeight(A)
    avg = mean(A,1);
end

function s = getEigenSum(A)
    [eigenVec, D] = eig(A);
    eigenVal = diag(D);  
    s = sum(eigenVal);
end

function result = getResult(A)
  result = A>30;  
end