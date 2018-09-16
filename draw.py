#! /usr/bin/python

import matplotlib.pyplot as plt
from matplotlib.path import Path
import matplotlib.patches as patches

dataFile = open("data/output.txt", "r")
num = int(dataFile.readline())

pointList_x = []
pointList_y = []
pointList_x_ = []
pointList_y_ = []
pathList = []

for i in range(num):
    pointList_x.append(int(dataFile.readline()))
    pointList_y.append(int(dataFile.readline()))

for i in range(num):
    pathList.append(int(dataFile.readline()))

dataFile.close()

for i in range(num):
    pointList_x_.append(pointList_x[pathList[i]])
    pointList_y_.append(pointList_y[pathList[i]])
pointList_x_.append(pointList_x[pathList[0]])
pointList_y_.append(pointList_y[pathList[0]])


# newline(pointList[0], pointList[1])
plt.scatter(pointList_x_, pointList_y_)
plt.plot(pointList_x_, pointList_y_, 'g')
plt.xlabel('x')
plt.ylabel('y')
plt.title(r'$Maybe\ the\ shortest\ path$')
plt.show()