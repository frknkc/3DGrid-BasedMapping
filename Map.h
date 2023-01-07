/**
* @file Map.h
* @Author Furkan Koc
* @date January, 2023
*/

#include <iostream>
#include "PointCloud.h"
#ifndef OOPPROJECT_MAP_H
#define OOPPROJECT_MAP_H

//Abstract class
class Map {
public:
    //! map'in depth'ine _depth i atar, gridSize'ina _gridSize'i atar.
    virtual void setMap(int _depth, float _gridSize = 0.5) = 0;
    //! \return map(bool*)
    //! _depth'e map'in depth'ini atar, _gridSize'a map'in gridSize'ini atar.
    virtual bool* getMap(int &_depth, float &_gridSize) = 0;
    //! pointCloud'un icindeki noktalari alip map'in icine atar.
    virtual void insertPointCloud(PointCloud &pc) = 0;
    //! noktayi map'in icine atar.
    virtual void insertPoint(Point &p) = 0;
    //! verilen txt dosyasini okuyup map'e atar
    virtual bool loadMap(std::string fileName) = 0;
    //! verilen txt dosyasina map'de 1 olarak isaterlenmis kutularin koordinatlarini kaydeder.
    virtual bool saveMap(std::string fileName) = 0;

};


#endif //OOPPROJECT_MAP_H
