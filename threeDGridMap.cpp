#include "threeDGridMap.h"

#include "DepthCamera.h"

//Get the grid map's depth, gridSize and map array
bool *threeDGridMap::getThreeDGridMap(int &_depth, float &_gridSize) {
    _depth = this->depth;
    _gridSize = this->gridSize;
    return this->map;
}

//Set the grid map's depth and gridSize
void threeDGridMap::setThreeDGridMap(int _depth, float _gridSize) {
    this->depth = _depth;
    this->gridSize = _gridSize;
    map = new bool[_depth*_depth*_depth];
}

void threeDGridMap::insertPointCloud(PointCloud &pc) {
    int size = 0;
    list<Point> pointsToInsert = pc.getPointCloud();
    auto iter = pointsToInsert.begin();
    double x = 0, y = 0, z = 0;
    for (; iter != pointsToInsert.end(); ++iter) {
        insertPoint(*iter);
    }
}

void threeDGridMap::insertPoint(Point &p) {
    double x = 0, y = 0, z = 0;
    p.getPoint(x,y,z);
    //Calculation of cube number
    int index = ((int)(((z+3)/gridSize))*depth*depth+(int)(((y+3)/gridSize))*depth+(int)((x+3)/gridSize));
    map[(int)index] = true;
}

bool threeDGridMap::getGrid(int x, int y, int z) {
    int index = ((int)(((z+3)/gridSize))*depth*depth+(int)(((y+3)/gridSize))*depth+(int)((x+3)/gridSize));
    return this->map[index];
}

bool threeDGridMap::loadMap(std::string fileName) {
    DepthCamera depthCamera(fileName); //transformu varmış
    PointCloud pc = depthCamera.capture();
    this->insertPointCloud(pc);
    return true;
}

bool threeDGridMap::saveMap(std::string fileName) {
    std::fstream file(fileName, std::ios::app);
    double x,y,z;
    if (file.is_open()){
        for (int i = 0; i <depth*depth*depth; ++i) {
            if (*(map + i)) {
                 x = i%depth;
                 y = (i%(depth*depth)-x)/depth;
                 z = (i-(y*depth+x))/(depth*depth);
//                 cout<<x<<" "<<y<<" "<<z<<endl;
                 file<<x<<" "<<y<<" "<<z<<endl;
            }
        }
    }
	return true;
}


