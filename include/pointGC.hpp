#ifndef POINT_GC_HPP_
#define POINT_GC_HPP_ 1

//Change it when you want to change the type
typedef int pointValue;

//2D Point with x and y
typedef struct Point_2D{
    pointValue x;
    pointValue y;
}Point_2D;

//Create the Linked List which include [num] 2D Points
Point_2D* getnPoint(int num);

//Get the distance between two points
double getDistance(Point_2D a, Point_2D b);

//Get Distance Matrix
double** getDistanceMat(Point_2D* LLhead, int num);

//Return all points x and y
int *getPointList(Point_2D *LLhead, int num);

#endif