#include "Transform.h"
#include <math.h>


void Transform::setTransform(double *ang, double *tr) {
    for (int i = 0; i < 3; ++i) {
        (*angles)(i) = ang[i];
        (*trans)(i) = tr[i];
    }
}

void Transform::setTransform(Eigen::Vector3d ang, Eigen::Vector3d tr) {
    for (int i = 0; i < 3; ++i) {
		(*angles)(i) = ang[i];
		(*trans)(i) = tr[i];
    }
}
void Transform::setTransform(double *tr) {
    for (int i = 0; i < 3; ++i) {
		(*trans)(i) = tr[i];
    }
}

void Transform::setTransform(Eigen::Vector3d tr) {
    for (int i = 0; i < 3; ++i) {
		(*trans)(i) = tr[i];
    }
}

void Transform::getTransform(Eigen::Vector3d &ang, Eigen::Vector3d &tr) {
    ang = *(this->angles);
    tr = *(this->trans);
}

void Transform::setRotation(double *ang) {
    *transMatrix << cos(ang[2]) * cos(ang[1]), (cos(ang[2]) * sin(ang[1]) * sin(ang[0])) - (sin(ang[2]) * cos(ang[0])), (cos(ang[2]) * sin(ang[1])) * cos(ang[0]) + (sin(ang[2]) * sin(ang[0])),
                    sin(ang[2]) * cos(ang[1]), (sin(ang[2]) * sin(ang[1]) * sin(ang[0])) + (cos(ang[2]) * cos(ang[0])), (sin(ang[2]) * sin(ang[1]) * cos(ang[0])) - (cos(ang[2]) * sin(ang[0])),
                    -sin(ang[1]), cos(ang[1]) * sin(ang[0]), cos(ang[1]) * cos(ang[0]);
}

void Transform::setRotation(double _rotationmatrix[3][3])
{
    (*transMatrix)(0,0) = _rotationmatrix[0][0];
	(*transMatrix)(0,1) = _rotationmatrix[0][1];
	(*transMatrix)(0,2) = _rotationmatrix[0][2];
	(*transMatrix)(1,0) = _rotationmatrix[1][0];
	(*transMatrix)(1,1) = _rotationmatrix[1][1];
	(*transMatrix)(1,2) = _rotationmatrix[1][2];
	(*transMatrix)(2,0) = _rotationmatrix[2][0];
	(*transMatrix)(2,1) = _rotationmatrix[2][1];
	(*transMatrix)(2,2) = _rotationmatrix[2][2];
}

void Transform::setRotation(Eigen::Vector3d ang) {
    *(this->angles) = ang;
}

void Transform::setTranslation(double *tr) {

	(*transMatrix)(3,0) = 0;
	(*transMatrix)(3,1) = 0;
	(*transMatrix)(3,2) = 0;
	(*transMatrix)(3,3) = 1;

	(*transMatrix)(0,3) = tr[0];
	(*transMatrix)(1,3) = tr[1];
	(*transMatrix)(2,3) = tr[2];
}

void Transform::setTranslation(Eigen::Vector3d tr) {
	(*transMatrix)(3, 0) = 0;
	(*transMatrix)(3, 1) = 0;
	(*transMatrix)(3, 2) = 0;
	(*transMatrix)(3, 3) = 1;
	(*transMatrix)(0,3) = tr(0);
	(*transMatrix)(1,3) = tr(1);
	(*transMatrix)(2,3) = tr(2);
}

Point Transform::doTransform(Point p) {
    double x,y,z;
    p.getPoint(x,y,z);

    Eigen::Vector4d points; points << x,y,z,1;
    Eigen::Vector4d result; result << 0,0,0,1;

    result = (*transMatrix) * points;


    Point res(result(0), result(1), result(2));
    return res;
}

PointCloud Transform::doTransform(const PointCloud& pc) {
    Point tmp;
    int size;
    std::list<Point> points = pc.getPointCloud();
    auto iter = points.begin();
    std::list<Point> result;
    for (; iter != points.end(); ++iter) {
        tmp = doTransform(*iter);
        result.emplace_back(tmp);
    }
    PointCloud res;
    res.setPointCloud(result);
    return res;
}












