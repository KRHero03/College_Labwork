import numpy as np
import cv2 as cv

img = cv.imread('left2.jpg')
img =  cv.cvtColor(img, cv.COLOR_BGR2GRAY)
new_image = np.zeros(img.shape)
print('vector<vector<double>> leftImage2 = {',end='')
for i in range(len(img)):
    for j in range(len(img[i])):
        if(img[i][j]<170):
            print('{'+str(j)+','+str(32-i)+'},',end='')
            new_image[i][j] = 255
print('};')
# cv.imshow('New Image',new_image)
# cv.waitKey(0)