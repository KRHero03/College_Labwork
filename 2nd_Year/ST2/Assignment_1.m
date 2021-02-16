%Assignment 1
%Author:- Krunal Rank
%IDE:- MATLAB

A = [1 2 3;4 5 6; 7 8 9;]; %Declared A #1
B = [7 8 9; 3 2 5; 4 9 6]; %Declared B

disp(A'); %Displaying transpose of matrix A #2

C = A + B; % Adding matrices A and B and storing it in C #3

disp(A*B); %Multiplying matrices A and B #4

disp(A.*B); %Multiplying individual elements of A and B #5

A = A.^2; %Squared individual elements of A #6
B = B.^2; %Squared individual elements of B

disp(A(1,:)); %Displaying first row of matrix A #7

disp(B(:,end)); %Displaying last column of matrix B #8

disp(det(A)); %Displaying determinant of A #9

disp(pinv(B)); %Displaying inverse of B #10

A = rand(5,6); %Creating 5 x 6 array 'A' with random numbers #11

S = 'I am an Indian'; %Storing String in S #12

whos; %Displays details of all existing variables including class #13
class(A); %Displays class of A

disp(A(3:4,2:5)); %Displays A from 3rd row to 4th row and 2nd column to 5th column #14

disp(exist('A','VAR')); %Displays 1 if a VARIABLE named A exists, else 0 #15

clear('B'); %Removes VARIABLE B from Workspace #16

marks = [22 44 36; 52 57 68; 66 53 69; 85 40 86; 15 47 25; 79 72 82]; %Creates...
...a matrix with marks of first 3 subjects #17

marks = [marks [36;76;76;72;28;91]]; %Appended marks from other subject in matrix 'marks'

chetan = marks(3,:); %Extract marks from Row 3
disp(sum(chetan)); %Display total marks of student 3 Chetan

marks(:,4) = marks(:,4)./2; %Scaled marks from Subject Column 4 to half

disp(marks([4,6],1:3)); %Displays marks of first three subjects of student 4 and student 6 

disp(mean(marks,1)); %Displays average marks of all subjects

disp(marks./10); %Scales all marks out of 10 which were previously out of 100








