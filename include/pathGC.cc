#include "pathGC.hpp"
#include "pointGC.hpp"

int *pointList;
int pointNum;
double distanceSum = 0;
Path* pathList;

void pathInit(int num){
    pointList = new int[num];
    for(int i = 0; i < num; i++)
        pointList[i] = 1;
    
    pathList = new Path[num+1];
    for(int i = 0; i <= num; i++)
        pathList[i] = -1;

    pointNum = num;
    return ;
}

void pathAdd(int num, int direction){
    int position;
    if(direction >= 0){
        for(position = 0; pathList[position] != -1; position++);
        pathList[position] = num;
    }else{
        for(position = pointNum; pathList[position] != -1; position--);
        pathList[position] = num;
    }
    return ;
}

void pathExchange(int positionOne, int positionTwo){
    //TODO
    return;
}

int pathFind(int pointID, double** distanceMat){
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

void pathDeCross(Point_2D* point, int num){
    bool allDeCross = true;
    for(int i = 0; i < num-1; i++){
        for(int j = i+1; j < num; j++){
            if(isLineCross);//TODO
        }
    }
}

bool isLineCross(
            Point_2D lineOne_pointStart, 
            Point_2D lineOne_pointEnd,
            Point_2D lineTwo_pointStart,
            Point_2D lineTwo_pointEnd 
            ){
    double lineOne_middle_x = (lineOne_pointStart.x + lineOne_pointEnd.x)/2.0;
    double lineOne_middle_y = (lineOne_pointStart.y + lineOne_pointEnd.y)/2.0;
    if((lineTwo_pointStart.x - lineOne_middle_x)*(lineTwo_pointEnd.x - lineOne_middle_x) < 0)
        return true;
    if((lineTwo_pointStart.y - lineOne_middle_y)*(lineTwo_pointEnd.y - lineOne_middle_y) < 0)
        return true;
    return false;
}