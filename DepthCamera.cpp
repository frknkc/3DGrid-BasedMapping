/**
* @file DepthCamera.cpp
* @Author Furkan Koc
* @date January, 2023
*/
#include "DepthCamera.h"
#include "PointCloud.h"
#include "Point.h"
#include <iostream>
#include <fstream>

using namespace std;

/*!
\fileName adli dosyayi kapsulleme yoluyla _filename degiskenine esitlenir.
\_fileName dosyasi kapsulleme yoluyla esitlenmesi icin konuldu.
*/
void DepthCamera::setFile(string _filename) {
	this->filename = filename;
}

/*!
\return fileName
*/
string DepthCamera::getFile() {
	return filename;
}
//! \return pointCloud
//! filename adli txt dosyasini okuyup pointcloud nesnesine atar.
PointCloud DepthCamera::capture() {

    std::string file_path = filename;
    std::fstream file(file_path, std::ios::in);
    std::string line;
    std::string point;
    std::list<Point> points;
    int state = 0;
    int size = 0;
    double x = 0, y = 0, z = 0;
    int counter;
    int p_counter = 0;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (state == 0) {
                state++;
                continue;
            } else if (state == 1) {
                size = std::stoi(line);
//                points = new Point[size];
                state++;
                continue;
            } else {
                counter = 0;
                point = "";
                for (int i = 0; i < line.size(); i++) {
                    if (line[i] == ' ') {
                        if (counter == 0) x = std::stod(point);
                        if (counter == 1) y = std::stod(point);
                        if (counter == 2) {
                            z = std::stod(point);
                            break;
                        }
                        point = "";
                        counter++;
                    } else {
                        point += line[i];
                    }
                }
//                std::cout<<"size: "<<size<<"x: "<<x<<"y: "<<y<<"z: "<<z<<endl;
                Point p(x,y,z);
                points.emplace_back(p);
//                points[p_counter] = p;
                p_counter++;
            }
        }
	}
	else {
		cout << "file cannot open!";
	}
    PointCloud pointCloud;
    pointCloud.setPointCloud(points);

    return pointCloud;
}

//! \return pointCloud(transform yapilmis hali)
//! filename adli txt dosyasini okuyup pointcloud nesnesine atar ve transform islemini yapar.
PointCloud DepthCamera::captureFor() {
    PointCloud pC = capture();
    return transform.doTransform(pC);
}