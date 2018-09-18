#ifndef PATH_GC_HPP_
#define PATH_GC_HPP_ 1

#include "pointGC.hpp"

typedef int Path;

extern int *pointAvailableList;
extern int pointNum;

//Create list with num
void pathInit(int num);

//Exchange path by position, position start on 0
void pointExchange(Point_2D* list, int positionOne, int positionTwo);

//Add point to path, when direction<0 from end, else from start
void pathAdd(int num, int direction);

//Find the shorted path and return the other pointID
int pathFind(int pointID, double** DistanceMat);

//Make path not cross each other
void pathDeCross(Point_2D* point, int usedNum);

//Judge if the two lines which links two points is cross.
bool isLineCross(
            Point_2D lineOne_pointStart, 
            Point_2D lineOne_pointEnd,
            Point_2D lineTwo_pointStart,
            Point_2D lineTwo_pointEnd 
            );

#endif