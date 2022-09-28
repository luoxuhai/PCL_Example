#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/statistical_outlier_removal.h>

using namespace std::chrono;

int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZ>);

    pcl::io::loadPCDFile<pcl::PointXYZ>("../../../data/table_scene_lms400.pcd", *cloud);

    // std::cerr << *cloud << std::endl;

    // 创建滤波器，对每个点分析的临近点的个数设置为50 ，并将标准差的倍数设置为1  这意味着如果一
    //个点的距离超出了平均距离一个标准差以上，则该点被标记为离群点，并将它移除，存储起来
    auto start = system_clock::now();

    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor; //创建滤波器对象
    sor.setInputCloud(cloud);                          //设置待滤波的点云
    sor.setMeanK(50);                                  //设置在进行统计时考虑查询点临近点数
    sor.setStddevMulThresh(1.0);                       //设置判断是否为离群点的阀值
    sor.filter(*cloud_filtered);                       //存储

    // std::cerr << "Cloud after filtering: " << std::endl;
    // std::cerr << *cloud_filtered << std::endl;

    // pcl::PCDWriter writer;
    // writer.write<pcl::PointXYZ>("../table_scene_lms400_inliers.pcd", *cloud_filtered, false);
    // // true：滤波结果取反，被过滤的点
    // sor.setNegative(true);
    // sor.filter(*cloud_filtered);
    // writer.write<pcl::PointXYZ>("../table_scene_lms400_outliers.pcd", *cloud_filtered, false);

    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    std::cout << "花费了"
              << double(duration.count()) * microseconds::period::num / microseconds::period::den
              << "秒" << std::endl;
    return 0;
}
