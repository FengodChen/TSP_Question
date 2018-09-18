#include "pointGC.hpp"
#include <iostream>
#include <math.h>
#include <cstdlib>

Point_2D* getnPoint(int num){
    using namespace std;
    if(num <= 0){
        return NULL;
    }else{
        Point_2D *LLhead = new Point_2D[num];
        cout << "Please input the point(x, y)" << endl;
        cout << "Sample: a(2, 5), just input \"2 5\"" << endl;
        cout << "POINT\t\t(x, y)" << endl;
        for(int i = 0; i < num; i++){
            cout << "Point" << i << "\t\t";
            cin >> LLhead[i].x >> LLhead[i].y;
        }
        cout << endl << "==========ENDINPUT==========" << endl << endl;
        return LLhead;
    }
}

double getDistance(Point_2D a, Point_2D b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double** getDistanceMat(Point_2D* LLhead, int num){
    double** list = new double*[num];
    for(int i = 0; i < num; i++){
        list[i] = new double[num];
        for(int j = i+1; j < num; j++){
            list[i][j] = getDistance(LLhead[i], LLhead[j]);
        }
    }
    for(int i = 0; i < num; i++)
        for(int j = i+1; j < num; j++)
            list[j][i] = list[i][j];
    return list;
}

int *getPointList(Point_2D *LLhead, int num){
    int* list = new int[num*2];
    for(int i = 0, j = 0; i < num; i++){
        list[j] = LLhead[i].x;
        j++;
        list[j] = LLhead[i].y;
        j++;
    }
    return list;
}

double pointMuti(Point_2D a, Point_2D b){
    return (a.x*b.y - a.y*b.x);
}

Point_2D pointSub(Point_2D a,Point_2D b){
    Point_2D ans;
    ans.x = a.x - b.x;
    ans.y = a.y - b.y;
    return ans;
}