//
// Created by Xuhai Luo on 2022/7/7.
//

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

void writePCDFileASCII(std::string filename, pcl::PointCloud<pcl::PointXYZI> cloud)
{
    pcl::io::savePCDFileASCII(filename, cloud);
}