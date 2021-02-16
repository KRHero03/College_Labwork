%% Software Tools 2 Evaluation
%  Name: Krunal Rank
%  Roll No: U18CO081

%% Question 1

clc;
clear all;
close all;

syms h;
A = 2*h*100 + 0.5* pi *100 * 100;
fplot(A, [0,500]);


[r,h] = meshgrid(0:1:300,100:100:400);
A = 2.*h.*r + 0.5* pi .*r.* r;
mesh(h,r,A);

[r,h] = meshgrid(0:1:300,0:1:500);
A = 2.*h.*r + 0.5* pi .*r.* r;
mesh(h,r,A);



%% Question 2

clc;
clear all;
close all;

img = [100 200 500; 390 500 678; 200 900 567];

imgNo = 0;
maxVal = 0;

for i = 1:3
    for j= 1:3
        if img(i,j)> maxVal
            imgNo = i;
            maxVal = img(i,j);
        end
    end
end

fprintf('The pixel with the maximum intensity of %d is found in Image #%d !\n',maxVal,imgNo);

temp_img = img + 100;
fprintf('The images with 100 added to each pixel value will have following values:-\n');
disp(temp_img);