//
// Created by 罗绪海 on 2022/7/7.
//

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#ifndef PCL_EXAMPLE_WRITE_PCD_FILE_H
#define PCL_EXAMPLE_WRITE_PCD_FILE_H

void writePCDFileASCII(std::string filename, pcl::PointCloud<pcl::PointXYZI> cloud);

#endif //PCL_EXAMPLE_WRITE_PCD_FILE_H