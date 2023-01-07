#include "Point.h"
#include "PointCloud.h"
#include "eigen/Eigen/Eigen"

#ifndef OOPPROJECT_TRANSFORM_H
#define OOPPROJECT_TRANSFORM_H


class Transform {
    Eigen::Vector3d *angles;
    Eigen::Vector3d *trans;
    Eigen::Matrix4d *transMatrix;
public:
    Transform(){
		angles = new Eigen::Vector3d;
		trans = new Eigen::Vector3d;
		transMatrix = new Eigen::Matrix4d;
    }
    void setTransform(double ang[], double tr[]);
    void setTransform(double tr[]);
    void setTransform(Eigen::Vector3d tr);
    void setTransform(Eigen::Vector3d ang, Eigen::Vector3d tr);
    void getTransform(Eigen::Vector3d &ang, Eigen::Vector3d &tr);
    void setRotation(double ang[3]);
    void setRotation(Eigen::Vector3d ang);
    void setRotation(double trans[3][3]);
    void setTranslation(double tr[]);
    void setTranslation(Eigen::Vector3d tr);
    Point doTransform(Point p);
    PointCloud doTransform(const PointCloud& pc);
};


#endif //OOPPROJECT_TRANSFORM_H
