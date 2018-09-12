#include <iostream>
#include "include/pointGC.hpp"
#include "include/pathGC.hpp"
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
    int pointNum_;
    cout << "Please input the number of points: ";
    cin >> pointNum_;
    LinkList_P2d* pointLinkList = getnPoint(pointNum_);
    double** distanceMat = getDistanceMat(pointLinkList);

    pathInit(pointNum_);

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

    cout << "Path:" << endl << "\t";
    cout << "0 -> ";
    for(int i = 0; i < pathA.num; i++)
        cout << pathA.list[i] << " -> ";
    for(int i = pathB.num-1; i >= 0; i--)
        cout << pathB.list[i] << " -> ";
    cout << "0" << endl;

    cout << "Total Distance: " << endl << "\t" << distanceSum << endl;

    return 0;
}
