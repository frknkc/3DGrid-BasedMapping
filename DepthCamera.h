/**
* @file DepthCamera.h
* @Author Furkan Koc
* @date January, 2023
*/
#pragma once
#include"PointCloud.h"
#include "PointCloudGenerator.h"
#include<string>

using namespace std;

//! \inherit PointCloudGenerator
class DepthCamera : public PointCloudGenerator
{
private: 
	string filename;
public:
    //! DephtCamera sinifi icin constructor
    DepthCamera(string _filename){
        this->filename = _filename;
    }
    DepthCamera(string _filename, Transform const &_transform){
        this->filename = _filename;
		this->transform = _transform;
    }

    //! \param filename adli dosyayi kapsulleme yoluyla _filename degiskene esitler.
	void setFile(string);
    //! \return filename.
	string getFile();
    //! \return pointCloud
    //! filename adli txt dosyasini okuyup pointcloud nesnesine atar.
	PointCloud capture();
    //! \return pointCloud(transform yapilmis hali)
    //! filename adli txt dosyasini okuyup pointcloud nesnesine atar ve transform islemini yapar.
    PointCloud captureFor();
};

