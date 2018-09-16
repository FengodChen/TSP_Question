#include <iostream>
#include <cstdlib>
#include "include/pointGC.hpp"
#include "include/pathGC.hpp"
#include "include/dataIO.hpp"

using namespace std;

extern int *pointList;
extern int pointNum;
extern PathList pathA;
extern PathList pathB;
extern double distanceSum;

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
    LinkList_P2d* pointLinkList = getnPoint(pointNum_);
    double** distanceMat = getDistanceMat(pointLinkList);
    // Output point.x and point.y to file
    int *filePointList = getPointList(pointLinkList);
    for(int i = 0; i < pointNum_*2; i++)
        outputFile(filePointList[i]);

    // Initialize path list
    pathInit(pointNum_);

    // Set start path point0
    int pointA = 0;
    int pointB = 0;
    pointList[0] = 0;
    
    while(!isFull(pointNum_)){
        pointA = pathFind(pointA, &pathA, distanceMat);
        pointList[pointA] = 0;
        pathAdd(&pathA, pointA);

        if(isFull(pointNum_))
            break;

        pointB = pathFind(pointB, &pathB, distanceMat);
        pointList[pointB] = 0;
        pathAdd(&pathB, pointB);
    }
    distanceSum += distanceMat[pathA.num-1][pathB.num-1];

    // Output path
    cout << "Path:" << endl << "\t";
    cout << "0 -> ";
    outputFile(0);
    for(int i = 0; i < pathA.num; i++){
        cout << pathA.list[i] << " -> ";
        outputFile(pathA.list[i]);
    }
    for(int i = pathB.num-1; i >= 0; i--){
        cout << pathB.list[i] << " -> ";
        outputFile(pathB.list[i]);
    }
    cout << "0" << endl;
    outputFile(0);

    cout << "Total Distance: " << endl << "\t" << distanceSum << endl;

    closeOutFile();

    return 0;
}
