#ifndef PATH_GC_HPP_
#define PATH_GC_HPP_ 1

#include "pointGC.hpp"

typedef struct PathList{
    int num;
    int *list;
} PathList;

extern int *pointList;
extern int pointNum;
extern PathList pathA;
extern PathList pathB;

//Create list with num
void pathInit(int num);

//Exchange path by position, position start on 0
void pathExchange(PathList* path, int positionOne, int positionTwo);

//Add point to path
void pathAdd(PathList* path, int num);

//Find the shorted path and return the other pointID
int pathFind(int pointID, PathList* path, double** DistanceMat);

//Judge if the two lines which links two points is cross.
bool isLineCross(
            Point_2D lineOne_pointStart, 
            Point_2D lineOne_pointEnd,
            Point_2D lineTwo_pointStart,
            Point_2D lineTwo_pointEnd 
            );

#endif