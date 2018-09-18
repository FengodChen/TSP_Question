#include <iostream>
#include <cstdlib>
#include "include/pointGC.hpp"
#include "include/pathGC.hpp"
#include "include/dataIO.hpp"

using namespace std;

extern int *pointAvailableList;
extern int pointNum;
extern Path* pathList;

bool isFull(int num){
    for(int i = 0; i < num; i++)
        if(pointAvailableList[i] == 1)
            return false;
    return true;
}

int main(int argc, char const *argv[])
{
    //freopen("input.txt", "r", stdin);

    // Create output file named "output.txt"
    // line 1 is the number of points
    // line 2 is point1.x, line 3 is point1.y
    // ......line point_number*2+1 is pointnumber.y
    createOutFile("../data/output.txt");

    // Input the point
    int pointNum_;
    cout << "Please input the number of points: ";
    cin >> pointNum_;
    // Output the number of the points to file
    outputFile(pointNum_);

    // Handle the data
    Point_2D* pointList = getnPoint(pointNum_);
    double** distanceMat = getDistanceMat(pointList, pointNum_);

    // Initialize path list
    pathInit(pointNum_);

    // Set start path point0
    int pointA = 0;
    int pointB = 0;
    pointAvailableList[0] = 0;
    pathList[0] = 0;
    pathList[pointNum_] = 0;
    
    // Get the path
    while(!isFull(pointNum_)){
        pointA = pathFind(pointA, distanceMat);
        pointAvailableList[pointA] = 0;
        pathAdd(pointA, 1);

        if(isFull(pointNum_))
            break;

        pointB = pathFind(pointB, distanceMat);
        pointAvailableList[pointB] = 0;
        pathAdd(pointB, -1);
    }

    // Optimize the path when two lines are cross
    pathDeCross(pointList, 0);

    // Output point.x and point.y to file
    int *filePointList = getPointList(pointList, pointNum_);
    for(int i = 0; i < pointNum_*2; i++)
        outputFile(filePointList[i]);

    // Output path to screen and file
    cout << "Path:" << endl << "\t";
    for(int i = 0; i <= pointNum_; i++){
        if(i == pointNum_)
            cout << "(" << pointList[pathList[i]].x << ", " << pointList[pathList[i]].y << ")" << endl;
        else
            cout << "(" << pointList[pathList[i]].x << ", " << pointList[pathList[i]].y << ")" << " -> ";
        outputFile(pathList[i]);
    }

    //Calculate distance and output it to screen
    double distanceSum = 0;
    for(int i = 0; i <= pointNum_; i++){
        distanceSum += getDistance(pointList[pathList[i]], pointList[pathList[i+1]]);
    }
    cout << "Total Distance: " << endl << "\t" << distanceSum << endl;

    closeOutFile();

    return 0;
}
