#ifndef POINT_GC_HPP_
#define POINT_GC_HPP_ 1

//Change it when you want to change the type
typedef int pointValue;

//2D Point with x and y
typedef struct Point_2D{
    pointValue x;
    pointValue y;
}Point_2D;

//Linked List of 2D Point
typedef struct LinkList_P2d{
    Point_2D point;
    struct LinkList_P2d* next;
    int data;
}LinkList_P2d;

//Create the Linked List which include [num] 2D Points
LinkList_P2d* getnPoint(int num);

//Get the distance between two points
double getDistance(Point_2D a, Point_2D b);

//Get Distance Matrix
double** getDistanceMat(LinkList_P2d* head);

#endif