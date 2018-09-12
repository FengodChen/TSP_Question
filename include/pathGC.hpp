#ifndef PATH_GC_HPP_
#define PATH_GC_HPP_ 1

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

//Add point to path
void pathAdd(PathList* path, int num);

//Find the shorted path and return the other pointID
int pathFind(int pointID, PathList* path, double** DistanceMat);

#endif