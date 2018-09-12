#include "pathGC.hpp"

int *pointList;
int pointNum;
double distanceSum = 0;
PathList pathA, pathB;

void pathInit(int num){
    pointList = new int[num];
    for(int i = 0; i < num; i++)
        pointList[i] = 1;
    
    pathA.list = new int[num];
    pathB.list = new int[num];

    pointNum = num;
    return ;
}

void pathAdd(PathList* path, int num){
    path->list[path->num] = num;
    path->num += 1;
    return ;
}

int pathFind(int pointID, PathList* path, double** distanceMat){
    int shortPoint = -1;
    for(int i = 0; i < pointNum; i++){
        if(i == pointID || pointList[i] == 0)
            continue;
        if(shortPoint == -1)
            shortPoint = i;

        if(pointList[i] == 1)
            if(distanceMat[pointID][i] < distanceMat[pointID][shortPoint])
                shortPoint = i;
    }
    distanceSum += distanceMat[pointID][shortPoint];
    return shortPoint;
}
