#include "pointGC.hpp"
#include <iostream>
#include <math.h>
#include <alloca.h>

LinkList_P2d* getnPoint(int num){
    using namespace std;
    if(num <= 0){
        return nullptr;
    }else{
        int LLsize = sizeof(LinkList_P2d);  //Get the size of LinkList_P2d
        LinkList_P2d* LLhead = (LinkList_P2d*)malloc(LLsize);
        LLhead->data = num;
        LinkList_P2d* tmp = LLhead;
        cout << "Please input the point(x, y)" << endl;
        cout << "Sample: a(2, 5), just input \"2 5\"" << endl;
        cout << "POINT\t\t(x, y)" << endl;
        for(int i = 0; i < num; i++){
            tmp->next = (LinkList_P2d*)malloc(LLsize);
            tmp = tmp->next;
            cout << "Point" << i << "\t\t";
            cin >> tmp->point.x >> tmp->point.y;
        }
        return LLhead;
    }
}

double getDistance(Point_2D a, Point_2D b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double** getDistanceMat(LinkList_P2d* head){
    int num = head->data;
    double** list = new double*[num];
    LinkList_P2d* tmp = head;
    for(int i = 0; i < num; i++){
        list[i] = new double[10];
        tmp = tmp->next;
        LinkList_P2d* tmp2 = tmp;
        for(int j = i+1; j < num; j++){
            tmp2 = tmp2->next;
            list[i][j] = getDistance(tmp->point, tmp2->point);
        }
    }
    for(int i = 0; i < num; i++)
        for(int j = i+1; j < num; j++)
            list[j][i] = list[i][j];
    return list;
}

int *getPointList(LinkList_P2d *head){
    int num = head->data;
    int* list = new int[num];
    LinkList_P2d* tmp = head;
    for(int i = 0; i < num; i++){
        tmp = tmp->next;
        list[i] = tmp->point.x;
        i++;
        list[i] = tmp->point.y;
    }
    return list;
}