#include "MapperInterface.h"

void MapperInterface::addGenerator(PointCloudGenerator *_pointCloudGenerator) {
    generators.emplace_back(_pointCloudGenerator);
}

void MapperInterface::setRecorder(PointCloudRecorder *_pointCloudRecorder) {
    this->recorder = _pointCloudRecorder;
}

bool MapperInterface::generate() {
    int size = generators.size();
    for (int i = 0; i < size; ++i) {
        pointCloud = pointCloud + generators[i]->captureFor();
    }
    return true;
}

bool MapperInterface::recordPointCloud() {
    recorder->save(pointCloud);
    return false;
}

bool MapperInterface::recordMap() {
    map->saveMap("../GridMap.txt");
    return true;
}

bool MapperInterface::insertMap() {
    map->insertPointCloud(pointCloud);
    return false;
}
