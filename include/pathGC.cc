#include "pathGC.hpp"
#include "pointGC.hpp"
#include <iostream>

int *pointList;
int pointNum;
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

void pointExchange(Point_2D* list, int positionOne, int positionTwo){
    Point_2D tmp = list[positionOne];
    list[positionOne] = list[positionTwo];
    list[positionTwo] = tmp;
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
    return shortPoint;
}

void pathDeCross(Point_2D* point, int usedNum){
    bool isDeCross = true;
    int num = 0;
    if(usedNum > 10000){
        std::cout << "WARNING(on pathDeCross): Runtime is over!" << std::endl;
        return;
    }
    for(int i = 0; i < pointNum-2; i++){
        if(i == 0){
            for(int j = i+2; j < pointNum-1; j++)
                if(isLineCross(
                    point[pathList[i]],
                    point[pathList[i+1]],
                    point[pathList[j]],
                    point[pathList[j+1]]
                )){
                    pointExchange(point, pathList[i+1], pathList[j]);
                    isDeCross = false;
                }
        }else{
            for(int j = i+2; j < pointNum; j++)
                if(isLineCross(
                    point[pathList[i]],
                    point[pathList[i+1]],
                    point[pathList[j]],
                    point[pathList[j+1]]
                )){
                    pointExchange(point, pathList[i+1], pathList[j]);
                    isDeCross = false;
                    num++;
                }
        }
    }
    if(!isDeCross)
        pathDeCross(point, usedNum+1);
    
    return;
}

/*
std::ostream & operator<<(std::ostream &__out, Point_2D point){
    std::cout << "(" << point.x << ", " << point.y << ")";
    return __out;
}
*/

bool isLineCross(
            Point_2D lineOne_pointStart, 
            Point_2D lineOne_pointEnd,
            Point_2D lineTwo_pointStart,
            Point_2D lineTwo_pointEnd 
            ){
    Point_2D lineOne, lineTwo;
    lineOne = pointSub(lineOne_pointEnd, lineOne_pointStart);
    lineTwo = pointSub(lineTwo_pointEnd, lineTwo_pointStart);
    double t = pointMuti(pointSub(lineTwo_pointStart, lineOne_pointStart), lineTwo)/pointMuti(lineOne, lineTwo);
    double u = pointMuti(lineOne, pointSub(lineOne_pointStart, lineTwo_pointStart))/pointMuti(lineOne, lineTwo);
    //std::cout << lineOne_pointStart << "->" << lineOne_pointEnd << " || " << lineTwo_pointStart << "->" << lineTwo_pointEnd << std::endl;
    //std::cout << "t = " << t << ", u = " << u << std::endl;
    if(t >= 0 && t <= 1)
        if(u >= 0 && u <= 1)
            return true;
    return false;
}