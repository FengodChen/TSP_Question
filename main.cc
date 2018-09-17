#include <iostream>
#include <cstdlib>
#include "include/pointGC.hpp"
#include "include/pathGC.hpp"
#include "include/dataIO.hpp"

using namespace std;

extern int *pointList;
extern int pointNum;
extern double distanceSum;
extern Path* pathList;

bool isFull(int num){
    for(int i = 0; i < num; i++)
        if(pointList[i] == 1)
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
    Point_2D* pointLinkList = getnPoint(pointNum_);
    double** distanceMat = getDistanceMat(pointLinkList, pointNum_);
    // Output point.x and point.y to file
    int *filePointList = getPointList(pointLinkList, pointNum_);
    for(int i = 0; i < pointNum_*2; i++)
        outputFile(filePointList[i]);

    // Initialize path list
    pathInit(pointNum_);

    // Set start path point0
    int pointA = 0;
    int pointB = 0;
    pointList[0] = 0;
    pathList[0] = 0;
    pathList[pointNum_] = 0;
    
    while(!isFull(pointNum_)){
        pointA = pathFind(pointA, distanceMat);
        pointList[pointA] = 0;
        pathAdd(pointA, 1);

        if(isFull(pointNum_))
            break;

        pointB = pathFind(pointB, distanceMat);
        pointList[pointB] = 0;
        pathAdd(pointB, -1);
    }
    distanceSum += distanceMat[pointA][pointB];

    // Output path
    cout << "Path:" << endl << "\t";
    for(int i = 0; i <= pointNum_; i++){
        if(i == pointNum_)
            cout << pathList[i] << endl;
        else
            cout << pathList[i] << " -> ";
        outputFile(pathList[i]);
    }

    cout << "Total Distance: " << endl << "\t" << distanceSum << endl;

    closeOutFile();

    return 0;
}
