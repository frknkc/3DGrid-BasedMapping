#include <iostream>
#include "PointCloud.h"
#include "PointCloudGenerator.h"
#include "PointCloudRecorder.h"
#include "Map.h"
#include <vector>
#ifndef OOPPROJECT_MAPPERINTERFACE_H
#define OOPPROJECT_MAPPERINTERFACE_H


class MapperInterface {
    PointCloud pointCloud;
    PointCloud patch;
    std::vector<PointCloudGenerator*> generators;
    PointCloudRecorder *recorder;
    Map *map;
public:
    MapperInterface(Map *_map):map(_map){}
    void addGenerator(PointCloudGenerator *_pointCloudGenerator);
    void setRecorder(PointCloudRecorder *_pointCloudRecorder);
    bool generate();
    bool recordPointCloud();
    bool recordMap();
    bool insertMap();

};


#endif //OOPPROJECT_MAPPERINTERFACE_H
