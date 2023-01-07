#pragma once

#include "PointCloud.h"
#include <fstream>
#include <iostream>
#include "Map.h"

#ifndef OOPPROJECT_THREEDGRIDMAP_H
#define OOPPROJECT_THREEDGRIDMAP_H


class threeDGridMap : public Map{
    bool *map;
    float gridSize;
    int depth;
public:
    threeDGridMap(int _depth, float _gridSize = 0.5):depth(_depth), gridSize(_gridSize){
        this->map = new bool[depth*depth*depth];
        for (int i = 0; i < depth*depth*depth; ++i) {
            map[i] = false;
        }
    }
    void setMap(int _depth, float _gridSize = 0.5){
        this->depth = _depth;
        this->gridSize = _gridSize;
    }
    bool* getMap(int &_depth, float &_gridSize){
        _depth = this->depth;
        _gridSize = this->gridSize;
		return map;
    }
    void setThreeDGridMap(int _depth, float _gridSize = 0.5);
    bool* getThreeDGridMap(int &_depth, float &_gridSize);
    void insertPointCloud(PointCloud &pc);
    void insertPoint(Point &p);
    bool getGrid(int x, int y, int z);
    bool loadMap(std::string fileName);
    bool saveMap(std::string fileName);

};


#endif //OOPPROJECT_THREEDGRIDMAP_H
